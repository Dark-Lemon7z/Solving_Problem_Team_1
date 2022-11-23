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

void delete_name(char key) {
	Node* ptr = list_info.head, * prev = list_info.head;
	while (ptr != NULL)
	{
		if (list_info.head->data.name == key)
		{
			list_info.head = list_info.head->next;
			free(ptr);
		}
		else
		{
			ptr = ptr->next;
			while (ptr != NULL)
			{
				if (ptr->data.name == key)
				{
					prev->next = ptr->next;
					free(ptr);
				}
				ptr = ptr->next;
				prev = prev->next;
			}
		}
	}
	printf("==No data exist==");


}