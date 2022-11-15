#include "gyeongwon_header.h"

void print_node(Node* cur)
{
	if (cur == NULL)
	{
		printf("tag|   date   |  fee |         name        |age|         organization          |  job\n-----------------------------------------------------------------------------------------------------\n");
		while (EOF != NULL)
		{
			printf("%2d |%d-%d-%2d |%5s |%20s |%d | %30s| %s\n", list_info.head->data.tag, list_info.head->data.year, list_info.head->data.month,
				list_info.head->data.date, list_info.head->data.fee_paid ? "true" : "false",
				list_info.head->data.name, list_info.head->data.age, list_info.head->data.org, list_info.head->data.job);
			list_info.head = list_info.head->next;
		}
	}
	else
	{
		printf("tag|   date   |  fee |         name        |age|         organization          |  job\n-----------------------------------------------------------------------------------------------------\n");
		printf("%2d |%d-%d-%2d |%5s |%20s |%d | %30s| %s\n", cur->data.tag, cur->data.year, cur->data.month,
			cur->data.date, cur->data.fee_paid ? "true" : "false",
			cur->data.name, cur->data.age, cur->data.org, cur->data.job);
	}
	free(cur);
}
