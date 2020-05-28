// OJ: https://leetcode.com/problems/basic-calculator-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    int getNum(string &s, int &i) {
        int ans = 0;
        while (i < s.size() && isdigit(s[i])) ans = ans * 10 + (s[i++] - '0');
        return ans;
    }
public:
    int calculate(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        int i = 0, cur = getNum(s, i), prev = cur;
        while (i < s.size()) {
            char c = s[i++];
            int n = getNum(s, i);
            if (c == '+') {
                cur += n;
                prev = n;
            } else if (c == '-') {
                cur -= n;
                prev = -n;
            } else if (c == '*') {
                cur = cur - prev + prev * n;
                prev = prev * n;
            } else {
                cur = cur - prev + prev / n;
                prev = prev / n;
            }
        }
        return cur;
    }
};