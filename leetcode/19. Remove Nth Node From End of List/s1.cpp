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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head;
        while (n--) q = q->next;
        if (!q) {
            head = head->next;
            delete p;
            return head;
        }
        while (q->next) p = p->next, q = q->next;
        q = p->next;
        p->next = q->next;
        delete q;
        return head;
    }
};