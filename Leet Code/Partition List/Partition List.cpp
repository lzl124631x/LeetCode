/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(!head) return NULL;
        ListNode *p, *lt_head, *lt_tail, *geq_head, *geq_tail;
        lt_head = lt_tail = geq_head = geq_tail = NULL;
        while(head){
        	p = head; head = head->next;
        	if(p->val < x){
        		if(!lt_head){
        			lt_head = p;
        		}else{
        			lt_tail->next = p;
        		}
        		lt_tail = p;
        	}else{
        		if(!geq_head){
        			geq_head = p;
        		}else{
        			geq_tail->next = p;
        		}
        		geq_tail = p;
        	}
        }
        if(!lt_head){
        	head = geq_head;
        }else{
        	head = lt_head;
        	lt_tail->next = geq_head;
        }
        if(geq_tail){
        	geq_tail->next = NULL;
        }
        return head;
    }
};