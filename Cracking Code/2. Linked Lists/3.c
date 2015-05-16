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

void remove_middle_node(ListNode *n){
	ListNode *next;
	if(!n || !n->next) return;
	next = n->next;
	n->data = next->data;
	n->next = next->next;
	free(next);
}

int main(){
	size_t N, n;
	int data;
	ListNode *head, *p;
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
		scanf("%u", &n);
		p = head;
		while(n-- && p) p = p->next;
		remove_middle_node(p);
		print_list(head);
		list_destroy(head);
	}
	return 0;
}

/*
 * 要删除单链表上的一个节点n就必须知道n的前一个节点, 
 * 此题可以人为创造一个前导节点, 即通过:
 * 拷贝n->next的数据到n中, 删掉n->next即可.
 */