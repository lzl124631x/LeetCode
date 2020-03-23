// OJ: https://leetcode.com/problems/interleaving-string/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    bool isInterleave(string a, string b, string c) {
        int M = a.size(), N = b.size();
        if (M + N != c.size()) return false;
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        dp[M][N] = true;
        for (int i = M; i >= 0; --i) {
            for (int j = N; j >= 0; --j) {
                if (i < M && a[i] == c[i + j]) dp[i][j] |= dp[i + 1][j];
                if (j < N && b[j] == c[i + j]) dp[i][j] |= dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};