// OJ: https://leetcode.com/problems/shortest-common-supersequence/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
// Ref: https://leetcode.com/problems/shortest-common-supersequence/discuss/312757/JavaPython-3-O(mn)-clean-DP-code-w-picture-comments-and-analysis.
class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int M = s.size(), N = t.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        string ans(M + N - dp[M][N], ' ');
        for (int i = M, j = N, k = ans.size() - 1; k >= 0; --k) {
            if (i && j && s[i - 1] == t[j - 1]) ans[k] = s[--i], --j;
            else if (i && dp[i][j] == dp[i - 1][j]) ans[k] = s[--i];
            else ans[k] = t[--j];
        }
        return ans;
    }
};