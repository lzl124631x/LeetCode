// OJ: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int minInsertions(string s) {
        int N = s.size();
        vector<int> dp(N + 1);
        for (int i = 0; i <= N; ++i) {
            int prev;
            for (int j = 0; j <= N; ++j) {
                int cur = dp[j];
                if (i == 0 || j == 0) dp[j] = i + j;
                else if (s[i - 1] == s[N - j]) dp[j] = prev;
                else dp[j] = 1 + min(dp[j], dp[j - 1]);
                prev = cur;
            }
        }
        return dp[N] / 2;
    }
};;