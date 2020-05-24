// OJ: https://leetcode.com/problems/score-of-parentheses/solution/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    int dfs(string &s, int &i) {
        int ans = 0;
        while (i < s.size() && s[i] == '(') { 
            if (i + 1 < s.size() && s[i + 1] == ')') {
                i += 2;
                ++ans;
            } else {
                ++i;
                ans += 2 * dfs(s, i);
                ++i;
            }
        }
        return ans;
    }
public:
    int scoreOfParentheses(string s) {
        int i = 0;
        return dfs(s, i);
    }
};