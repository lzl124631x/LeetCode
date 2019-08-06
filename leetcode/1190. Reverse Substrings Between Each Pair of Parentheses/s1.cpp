// OJ: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    string helper(string &s, int &i) {
        string ans;
        int N = s.size();
        while (i < N) {
            while (i < N && s[i] != '(' && s[i] != ')') ans += s[i++];
            if (i >= N || s[i] == ')') break;
            ++i;
            string mid = helper(s, i);
            reverse(mid.begin(), mid.end());
            ans += mid;
            while (i < N && s[i] != ')') ans += s[i++];
            if (i >= N) break;
            ++i;
        }
        return ans;
    }
public:
    string reverseParentheses(string s) {
        int i = 0;
        return helper(s, i);
    }
};