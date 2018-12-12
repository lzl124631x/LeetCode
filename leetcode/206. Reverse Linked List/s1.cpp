// OJ: https://leetcode.com/problems/reverse-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(0);
        while (head) {
            ListNode *node = head;
            head = head->next;
            node->next = dummy.next;
            dummy.next = node;
        }
        return dummy.next;
    }
};