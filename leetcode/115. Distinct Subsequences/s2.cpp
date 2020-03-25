// OJ: https://leetcode.com/problems/distinct-subsequences
// Author: github.com/lzl124631x
// Time: O(ST)
// Space: O(ST)
class Solution {
    typedef long long LL;
public:
    int numDistinct(string s, string t) {
        int M = s.size(), N = t.size();
        vector<vector<LL>> dp(M + 1, vector<LL>(N + 1));
        for (int i = M; i >= 0; --i) {
            for (int j = N; j >= 0; --j) {
                if (i == M || j == N) dp[i][j] = j == N;
                else dp[i][j] = dp[i + 1][j] + (s[i] == t[j] ? dp[i + 1][j + 1] : 0);
            }
        }
        return dp[0][0];
    }
};