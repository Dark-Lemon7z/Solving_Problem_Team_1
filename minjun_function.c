#include "minjun_header.h"
#include "main.h"

void AddNode() {
	int a;

	Node *temp = malloc(sizeof(Node));
	scanf("%d/%d-%d-%d/%s/%s/%d/%s/%s\n", &temp->data.tag, &temp->data.year, &temp->data.month, 
		&temp->data.date, temp->data.fee_paid, temp->data.name, &temp->data.age, temp->data.org, temp->data.job);
	printf("�� �տ� �߰��� 1, �� �ڶ�� 0�� �Է��ϼ���.");
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