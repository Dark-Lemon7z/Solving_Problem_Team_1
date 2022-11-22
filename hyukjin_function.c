#include "hyukjin_header.h"

/*
 * Name        : search_tag
 * Date        : 2022-11-14
 * argument    : int tag
 * return      : node *
 * description : This function can find the tag from txt file.
*/

Node* search_tag(int tag)
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

Node* search_name(char name)
{
	Node* ptr = list_info.head;

	while (ptr != NULL)
	{
		if (ptr->data.name == name)
		{
			return ptr;
		}
		else
			ptr = ptr->next;
	}
	return NULL;
}

Node* search_org(char org)
{
	Node* ptr = list_info.head;

	while (ptr != NULL)
	{
		if (ptr->data.org == org)
		{
			return ptr;
		}
		else
			ptr = ptr->next;
	}
	return NULL;
}