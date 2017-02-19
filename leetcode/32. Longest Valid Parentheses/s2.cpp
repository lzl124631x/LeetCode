class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')' && st.size() && s[st.top()] == '(') st.pop();
            else st.push(i);
        }
        int ans = 0, end = s.size();
        while (st.size()) {
            ans = max(ans, end - st.top() - 1);
            end = st.top();
            st.pop();
        }
        return ans;
    }
};