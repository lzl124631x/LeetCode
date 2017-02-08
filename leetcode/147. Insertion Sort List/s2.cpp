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
    ListNode* insertionSortList(ListNode* head) {
        ListNode newHead(0);
        while (head) {
            ListNode *p = head, *q = &newHead;
            head = head->next;
            while (q->next && q->next->val < p->val) q = q->next;
            p->next = q->next;
            q->next = p;
        }
        return newHead.next;
    }
};