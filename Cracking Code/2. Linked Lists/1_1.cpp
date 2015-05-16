#include <stdio.h>
#include <malloc.h>
#include <set>
using namespace std;

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
	if(!head || !head->next) return;
	set<int> s;
	s.insert(head->data);
	ListNode *p, *q;
	p = head;
	q = p->next;
	while(q){
		if(s.find(q->data) == s.end()){
			s.insert(q->data);
			p = q;
		}else{
			p->next = q->next;
			free(q);
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