// OJ: https://leetcode.com/problems/valid-parenthesis-string/
// Author: github.com/lzl124631x
// Time: O(3^S) where S is the length of string s. In the worst case every character
//       is "*", so every step has 3 choices.
// Space: O(S)
class Solution {
private:
    bool dfs(string &s, int start, int leftParenCnt) {
        if (start == s.size()) return !leftParenCnt;
        if (s[start] == '(') {
            return dfs(s, start + 1, leftParenCnt + 1);
        } else if (s[start] == ')') {
            if (--leftParenCnt < 0) return false;
            return dfs(s, start + 1, leftParenCnt);
        } else {
            if (dfs(s, start + 1, leftParenCnt + 1)) return true;
            if (leftParenCnt >= 1 && dfs(s, start + 1, leftParenCnt - 1)) return true;
            return dfs(s, start + 1, leftParenCnt);
        }
    }
public:
    bool checkValidString(string s) {
        return dfs(s, 0, 0);
    }
};