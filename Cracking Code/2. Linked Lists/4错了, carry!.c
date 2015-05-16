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

ListNode* addList(ListNode *l1, ListNode *l2){
	if(!l1 || !l2) return l1 ? l1 : l2;
	ListNode *head, *tail, *p;
	int carry = 0;
	head = tail = NULL;
	while(l1 && l2){
		carry += l1->data + l2->data;
		p = listnode_create(carry % 10);
		carry /= 10;
		if(!head){
			head = p;
		}else{
			tail->next = p;
		}
		tail = p;
		l1 = l1->next; l2 = l2->next;
	}
	if(!l1) l1 = l2;
	while(l1){
		carry += l1->data;
		p = listnode_create(carry % 10);
		carry /= 10;
		tail->next = p;
		tail = p;
		l1 = l1->next;
	}
	tail->next = 0;
	return head;
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
	l3 = addList(l1, l2);
	print_list(l3);
	list_destroy(l1);
	list_destroy(l2);
	list_destroy(l3);
	return 0;
}