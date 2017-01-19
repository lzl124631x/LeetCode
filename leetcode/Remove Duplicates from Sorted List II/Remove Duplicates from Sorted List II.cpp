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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode fake_head(0);
        fake_head.next = head;
        head = &fake_head;
        ListNode *prev, *p, *cur_prev, *cur;
        cur_prev = head;
        cur = head->next;
        while(cur){
        	prev = cur; p = cur->next;
        	while(p && p->val != cur->val){
        		prev = p; p = p->next;
        	}
        	if(!p){
        		cur_prev = cur;
        	}else{
        		while(p){
        			if(p->val == cur->val){
        				prev->next = p->next;
        				free(p);
        			}else{
        				prev = p;
        			}
        			p = prev->next;
        		}
        		cur_prev->next = cur->next;
        		free(cur);
        	}
        	cur = cur_prev->next;
        }
        return fake_head.next;
    }
};