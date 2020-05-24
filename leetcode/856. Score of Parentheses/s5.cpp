// OJ: https://leetcode.com/problems/score-of-parentheses/solution/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/score-of-parentheses/solution/
class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 0, depth = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(') ++depth;
            else {
                --depth;
                if (i - 1 >= 0 && S[i - 1] == '(') ans += 1 << depth;
            }
        }
        return ans;
    }
};