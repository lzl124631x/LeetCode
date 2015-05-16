/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <stdio.h>
#include <malloc.h>
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* listnode_create(int val){
	ListNode *p = (ListNode*)malloc(sizeof *p);
	p->val = val;
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

void listnode_append(ListNode *head, int val){
	if(!head) return;
	while(head->next){
		head = head->next;
	}
	head->next = listnode_create(val);
}

void print_list(ListNode *head){
	while(head){
		printf("[%d] ", head->val);
		head = head->next;
	}
	printf("\n");
}

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(!head) return NULL;
        ListNode *prev, *next, *mid_head, *mid_last, *prev_m;
        if(m == 1){
        	mid_head = head;
        }else{
        	prev_m = head;
        	for(int i = m - 2; i > 0; --i){
        		prev_m = prev_m->next;
        	}
        	mid_head = prev_m->next;
        }
        mid_last = prev = mid_head;
        next = mid_head->next;
        while(n-- > m){
        	mid_head = next;
        	next = mid_head->next;
        	mid_head->next = prev;
        	prev = mid_head;
        }
        if(m != 1){
        	prev_m->next = mid_head;
        }else{
        	head = mid_head;
        }
        mid_last->next = next;
        return head;
    }
};

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
	Solution s;
	head = s.reverseBetween(head, 1, 7);
	print_list(head);
	return 0;
}