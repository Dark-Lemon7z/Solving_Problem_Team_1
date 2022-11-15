void delete(int key) {
	Node* ptr = list_info.head;

//첫 노드를 지우려는 경우
	else if (list_info.head->tag == key) { 
		list_info.head = list_info.head->next;
		return;
	}
	else { 
		while (ptr->next != NULL)
		{
			if (ptr->next->tag == key) { 
				ptr->next = ptr->next->next;
				return;
			}
			ptr = ptr->next;
		}
	}
}