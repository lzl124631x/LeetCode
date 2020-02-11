// OJ: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while (head) {
            ans <<= 1;
            ans += head->val;
            head = head->next;
        }
        return ans;
    }
};