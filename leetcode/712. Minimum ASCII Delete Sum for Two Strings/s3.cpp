// OJ: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        if (s1.size() > s2.size()) swap(s1, s2);
        int M = s1.size(), N = s2.size();
        vector<int> dp(N + 1);
        for (int i = 1; i <= N; ++i) dp[i] = dp[i - 1] + s2[i - 1];
        for (int i = 1; i <= M; ++i) {
            int prev = dp[0];
            dp[0] += s1[i - 1];
            for (int j = 1; j <= N; ++j) {
                int next = dp[j];
                if (s1[i - 1] == s2[j - 1]) dp[j] = prev;
                else dp[j] = min(s1[i - 1] + dp[j], s2[j - 1] + dp[j - 1]);
                prev = next;
            }
        }
        return dp[N];
    }
};