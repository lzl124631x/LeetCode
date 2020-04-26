// OJ: https://leetcode.com/problems/maximum-score-after-splitting-a-string
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxScore(string s) {
        int one = 0, zero = 0, ans = 0;
        for (char c : s) one += c == '1';
        for (int i = 0; i < s.size() - 1; ++i) {
            zero += s[i] == '0';
            one -= s[i] == '1';
            ans = max(ans, zero + one);
        }
        return ans;
    }
};