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
            ListNode *p = head;
            head = head->next;
            ListNode *prev = &newHead, *cur = newHead.next;
            while (cur && cur->val < p->val) {
                prev = cur;
                cur = cur->next;
            }
            p->next = cur;
            prev->next = p;
        }
        return newHead.next;
    }
};