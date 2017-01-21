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
    ListNode* swapPairs(ListNode* head) {
        ListNode newHead(0), *newTail = &newHead;
        while (head && head->next) {
            ListNode *p = head, *q = head->next;
            head = q->next;
            newTail->next = q;
            q->next = p;
            newTail = p;
        }
        newTail->next = head;
        return newHead.next;
    }
};