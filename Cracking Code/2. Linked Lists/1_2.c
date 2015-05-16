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

void remove_duplicate(ListNode *head){
	ListNode *p, *q, *r;
	if(!head || !head->next) return;
	p = head;
	q = p->next;
	while(q){
		r = head;
		while(r->data != q->data) r = r->next;
		if(r != q){
			p->next = q->next;
			free(q);
		}else{
			p = q;
		}
		q = p->next;
	}
}

int main(){
	size_t N;
	int data;
	ListNode *head;
	while(1){
		head = NULL;
		scanf("%u", &N);
		while(N--){
			scanf("%d", &data);
			if(!head){
				head = listnode_create(data);
			}else{
				listnode_append(head, data);
			}
		}
		remove_duplicate(head);
		print_list(head);
		list_destroy(head);
	}
	return 0;
}