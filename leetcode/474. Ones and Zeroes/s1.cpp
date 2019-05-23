// OJ: https://leetcode.com/problems/ones-and-zeroes/
// Author: github.com/lzl124631x
// Time: O(MNS)
// Space: O(MNS)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int M, int N) {
        int S = strs.size();
        vector<vector<vector<int>>> dp(M + 1, vector<vector<int>>(N + 1, vector<int>(S + 1, 0)));
        vector<pair<int, int>> cnts(S);
        for (int i = 0; i < S; ++i) {
            auto str = strs[i];
            cnts[i].first = count(str.begin(), str.end(), '0');
            cnts[i].second = count(str.begin(), str.end(), '1');
        }
        for (int k = 1; k <= S; ++k) {
            int zeros = cnts[k - 1].first, ones = cnts[k - 1].second;
            for (int i = 0; i <= M; ++i) {
                for (int j = 0; j <= N; ++j) {
                    dp[i][j][k] = dp[i][j][k - 1];
                    if (zeros <= i && ones <= j) dp[i][j][k] = max(dp[i][j][k], 1 + dp[i - zeros][j - ones][k - 1]);
                }
            }
        }
        return dp[M][N][S];
    }
};