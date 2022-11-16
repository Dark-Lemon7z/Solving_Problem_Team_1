#include "minjun_header.h"
#include "main.h"

void AddNode() {
	int a;
	Node *temp = malloc(sizeof(Node));

	printf("tag : ");
	scanf("%d", &temp->data.tag);
	printf("year : ");
	scanf("%d", &temp->data.year);
	printf("month : ");
	scanf("%d", &temp->data.month);
	printf("date : ");
	scanf("%d", &temp->data.date);
	printf("fee_paid : ");
	scanf("%s", temp->data.fee_paid);
	printf("name : ");
	scanf("%s", temp->data.name);
	printf("age : ");
	scanf("%d", &temp->data.age);
	printf("org : ");
	scanf("%s", temp->data.org);
	printf("job : ");
	scanf("%s", temp->data.job);

	printf("Enter 1 to add to the front, Enter 0 to add at the end");
	scanf("%d", &a);

	if (a == 1) {
		temp->next = list_info.head;
		list_info.head = temp;
	}
	else {
		Node* cur;

		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = temp;
	}
}