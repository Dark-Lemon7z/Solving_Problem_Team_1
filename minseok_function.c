#include "minseok_header.h"
void init()
{
	list_info.size = 0;
	list_info.head = NULL;
}

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