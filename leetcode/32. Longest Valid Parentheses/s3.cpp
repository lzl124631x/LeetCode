// OJ: https://leetcode.com/problems/longest-valid-parentheses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/longest-valid-parentheses/solution/
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, ans = 0, N = s.size();
        for (int i = 0; i < N; ++i) {
            left += s[i] == '(';
            right += s[i] == ')';
            if (left == right) ans = max(ans, left + right);
            else if (right > left) left = right = 0;
        }
        left = 0, right = 0;
        for (int i = N - 1; i >= 0; --i) {
            left += s[i] == '(';
            right += s[i] == ')';
            if (left == right) ans = max(ans, left + right);
            else if (left > right) left = right = 0;
        }
        return ans;
    }
};