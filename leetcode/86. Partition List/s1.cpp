// OJ: https://leetcode.com/problems/partition-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode ltHead(0), *ltTail = &ltHead, geHead(0), *geTail = &geHead;
        while (head) {
            auto node = head;
            head = head->next;
            if (node->val < x) {
                ltTail->next = node;
                ltTail = node;
            } else {
                geTail->next = node;
                geTail = node;
            }
        }
        ltTail->next = geHead.next;
        geTail->next = NULL;
        return ltHead.next;
    }
};