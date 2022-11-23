#include "LIM_header.h"

void delete(int key) {

	Node* ptr = list_info.head, * prev = list_info.head;

	if (list_info.head->data.tag == key)
	{
		list_info.head = list_info.head->next;
		free(ptr);
		return;
	}
	else
	{
		ptr = ptr->next;
		while (ptr != NULL)
		{
			if (ptr->data.tag == key)
			{
				prev->next = ptr->next;
				free(ptr);
				return;
			}
			ptr = ptr->next;
			prev = prev->next;
		}
	}
	printf("==No data exist==");

}

void delete_name(char *key) {
	Node* ptr = list_info.head, * prev = list_info.head, *temp;
	if (strcmp(list_info.head->data.name,key) == 0)
	{
		temp = list_info.head;
		list_info.head = list_info.head->next;
		free(temp);
	}
	else
	{
		ptr = ptr->next;
		while (ptr != NULL)
		{
			if (strcmp(ptr->data.name,key) == 0)
			{
				prev->next = ptr->next;
				temp = ptr;
				free(temp);
			}
			ptr = ptr->next;
			prev = prev->next;
		}
	}
}

void delete_org(char* key) {
	Node* ptr = list_info.head, * prev = list_info.head, *temp;
	temp = ptr;
	while (ptr != NULL)
	{
		if (strcmp(list_info.head->data.org, key) == 0)
		{
			list_info.head = list_info.head->next;
			free(temp);
		}
		else
		{
			ptr = ptr->next;
			while (ptr != NULL)
			{
				if (strcmp(ptr->data.org, key) == 0)
				{
					prev->next = ptr->next;
					free(temp);
				}
				ptr = ptr->next;
				prev = prev->next;
			}
		}
	}
}