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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode newHead(0), *leftTail = &newHead, *prevLeftTail;
        int i = 0;
        for (; i < m; ++i) {
            leftTail->next = head;
            head = head->next;
            prevLeftTail = leftTail;
            leftTail = leftTail->next;
        }
        for (; i < n; ++i) {
            ListNode *p = head;
            head = head->next;
            p->next = prevLeftTail->next;
            prevLeftTail->next = p;
        }
        leftTail->next = head;
        return newHead.next;
    }
};