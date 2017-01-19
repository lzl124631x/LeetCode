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
    void reorderList(ListNode *head) {
        if(!head) return;
        ListNode *p, *prev, *last;
        int len = 0, pi = 0, i;
       	last = p = head;
        while(p && p->next){
        	last = last->next;
        	p = p->next->next;
        	pi++;
        }
        len = pi << 1;
        if(p) len++; // list length is odd
    	
    	p = last->next;
    	pi++;
    	while(p){
    		last->next = p->next;
    		prev = head;
    		i = len - pi - 1;
    		while(i--){
    			prev = prev->next;
    		}
    		p->next = prev->next;
    		prev->next = p;
    		p = last->next;
    		pi++;
    	}
    	last->next = NULL;
    }
};

int main(){
	ListNode *head;
	head = listnode_create(0);
	listnode_append(head, 1);
	listnode_append(head, 2);
	listnode_append(head, 3);
	listnode_append(head, 4);
	
	print_list(head);
	Solution s;
	s.reorderList(head);
	print_list(head);
	return 0;
}

/*
 * last 指针指示新链表的尾节点, index[last] 为 len/2 向下取整.
 * 每次将 node[last->next] 摘下, 记其对应的 index 为 pi,
 * 将该节点插入到 index 为 len - pi - 1 的节点之后.
 */