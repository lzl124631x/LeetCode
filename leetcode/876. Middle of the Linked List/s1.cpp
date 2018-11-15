// OJ: https://leetcode.com/problems/middle-of-the-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode *node = head;
        while (node) {
            node = node->next;
            ++cnt;
        }
        cnt = (cnt + 1) / 2;
        ListNode *fast = head;
        while (cnt--) fast = fast->next;
        node = head;
        while (fast) {
            node = node->next;
            fast = fast->next;
        }
        return node;
    }
};