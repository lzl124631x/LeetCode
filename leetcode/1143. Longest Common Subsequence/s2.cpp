// OJ: https://leetcode.com/problems/longest-common-subsequence/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int M = s.size(), N = t.size();
        if (M < N) swap(M, N), swap(s, t);
        vector<int> dp(N + 1);
        for (int i = 1; i <= M; ++i) {
            int prev = 0;
            for (int j = 1; j <= N; ++j) {
                int cur = dp[j];
                if (s[i - 1] == t[j - 1]) dp[j] = 1 + prev;
                else dp[j] = max(dp[j], dp[j - 1]);
                prev = cur;
            }
        }
        return dp[N];
    }
};