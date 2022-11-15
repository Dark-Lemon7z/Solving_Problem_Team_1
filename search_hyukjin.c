#include <stdio.h>

void serarch_tag(struct data* head, int tag)
{
	struct data* ptr;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->tag == tag)
		{
			return &head;
			break;
		}
		else
			ptr = ptr->next;
	}
}