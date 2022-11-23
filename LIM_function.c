#include "LIM_header.h"

void delete(int key) {
	Node* ptr = list_info.head;

	//첫 노드 지울 때
	if (list_info.head->tag == key) {
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
		}
	}
}