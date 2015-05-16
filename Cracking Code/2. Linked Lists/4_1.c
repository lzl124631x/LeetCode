#include <stdio.h>
#include <malloc.h>
typedef struct ListNode{
	int data;
	struct ListNode *next;
} ListNode;

ListNode* listnode_create(int data){
	ListNode *p = (ListNode*)malloc(sizeof *p);
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

ListNode* addList(ListNode *l1, ListNode *l2, int carry){
	if(!l1 && !l2) return NULL;
	ListNode *result = listnode_create(carry);
	if(l1) result->data += l1->data;
	if(l2) result->data += l2->data;
	carry = result->data / 10;
	result->data %= 10;
	result->next = addList(
		l1 ? l1->next : NULL,
		l2 ? l2->next : NULL,
		carry);
	return result;
}

int main(){
	ListNode *l1, *l2, *l3;
	l1 = listnode_create(3);
	listnode_append(l1, 1);
	listnode_append(l1, 5);
	l2 = listnode_create(5);
	listnode_append(l2, 9);
	listnode_append(l2, 2);
	print_list(l1);
	print_list(l2);
	l3 = addList(l1, l2, 0);
	print_list(l3);
	list_destroy(l1);
	list_destroy(l2);
	list_destroy(l3);
	return 0;
}