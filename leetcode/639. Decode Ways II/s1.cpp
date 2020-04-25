// OJ: https://leetcode.com/problems/decode-ways-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/decode-ways-ii/solution/
class Solution {
    void add(long &a, long b) { a = (a + b) % ((int)1e9+7); }
public:
    int numDecodings(string s) {
        long prev1 = s[0] == '*' ? 9 : (s[0] != '0'), prev2 = 1;
        for (int i = 1; i < s.size(); ++i) {
            long cur = 0;
            if (s[i] == '*') {
                cur = 9 * prev1;
                if (s[i - 1] == '1') add(cur, 9 * prev2);
                else if (s[i - 1] == '2') add(cur, 6 * prev2);
                else if (s[i - 1] == '*') add(cur, 15 * prev2);
            } else {
                cur = s[i] != '0' ? prev1 : 0;
                if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) add(cur, prev2);
                else if (s[i - 1] == '*') add(cur, (s[i] <= '6' ? 2 : 1) * prev2);
            }
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};