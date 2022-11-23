#include "gyeongwon_header.h"

void print_node(Node* cur)
{
	int count = 0;
	Node* temp = list_info.head;
	if (cur == NULL)
	{
		printf("tag|   date   |  fee |         name        |age|         organization          |  job\n-----------------------------------------------------------------------------------------------------\n");
		while (temp != NULL)
		{
			printf("%2d |%d-%d-%2d |%5s |%20s |%d | %30s| %s\n", temp->data.tag, temp->data.year, temp->data.month,
				temp->data.date, temp->data.fee_paid ? "true" : "false",
				temp->data.name, temp->data.age, temp->data.org, temp->data.job);
			temp = temp->next;
			count++;
			if ((count + 1) % 5 == 0)
			{
				printf("\n-----------------------------------------------------------------------------------------------------\n");
			}
		}
	}
	else
	{
		printf("tag|   date   |  fee |         name        |age|         organization          |  job\n-----------------------------------------------------------------------------------------------------\n");
		printf("%2d |%d-%d-%2d |%5s |%20s |%d | %30s| %s\n", cur->data.tag, cur->data.year, cur->data.month,
			cur->data.date, cur->data.fee_paid ? "true" : "false",
			cur->data.name, cur->data.age, cur->data.org, cur->data.job);
	}
}
