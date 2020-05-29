// OJ: https://leetcode.com/problems/basic-calculator-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int ans = 0, num = 0;
        char op = '+';
        for (int i = 0, N = s.size(); i < N; ++i) {
            if (isdigit(s[i])) {
                while (i < N && isdigit(s[i])) num = 10 * num + (s[i++] - '0');
                --i;
            }
            if ((!isdigit(s[i]) && s[i] != ' ') || i == N - 1) {
                if (op == '+') st.push(num);
                else if (op == '-') st.push(-num);
                else if (op == '*') st.top() *= num;
                else if (op == '/') st.top() /= num;
                op = s[i];
                num = 0;
            }
        }
        while (st.size()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};