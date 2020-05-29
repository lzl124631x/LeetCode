// OJ: https://leetcode.com/problems/basic-calculator-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int calculate(string s) {
        int num = 0, ans = 0, cur = 0;
        char op = '+';
        for (int i = 0, N = s.size(); i < N; ++i) {
            if (isdigit(s[i])) num = 10 * num + (s[i] - '0');
            if ((!isdigit(s[i]) && s[i] != ' ') || i == N - 1) {
                if (op == '+') cur += num;
                else if (op == '-') cur -= num;
                else if (op == '*') cur *= num;
                else cur /= num;
                if (s[i] == '+' || s[i] == '-' || i == N - 1) {
                    ans += cur;
                    cur = 0;
                }
                op = s[i];
                num = 0;
            }
        }
        return ans;
    }
};