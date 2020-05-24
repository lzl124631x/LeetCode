// OJ: https://leetcode.com/problems/score-of-parentheses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') st.push(0);
            else {
                int val = max(2 * st.top(), 1);
                st.pop();
                st.top() += val;
            }
        }
        return st.top();
    }
};