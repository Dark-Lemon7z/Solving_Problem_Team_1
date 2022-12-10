#include "minseok_header.h"
/*
 * Name        : init
 * Date        : 2022-11-07
 * author      : MinSeok Choi
 * argument    : none
 * return      : void
 * description : initializing program
*/
void init()
{
	list_info.size = 0;
	list_info.head = NULL;
	clear_(0);
}
/*
 * Name        : read_from_file
 * Date        : 2022-11-10
 * author      : MinSeok Choi
 * argument    : none
 * return      : void
 * description : This function can read data from txt file
*/
void read_from_file()
{
	int tag;
	int year, month, date;
	char fee_paid[4]; //yes -> 1, no -> 0
	char name[25];
	int age;
	char org[50];
	char job[15];
	Node *temp, *cur, *prev;
	FILE * input = fopen("registraion_data.txt", "r");
	if(input == NULL)
		printf("readfail");
	while(EOF != fscanf(input, "%d/%d-%d-%d/%[^/]/%[^/]/%d/%[^/]/%s", &tag, &year, &month, &date, fee_paid, name, &age, org, job))
	{
		list_info.size++;
		prev = list_info.head;
		temp = (Node *) malloc(sizeof(Node));
		temp->next = NULL;
		temp->data.tag = tag;
		temp->data.year = year;
		temp->data.month = month;
		temp->data.date = date;
		temp->data.fee_paid = (strcmp(fee_paid, "yes") ? false : true);
		temp->checked = false;
		strcpy(temp->data.name, name);
		temp->data.age = age;
		strcpy(temp->data.org, org);
		strcpy(temp->data.job, job);
		//insert part ** tag sorted
		if(list_info.head == NULL)
		{
			list_info.head = temp;
			continue;
		}
		else
		{
			for(cur = list_info.head; cur != NULL; cur = cur->next)
			{
				if(cur->data.tag > tag)
				{
					if(cur == list_info.head)
					{
						list_info.head = temp;
						temp->next = cur;
					}
					else
					{
						prev->next = temp;
						temp->next = cur;
					}
					break;
				}
				if(cur != list_info.head)
					prev = prev->next;
			}
		}
		if(cur == NULL)
		{
			prev->next = temp;
			temp->next = NULL;
		}
	}
	fclose(input);
}
/*
 * Name        : delete_node_arr_list
 * Date        : 2022-11-24
 * author      : MinSeok Choi
 * argument    : Node_arr *
 * return      : void
 * description : delete linked-list
*/
void delete_node_arr_list(Node_arr * head)
{
	if(head == NULL)
		return;
	Node_arr *prev = NULL, *cur;
	for(cur = head; cur != NULL; cur = cur->next)
	{
		if(prev != NULL)
			free(prev);
		prev = cur;
	}
	free(prev);
}
/*
 * Name        : delete_menu
 * Date        : 2022-11-24
 * author      : MinSeok Choi
 * argument    : none
 * return      : void
 * description : print delete menu
*/
void delete_menu()
{
	clear_(0);
	bool flag;
	int sel, tag_input;
	char ch_input[60];
	puts("=======Select_Delete Option=======");
	puts("1. Tag");
	puts("2. Name");
	puts("3. Organization");
	printf("input >> ");
	scanf("%d", &sel);
	switch(sel)
	{
		case 1:
			printf("Tag to delete >> ");
			scanf("%d", &tag_input);
			flag = delete(tag_input);
			break;
		case 2:
			printf("Name to delete >> ");
			get_string(ch_input);
			flag = delete_name(ch_input);
			break;
		case 3:
			printf("Organization to delete >> ");
			get_string(ch_input);
			flag = delete_org(ch_input);
			break;
		default:
			printf("Input Error\n");
			return;
	}
	if(!flag)
	{
		printf("No data exist.\n");
	}
	else
	{
		printf("Deleted.\n");
	}
}
/*
 * Name        : output_menu
 * Date        : 2022-11-24
 * author      : MinSeok Choi
 * argument    : none
 * return      : void
 * description : print output menu
*/
void output_menu()
{
	clear_(0);
	Node_arr *rst = NULL, *cur;
	Node ** ByAge;
	int sel, tag_input;
	char ch_input[60];
	while(1)
	{
		puts("=======Select_Output Option=======");
		puts("1. Tag");
		puts("2. Name (print all of same name)");
		puts("3. Organization (print all of same org.)");
		puts("4. Make output");
		puts("5. Just Print all of data by age");
		puts("**If nodes are duplicated, print only one time**");
		printf("input >> ");
		scanf("%d", &sel);
		switch(sel)
		{
			case 1:
				printf("Tag to save >> ");
				scanf("%d", &tag_input);
				rst = search_tag(tag_input);
				break;
			case 2:
				printf("Name to save >> ");
				get_string(ch_input);
				rst = search_name(ch_input);
				break;
			case 3:
				printf("Organization to save >> ");
				get_string(ch_input);
				rst = search_org(ch_input);
				break;
			case 4:
				write_to_file(NULL);
				puts("Fine.");
				return;
			case 5:
				write_to_file(ByAge = sortByAge());
				free(ByAge);
				return;
			default:
				printf("Input Error\n");
				break;
		}
		for(cur = rst; cur != NULL; cur = cur->next)
		{
			cur->node_addr->checked = true;
		}
		if(rst == NULL)
			puts("No Data");
		else
			delete_node_arr_list(rst);
		clear_(1);
	}

}
/*
 * Name        : write_to_file
 * Date        : 2022-12-10
 * author      : MinSeok Choi
 * argument    : Node **
 * return      : void
 * description : make output file
*/
void write_to_file(Node ** sorteddata)
{
	int idx = 0;
	char filename[54];
	FILE *output;
	Node *cur;
	printf("File name(up to 50) : ");
	get_string(filename);
	strcat(filename, ".txt");
	output = fopen(filename, "w");
	if(sorteddata == NULL)
	{
		for (cur = list_info.head; cur != NULL; cur = cur->next) // designed by gyeongwon
		{
			if (!cur->checked)
				continue;
			fprintf(output, "------------- #%d -------------\n", idx++);
			fprintf(output,
					"tag \t: %d\ndate\t: %d-%d-%d\nfee \t: %s\nname\t: %s\nage \t: %d\norg \t: %s\njob \t: %s\n",
					cur->data.tag,
					cur->data.year, cur->data.month,
					cur->data.date, cur->data.fee_paid ? "true" : "false",
					cur->data.name, cur->data.age, cur->data.org, cur->data.job);
			cur->checked = false;
		}
	}
	else
	{
		for (idx = 0; idx < list_info.size; idx++)
		{
			fprintf(output, "------------- #%d -------------\n", idx);
			fprintf(output,
					"tag \t: %d\ndate\t: %d-%d-%d\nfee \t: %s\nname\t: %s\nage \t: %d\norg \t: %s\njob \t: %s\n",
					sorteddata[idx]->data.tag,
					sorteddata[idx]->data.year, sorteddata[idx]->data.month,
					sorteddata[idx]->data.date, sorteddata[idx]->data.fee_paid ? "true" : "false",
					sorteddata[idx]->data.name, sorteddata[idx]->data.age, sorteddata[idx]->data.org, sorteddata[idx]->data.job);
		}
	}
	fclose(output);
}
/*
 * Name        : search_menu
 * Date        : 2022-11-24
 * author      : MinSeok Choi
 * argument    : none
 * return      : void
 * description : print menu for search
*/
void search_menu()
{
	clear_(0);
	Node_arr * rst, *cur;
	bool flag = false;
	int sel, tag_input;
	char ch_input[60];
	puts("=======Select_Search Option=======");
	puts("1. Tag");
	puts("2. Name");
	puts("3. Organization");
	printf("input >> ");
	scanf("%d", &sel);
	switch(sel)
	{
		case 1:
			printf("Tag to find >> ");
			scanf("%d", &tag_input);
			rst = search_tag(tag_input);
			break;
		case 2:
			printf("Name to find >> ");
			get_string(ch_input);
			rst = search_name(ch_input);
			break;
		case 3:
			printf("Organization to find >> ");
			get_string(ch_input);
			rst = search_org(ch_input);
			break;
		default:
			printf("Input Error\n");
			return;
	}
	for(cur = rst; cur != NULL; cur = cur->next)
	{
		flag = true;
		print_node(cur->node_addr);
	}
	if(!flag)
	{
		printf("Not Found!\n");
	}
	else
		delete_node_arr_list(rst);
}

