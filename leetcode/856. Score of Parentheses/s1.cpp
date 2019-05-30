// OJ: https://leetcode.com/problems/score-of-parentheses/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int scoreOfParentheses(string S) {
        if (S == "()") return 1;
        int i = 0, left = 0;
        do {
            left += S[i++] == '(' ? 1 : -1;
        } while (left);
        if (i == S.size()) return 2 * scoreOfParentheses(S.substr(1, S.size() - 2));
        return scoreOfParentheses(S.substr(0, i)) + scoreOfParentheses(S.substr(i));
    }
};