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
    ListNode* oddEvenList(ListNode* head) {
        ListNode oddHead(0), *oddTail = &oddHead, evenHead(0), *evenTail = &evenHead;
        bool odd = true;
        while (head) {
            if (odd) {
                oddTail->next = head;
                oddTail = head;
            } else {
                evenTail->next = head;
                evenTail = head;
            }
            head = head->next;
            odd = !odd;
        }
        oddTail->next = evenHead.next;
        evenTail->next = NULL;
        return oddHead.next;
    }
};