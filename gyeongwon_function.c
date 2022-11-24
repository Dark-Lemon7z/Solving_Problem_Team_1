#include "gyeongwon_header.h"
/*
 * Name        : print_node
 * Date        : 2022-11-24
 * author      : GyeongWon Lee
 * argument    : Node*
 * return      : void
 * description : This function prints node
*/
void print_node(Node* cur)
{
	int count = 0;
	Node* temp = list_info.head;
	if (cur == NULL)
	{
		while (temp != NULL)
		{
			printf("tag \t: %d\ndate\t: %d-%d-%d\nfee \t: %s\nname\t: %s\nage \t: %d\norg \t: %s\njob \t: %s\n--------------------------\n", temp->data.tag, temp->data.year, temp->data.month,
				temp->data.date, temp->data.fee_paid ? "true" : "false",
				temp->data.name, temp->data.age, temp->data.org, temp->data.job);
			temp = temp->next;
			count++;
			if (count % 5 == 0)
			{
				printf("========== %d of %d ==========\n", count, list_info.size);
				clear_(1);
			}
		}
		printf("Total : %d\n", list_info.size);
	}
	else
	{
		puts("--------------------------");
		printf("tag \t: %d\ndate\t: %d-%d-%d\nfee \t: %s\nname\t: %s\nage \t: %d\norg \t: %s\njob \t: %s\n", cur->data.tag, cur->data.year, cur->data.month,
			   cur->data.date, cur->data.fee_paid ? "true" : "false",
			   cur->data.name, cur->data.age, cur->data.org, cur->data.job);
	}
}
