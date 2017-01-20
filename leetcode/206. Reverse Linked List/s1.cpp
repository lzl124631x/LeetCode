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
    ListNode* reverseList(ListNode* head) {
        ListNode newHead(0);
        while (head) {
            ListNode *p = head;
            head = head->next;
            p->next = newHead.next;
            newHead.next = p;
        }
        return newHead.next;
    }
};