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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    	if(!head) return NULL;
        ListNode *last = head;
        while(n--) last = last->next;
        ListNode *prev = head;
        if(last){		// remove node in middle of list
        	while(last->next){
        		prev = prev->next;
        		last = last->next;
        	}
        	last = prev->next;
        	prev->next = last->next;
        	free(last);
        }else{			// remove head
        	head = head->next;
        	free(prev);
        }
        return head;
    }
};