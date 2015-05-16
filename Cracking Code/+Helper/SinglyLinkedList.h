#ifndef SinglyLinkedList_h
#define SinglyLinkedList_h
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void list_destroy(ListNode *head){
	if(!head) return;
	ListNode *next;
	while(head){
		next = head->next;
		delete head;
		head = next;
	}
}

void listnode_append(ListNode *head, int val){
	if(!head) return;
	while(head->next){
		head = head->next;
	}
	head->next = new ListNode(val);
}

void print_list(ListNode *head){
	while(head){
		printf("[%d] ", head->val);
		head = head->next;
	}
	printf("\n");
}
#endif