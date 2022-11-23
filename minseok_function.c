#include "minseok_header.h"
void init()
{
	list_info.size = 0;
	list_info.head = NULL;
	clear_(0);
}
/*
 * Name        : read_from_file
 * Date        : 2022-11-10
 * argument    : none.
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
		prev = list_info.head;
		temp = (Node *) malloc(sizeof(Node));
		temp->next = NULL;
		temp->data.tag = tag;
		temp->data.year = year;
		temp->data.month = month;
		temp->data.date = date;
		temp->data.fee_paid = (strcmp(fee_paid, "yes") ? false : true);
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
		//insert part ** No sort
		/*
		if(list_info.head == NULL)
		{
			list_info.head = temp;
			cur = temp;
		}
		else
		{
			cur->next = temp;
			cur = temp;
		}
		 */
	}
	fclose(input);
	//input test//
//	for(cur = list_info.head; cur != NULL; cur = cur->next)
//	{
//		printf("%d %s %s\n", cur->data.tag, cur->data.org, cur->data.name);
//	}
}
/*
 * Name        : main_menu
 * Date        : 2022-11-14
 * argument    : none.
 * return      : bool
 * description : This function prints main menu.
*/

void search_menu()
{
	Node *output;
	clear_(0);
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
			print_node(search_tag(tag_input));
			return ;
		case 2:
			printf("Name to find >> ");
			get_string(ch_input);
			search_name(ch_input);
			break;
		case 3:
			printf("Organization to find >> ");
			get_string(ch_input);
			search_org(ch_input);
			break;
		default:
			printf("input error");
			output = NULL;
			break;
	}
}

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
	puts("5. Exit");
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
			printf("input tag number >> ");
			get_string(str);
			delete_name(str);
//			scanf("%d", &input);
//			delete(input);
			return 1;
		case 3:
			AddNode();
			//민준 파트
			return 1;
		case 4:
			//혁진 파트
			search_menu();
//			if((temp = search_menu()) != NULL)
//				print_node(temp);
//			else
//				printf("Not Found!!\n");
			return 1;
		case 5:
			return 0;
		default:
			printf("Enter valid data.\n");
			return 1;
	}

}

/*
 * Name        : clear_
 * Date        : 2022-10-09
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