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
    ListNode* partition(ListNode* head, int x) {
        ListNode ltHead(0), *ltTail = &ltHead, geHead(0), *geTail = &geHead;
        while (head) {
            ListNode *p = head;
            head = head->next;
            if (p->val < x) {
                ltTail->next = p;
                ltTail = p;
            } else {
                geTail->next = p;
                geTail = p;
            }
        }
        ltTail->next = geHead.next;
        geTail->next = NULL;
        return ltHead.next;
    }
};