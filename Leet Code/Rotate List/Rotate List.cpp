/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 static int list_length(ListNode *head){
 	int len = 0;
 	while(head){
 		head = head->next;
 		len++;
 	}
 	return len;
 }

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head) return NULL;
        int len = list_length(head);
        k %= len;
        if(k == 0) return head;
        ListNode *old_last, *new_last;
        old_last = head;
        while(k--) old_last = old_last->next;
        new_last = head;
        while(old_last->next){
        	old_last = old_last->next;
        	new_last = new_last->next;
        }
        old_last->next = head;
        head = new_last->next;
        new_last->next = NULL;
        return head;
    }
};