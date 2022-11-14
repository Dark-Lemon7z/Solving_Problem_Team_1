#include "minseok_header.h"
void init()
{
	list_info.size = 0;
	list_info.head = NULL;
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
	Node *temp, *cur;
	FILE * input = fopen("registraion_data.txt", "r");
	if(input == NULL)
		printf("readfail");
	while(EOF != fscanf(input, "%d/%d-%d-%d/%[^/]/%[^/]/%d/%[^/]/%s", &tag, &year, &month, &date, fee_paid, name, &age, org, job))
	{
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

		//insert part
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
bool main_menu()
{
	int sel;
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
			return 1;
		case 2:
			//상균 파트
			return 1;
		case 3:
			//민준 파트
			return 1;
		case 4:
			//혁진 파트
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