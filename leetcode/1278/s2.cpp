// OJ: https://leetcode.com/problems/palindrome-partitioning-iii/
// Author: github.com/lzl124631x
// Time: O(K * N^2)
// Space: O(K * N^2)
class Solution {
    typedef long long LL;
    inline void setMin(LL &a, LL b) { a = min(a, b); }
public:
    int palindromePartition(string s, int K) {
        int N = s.size();
        vector<vector<LL>> pal(N, vector<LL>(N));
        vector<vector<LL>> dp(K + 1, vector<LL>(N, 1e9));
        for (int i = N - 2; i >= 0; --i) {
            for (int j = i + 1; j < N; ++j) {
                pal[i][j] = (s[i] != s[j]) + pal[i + 1][j - 1];
            }
        }
        for (int i = 0; i < N; ++i) dp[1][i] = pal[0][i];
        for (int k = 2; k <= K; ++k) {
            for (int i = k - 1; i < N; ++i) {
                for (int j = k - 2; j < i; ++j) {
                    setMin(dp[k][i], dp[k - 1][j] + pal[j + 1][i]);
                }
            }
        }
        return dp[K][N - 1];
    }
};