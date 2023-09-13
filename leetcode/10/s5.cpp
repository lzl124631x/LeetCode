// OJ: https://leetcode.com/problems/regular-expression-matching/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
// Ref: https://leetcode.com/problems/regular-expression-matching/solution/
class Solution {
public:
    bool isMatch(string s, string p) {
        int M = s.size(), N = p.size();
        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1));
        dp[M][N] = true;
        for (int i = M; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                bool match = i < M && (p[j] == '.' || p[j] == s[i]);
                if (j + 1 < N && p[j + 1] == '*') dp[i][j] = dp[i][j + 2] || (match && dp[i + 1][j]);
                else dp[i][j] = match && dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }
};