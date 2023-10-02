// OJ: https://leetcode.com/problems/remove-outermost-parentheses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans;
        int cnt = 0, start = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(') ++cnt;
            else if (--cnt == 0) {
                ans += S.substr(start + 1, i - start - 1);
                start = i + 1;
            }
        }
        return ans;
    }
};