#include "LIM_header.h"
/*
 * Name        : delete
 * Date        : 2022-11-24
 * author      : SangGyune Lim
 * argument    : int
 * return      : bool
 * description : This function can delete node
*/
bool delete(int key) {

	Node* ptr = list_info.head, * prev = list_info.head;

	if (list_info.head->data.tag == key)
	{
		list_info.head = list_info.head->next;
		free(ptr);
		list_info.size--;
		return true;
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
				list_info.size--;
				return true;
			}
			ptr = ptr->next;
			prev = prev->next;
		}
	}
	return false;
}
/*
 * Name        : delete_name
 * Date        : 2022-11-24
 * author      : SangGyune Lim
 * argument    : char *
 * return      : bool
 * description : This function can delete node by name
*/
bool delete_name(char *key)
{
	bool flag = 0;
	Node* ptr = list_info.head, * prev = list_info.head, *temp;
	while (ptr != NULL)
	{
		if (strcmp(ptr->data.name,key) == 0)
		{
			if(ptr == list_info.head)
			{
				temp = list_info.head;
				ptr = list_info.head->next;
				list_info.head = list_info.head->next;
				free(temp);
				flag = true;
				list_info.size--;
			}
			else
			{
				prev->next = ptr->next;
				temp = ptr;
				ptr = ptr->next;
				free(temp);
				flag = true;
				list_info.size--;
			}
		}
		if(ptr != list_info.head)
			prev = prev->next;
		ptr = ptr->next;
	}

	return flag;
}
/*
 * Name        : delete_org
 * Date        : 2022-11-24
 * author      : SangGyune Lim
 * argument    : char*
 * return      : bool
 * description : This function can delete node by organization
*/
bool delete_org(char* key)
{
	bool flag = 0;
	Node* ptr = list_info.head, * prev = list_info.head, *temp;
	while (ptr != NULL)
	{
		if (strcmp(ptr->data.org,key) == 0)
		{
			if(ptr == list_info.head)
			{
				temp = list_info.head;
				ptr = list_info.head->next;
				list_info.head = list_info.head->next;
				free(temp);
				flag = true;
				list_info.size--;
			}
			else
			{
				prev->next = ptr->next;
				temp = ptr;
				ptr = ptr->next;
				free(temp);
				flag = true;
				list_info.size--;
			}
		}
		if(ptr != list_info.head)
			prev = prev->next;
		ptr = ptr->next;
	}

	return flag;
}