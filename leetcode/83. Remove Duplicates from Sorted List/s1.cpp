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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        while (p) {
            ListNode *q = p->next;
            while (q && q->val == p->val) {
                p->next = q->next;
                delete q;
                q = p->next;
            }
            p = p->next;
        }
        return head;
    }
};