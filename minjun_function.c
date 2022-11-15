#include "minjun_header.h"

struct NODE* createNode(int tag)
{
	struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
	newNode->tag = tag;
	newNode->next = NULL;
	return newNode;
}
void addNode(Node** head)
{
	Node* newNode = createNode();
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		Node* temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
}