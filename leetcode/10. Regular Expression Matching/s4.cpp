// OJ: https://leetcode.com/problems/regular-expression-matching/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    bool isMatch(string s, string p) {
        int M = s.size(), N = p.size();
        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1));
        dp[0][0] = true;
        for (int i = 0; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (j < N && p[j] == '*') continue; // the next element is '*', skip the current one
                if (p[j - 1] == '*') {
                    int k = i;
                    do {
                        if (dp[i][j] = dp[k][j - 2]) break;
                        if (k > 0 && (p[j - 2] == '.' || s[k - 1] == p[j - 2])) --k;
                        else break;
                    } while (k >= 0);
                } else if (i - 1 >= 0 && (p[j - 1] == '.' || s[i - 1] == p[j - 1])) dp[i][j] = dp[i - 1][j - 1];
            }
        }
        return dp[M][N];
    }
};