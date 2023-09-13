// OJ: https://leetcode.com/problems/parsing-a-boolean-expression/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H) where H is the maximum depth of the expression
class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> op;
        stack<bool> ans;
        int i = 0, N = s.size();
        while (i < N) {
            if (s[i] == 't' || s[i] == 'f') ans.push(s[i++] == 't');
            else if (s[i] == '!' || s[i] == '&' || s[i] == '|') {
                op.push(s[i]);
                if (s[i] != '!') ans.push(op.top() == '&');
                i += 2;
            } else if (s[i] == ',' || s[i] == ')') {
                if (op.top() == '&' || op.top() == '|') {
                    bool val = ans.top();
                    ans.pop();
                    if (op.top() == '&') ans.top() = ans.top() && val;
                    else ans.top() = ans.top() || val;
                } else ans.top() = !ans.top();
                if (s[i] == ')') op.pop();
                ++i;
            }
        }
        return ans.top();
    }
};