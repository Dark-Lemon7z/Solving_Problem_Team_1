#include "hyukjin_header.h"
/*
 * Name        : search_tag
 * Date        : 2022-11-14
 * author      : HyukJin Jang
 * argument    : int
 * return      : Node_arr *
 * description : This function can find the tag from txt file.
*/
Node_arr * search_tag(int tag)
{
	Node* ptr = list_info.head;
	Node_arr *rst = NULL;
	while (ptr != NULL)
	{
		if (ptr->data.tag == tag)
		{
			rst = malloc(sizeof(Node_arr));
			rst->next = NULL;
			rst->node_addr = ptr;
			break;
		}
		else
			ptr = ptr->next;
	}
	return rst;
}
/*
 * Name        : search_name
 * Date        : 2022-11-24
 * author      : HyukJin Jang
 * argument    : char *
 * return      : Node_arr *
 * description : This function can find node by name.
*/
Node_arr * search_name(char *name)
{
	Node* ptr = list_info.head;
	Node_arr * rst = NULL, *cur;
	while (ptr != NULL)
	{
		if (strcmp(ptr->data.name, name) == 0)
		{
//			print_node(ptr);
			if(rst == NULL)
			{
				rst = malloc(sizeof(Node_arr));
				rst->next = NULL;
				cur = rst;
				rst->node_addr = ptr;
			}
			else
			{
				cur->next = malloc(sizeof(Node_arr));
				cur = cur->next;
				cur->node_addr = ptr;
				cur->next = NULL;
			}
		}
		ptr = ptr->next;
	}
	return rst;
}
/*
 * Name        : search_org
 * Date        : 2022-11-24
 * author      : HyukJin Jang
 * argument    : char *
 * return      : Node_arr *
 * description : This function can find node by organization.
*/
Node_arr * search_org(char * org)
{
	Node* ptr = list_info.head;
	Node_arr * rst = NULL, *cur;
	while (ptr != NULL)
	{
		if (strcmp(ptr->data.org, org) == 0)
		{
			if(rst == NULL)
			{
				rst = malloc(sizeof(Node_arr));
				rst->next = NULL;
				cur = rst;
				rst->node_addr = ptr;
			}
			else
			{
				cur->next = malloc(sizeof(Node_arr));
				cur = cur->next;
				cur->node_addr = ptr;
				cur->next = NULL;
			}
		}
		ptr = ptr->next;
	}
	return rst;
}