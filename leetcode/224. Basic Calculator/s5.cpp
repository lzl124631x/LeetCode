// OJ: https://leetcode.com/problems/basic-calculator/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int calculate(string s) {
        stack<int> signs;
        int n = 0, ans = 0, sign = 1;
        signs.push(sign);
        for (char c : s) {
            if (isdigit(c)) n = 10 * n + (c - '0');
            else if (c == '(') signs.push(sign);
            else if (c == ')') signs.pop();
            else if (c == '+' || c == '-') {
                ans += sign * n;
                n = 0;
                sign = signs.top() * (c == '+' ? 1 : -1);
            }
        }
        return ans + sign * n;
    }
};