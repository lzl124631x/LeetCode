class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')' && st.top() != -1 && s[st.top()] == '(') st.pop();
            else st.push(i);
            ans = max(ans, i - st.top());
        }
        return ans;
    }
};