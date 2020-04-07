// OJ: https://leetcode.com/problems/string-to-integer-atoi/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, N = s.size(), sign = 1, ans = 0;
        while (i < N && s[i] == ' ') ++i;
        if (i < N && (s[i] == '+' || s[i] == '-')) sign = s[i++] == '+' ? 1 : -1;
        while (i < N && isdigit(s[i])) {
            int n = s[i++] - '0';
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && n > INT_MAX % 10)) return sign == 1 ? INT_MAX : INT_MIN;
            ans = ans * 10 + n;
        }
        return ans * sign;
    }
};