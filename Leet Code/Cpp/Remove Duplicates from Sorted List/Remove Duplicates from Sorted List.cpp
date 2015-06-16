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
        if(!head) return NULL;
        ListNode *prev, *p, *cur;
        cur = head;
        while(cur){
        	prev = cur; p = cur->next;
        	while(p){
        		if(p->val == cur->val){
        			prev->next = p->next;
        			free(p);
        		}else{
        			prev = p;
        		}
        		p = prev->next;
        	}
        	cur = cur->next;
        }
        return head;
    }
};