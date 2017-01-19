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
    bool hasCycle(ListNode *head) {
  		if(!head) return false;
  		ListNode *p, *q;
  		p = q = head;
  		while(q && q->next){
  			p = p->next;
  			q = q->next->next;
  			if(p == q) return true;
  		}
  		return false;
    }
};