/*
 * Name        : main_menu
 * Date        : 2022-11-24
 * author      : MinSeok Choi
 * argument    : none.
 * return      : bool
 * description : This function prints main menu.
*/
bool main_menu()
{
	int sel, input;
	char str[30];
	Node *temp;
	puts("=======Registration_Management=======");
	puts("1. Print data");
	puts("2. Delete data");
	puts("3. Insert data");
	puts("4. Search data");
	puts("5. Make output file (txt)");
	puts("6. Exit");
	printf("input >> ");
	scanf("%d", &sel);
	switch(sel)
	{
		case 1:
			//경원 파트
			print_node(NULL);
			return 1;
		case 2:
			//상균 파트
			delete_menu();
			return 1;
		case 3:
			AddNode();
			//민준 파트
			return 1;
		case 4:
			//혁진 파트
			search_menu();
			return 1;
		case 5:
			output_menu();
			return 1;
		case 6:
			return 0;
		default:
			printf("Enter valid data.\n");
			return 1;
	}
}
/*
 * Name        : clear_
 * Date        : 2022-10-09
 * author      : MinSeok Choi
 * argument    : bool
 * return      : void
 * description : clear terminal's outputs
*/
void clear_(bool flag)
{
#ifdef _WIN32
	if(flag)
		system("pause");
	system("cls");
	return;
#endif

#ifdef _WIN64
	if(flag)
		system("pause");
	system("cls");
#endif

#ifdef __APPLE__
	if(flag)
	{
		puts("Press any enter to continue...");
		system("read");
	}
	system("clear");
#endif
}
/*
 * Name        : get_string
 * Date        : 2022-10-09
 * author      : MinSeok Choi
 * argument    : chat *str
 * return      : void
 * description : get string from user's input
*/
void get_string(char *str)
{
	int idx = 0;
	char temp;
	if((temp = getchar()) != '\n') // for \n dummy
	{
		str[idx++] = temp;
	}
	while((temp = getchar()) !='\n')
	{
		str[idx++] = temp;
		if(idx == 19)
		{
			break;
		}
	}
	str[idx] = '\0';
}
/*
 * Name        : sortByAge
 * Date        : 2022-12-10
 * author      : MinSeok Choi
 * argument    : none
 * return      : Node **
 * description : sort by age and return array
*/
Node **sortByAge()
{
	int idx = 0;
	Node **sortbyage = malloc(sizeof(Node*) * list_info.size), **rst = malloc(sizeof(Node*) * list_info.size);
	//Put nodes addr in array
	for(Node* cur = list_info.head; cur != NULL; cur = cur->next, idx++)
	{
		sortbyage[idx] = cur;
	}
	selection_sort(sortbyage);
	return sortbyage;
}
/*
 * Name        : seletion_sort
 * Date        : 2022-12-10
 * author      : MinSeok Choi
 * argument    : Node **
 * return      : void
 * description : Selection sort
*/
void selection_sort(Node** tar_arr)
{
	Node * temp;
	int cur, size = list_info.size, min, idx;
	for(cur = 0; cur < size; cur++)
	{
		min = tar_arr[cur]->data.age;
		idx = cur;
		for(int i = cur + 1; i < size; i++)
		{
			if(tar_arr[i]->data.age < min)
			{
				min = tar_arr[i]->data.age;
				idx = i;
			}
		}
		if(idx == cur)
			continue;
		temp = tar_arr[idx];
		tar_arr[idx] = tar_arr[cur];
		tar_arr[cur] = temp;
	}
}
/*
 * Name        : clear_node
 * Date        : 2022-12-10
 * author      : MinSeok Choi
 * argument    : chat *str
 * return      : void
 * description : get string from user's input
*/
void clear_node()
{
	Node * prev = list_info.head;
	for(Node * cur = prev->next; cur != NULL; cur = cur->next)
	{
		free(prev);
		prev = cur;
	}
	free(prev);
}