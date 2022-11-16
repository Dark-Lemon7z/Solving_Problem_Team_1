#include "hyukjin_header.h"

/*
 * Name        : search_tag
 * Date        : 2022-11-14
 * argument    : int tag
 * return      : node *
 * description : This function can find the tag from txt file.
*/

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