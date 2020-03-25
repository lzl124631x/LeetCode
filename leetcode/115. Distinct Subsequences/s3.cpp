// OJ: https://leetcode.com/problems/distinct-subsequences
// Author: github.com/lzl124631x
// Time: O(ST)
// Space: O(T)
class Solution {
    typedef long long LL;
public:
    int numDistinct(string s, string t) {
        int M = s.size(), N = t.size();
        vector<LL> dp(N + 1);
        for (int i = M; i >= 0; --i) {
            for (int j = 0; j <= N; ++j) {
                if (i == M || j == N) dp[j] = j == N;
                else if (s[i] == t[j]) dp[j] += dp[j + 1];
            }
        }
        return dp[0];
    }
};