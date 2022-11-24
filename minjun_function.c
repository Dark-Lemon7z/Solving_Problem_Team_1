#include "minjun_header.h"
#include "main.h"
/*
 * Name        : AddNode
 * Date        : 2022-11-24
 * author      : MinJun Choi
 * argument    : none
 * return      : void
 * description : this function can insert node ascent by tag.
*/
void AddNode() {
	char fee;
	Node* temp = malloc(sizeof(Node)), *cur, *prev = list_info.head;
	temp->next = NULL;
	printf("tag : ");
	scanf("%d", &temp->data.tag);
	//Tag verify first.
	for(cur = list_info.head; cur != NULL; cur = cur->next)
	{
		if(cur->data.tag > temp->data.tag)
		{
			break;
		}
		else if(cur->data.tag == temp->data.tag)
		{
			printf("Tag should be unique.\n");
			return;
		}
		if(cur != list_info.head)
			prev = prev->next;
	}
	list_info.size++;
	printf("year : ");
	scanf("%d", &temp->data.year);
	printf("month : ");
	scanf("%d", &temp->data.month);
	printf("date : ");
	scanf("%d", &temp->data.date);

	printf("fee_paid (y/n) : ");
	scanf(" %c", &fee);
	temp->data.fee_paid = fee == 'y' ? true : false;

	printf("name : ");
	get_string(temp->data.name);
	printf("age : ");
	scanf(" %d", &temp->data.age);
	printf("org : ");
	get_string(temp->data.org);
	printf("job : ");
	get_string(temp->data.job);

	if(prev == list_info.head)
	{
		temp->next = list_info.head;
		list_info.head = temp;
	}
	else
	{
		prev->next = temp;
		temp->next = cur;
	}
}
/*merged with AddNode.*/
/*void insertNode(int tag) {

	Node* ptr, * old_ptr = NULL;
	int newtag = tag, fail = -1;
	Node* new_node = malloc(sizeof(Node));
	new_node->data.tag = newtag;
	new_node->next = NULL;

	ptr = list_info.head;
	while (ptr)
	{
		if (ptr->data.tag == newtag)//중복될 경우
		{
			printf("%d already exists \n", newtag);
			break;
		}
		if (ptr->data.tag < newtag)  //pass
		{
			old_ptr = ptr;
			ptr = ptr->next;
		}
		else
		{
			if (ptr == list_info.head) {  //첫번째 노드일경우
				new_node->next = list_info.head;
				list_info.head = new_node;
				break;
			}
			old_ptr->next = new_node;//중간
			new_node->next = ptr;
			break;
		}
		if (ptr == NULL) {//끝
			old_ptr->next = new_node;
			break;
		}
	}
}*/
