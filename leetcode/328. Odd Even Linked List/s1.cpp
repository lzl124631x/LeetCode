// OJ: https://leetcode.com/problems/odd-even-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode oddHead, *oddTail = &oddHead, evenHead, *evenTail = &evenHead;
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