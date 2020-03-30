// OJ: https://leetcode.com/problems/longest-palindromic-subsequence
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int N = s.size();
        vector<int> dp(N + 1);
        for (int i = 1; i <= N; ++i) {
            int prev = 0;
            for (int j = 1; j <= N; ++j) {
                int cur = dp[j];
                if (s[i - 1] == s[N - j]) dp[j] = 1 + prev;
                else dp[j] = max(dp[j], dp[j - 1]);
                prev = cur;
            }
        }
        return dp[N];
    }
};