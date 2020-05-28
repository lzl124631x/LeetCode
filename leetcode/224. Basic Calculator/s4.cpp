// OJ: https://leetcode.com/problems/basic-calculator/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int ans = 0, sign = 1;
        for (int i = 0, N = s.size(); i < N; ++i) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < N && isdigit(s[i])) num = 10 * num + (s[i++] - '0');
                --i;
                ans += sign * num;
            } else if (s[i] == '+') sign = 1;
            else if (s[i] == '-') sign = -1;
            else if (s[i] == '(') {
                st.push(ans);
                st.push(sign);
                sign = 1;
                ans = 0;
            } else if (s[i] == ')') {
                ans *= st.top(); st.pop();
                ans += st.top(); st.pop();
            }
        }
        return ans;
    }
};