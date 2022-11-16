#include "minjun_header.h"
#include "main.h"

/*
 * Name        : AddNode
 * Date        : 2022-09-06
 * argument    : int array
 * return      : void
 * description : This function can print Matrix's values.
*/
void AddNode() {
	int sel;
	char fee;
	Node *temp = malloc(sizeof(Node));
	temp->next = NULL;
	printf("tag : ");
	scanf("%d", &temp->data.tag);
	//tag verify
	printf("year : ");
	scanf("%d", &temp->data.year);
	printf("month : ");
	scanf("%d", &temp->data.month);
	printf("date : ");
	scanf("%d", &temp->data.date);

	printf("fee_paid(y/n) : ");
	scanf(" %c", &fee);
	temp->data.fee_paid = fee == 'y' ? true : false;

	printf("name : ");
	get_string(temp->data.name);
	printf("age : ");
	scanf(" %d", &temp->data.age);
	printf("org : ");
	get_string(temp->data.org);
	printf("job : ");
	get_string(temp->data.job);

	printf("Enter 1 to add to the front, Enter any key to add at the end");
	scanf("%d", &sel);

	if (sel)
	{
		temp->next = list_info.head;
		list_info.head = temp;
	}
	else
	{
		Node *cur = list_info.head;

		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = temp;
	}
}

bool verify_same(int tag);