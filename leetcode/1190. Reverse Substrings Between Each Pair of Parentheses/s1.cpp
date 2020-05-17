// OJ: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
private:
    string solve(string &s, int &i) {
        string ans;
        int N = s.size();
        while (i < N) {
            while (i < N && s[i] != '(' && s[i] != ')') ans += s[i++];
            if (i < N) ++i;
            if (i >= N || s[i - 1] == ')') break;
            auto mid = solve(s, i);
            reverse(mid.begin(), mid.end());
            ans += mid;
        }
        return ans;
    }
public:
    string reverseParentheses(string s) {
        int i = 0;
        return solve(s, i);
    }
};