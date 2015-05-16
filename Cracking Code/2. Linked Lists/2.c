#include <stdio.h>
#include <malloc.h>

typedef struct ListNode{
	int data;
	struct ListNode *next;
} ListNode;

ListNode* listnode_create(int data){
	ListNode *p = malloc(sizeof *p);
	p->data = data;
	p->next = NULL;
	return p;
}

void list_destroy(ListNode *head){
	ListNode *next;
	if(!head) return;
	while(head){
		next = head->next;
		free(head);
		head = next;
	}
}

void listnode_append(ListNode *head, int data){
	if(!head) return;
	while(head->next){
		head = head->next;
	}
	head->next = listnode_create(data);
}

void print_list(ListNode *head){
	while(head){
		printf("[%d] ", head->data);
		head = head->next;
	}
	printf("\n");
}

ListNode* findNthFromEnd(ListNode *head, int n){
	if(!head || n <= 0) return NULL;
	ListNode *last;
	last = head;
	while(last && n--) last = last->next;
	if(n > 0) return NULL;
	while(last){
		head = head->next;
		last = last->next;
	}
	return head;
}

#include <assert.h>
int main(){
	ListNode *head;
	head = listnode_create(1);
	listnode_append(head, 2);
	listnode_append(head, 3);
	listnode_append(head, 4);
	listnode_append(head, 5);
	listnode_append(head, 6);
	listnode_append(head, 7);
	print_list(head);
	assert(!findNthFromEnd(head, -1));
	assert(!findNthFromEnd(head, 0));
	assert(!findNthFromEnd(head, 8));
	assert(!findNthFromEnd(head, 9));
	printf("[%d] ", findNthFromEnd(head, 1)->data);
	printf("[%d] ", findNthFromEnd(head, 2)->data);
	printf("[%d] ", findNthFromEnd(head, 3)->data);
	printf("[%d] ", findNthFromEnd(head, 4)->data);
	printf("[%d] ", findNthFromEnd(head, 5)->data);
	printf("[%d] ", findNthFromEnd(head, 6)->data);
	printf("[%d] ", findNthFromEnd(head, 7)->data);
	printf("\n");
	return 0;
}