#include "hyukjin_header.h"

Node* serarch_tag(int tag)
{
	Node* ptr = list_info.head;

	while (ptr != NULL)
	{
		if (ptr->data.tag == tag)
		{
			return ptr;
		}
		else
			ptr = ptr->next;
	}
	return NULL;
}