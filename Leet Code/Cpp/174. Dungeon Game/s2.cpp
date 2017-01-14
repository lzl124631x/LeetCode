// https://discuss.leetcode.com/topic/6912/c-dp-solution
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon[0].empty()) return 0;
        int M = dungeon.size(), N = dungeon[0].size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, INT_MAX));
        dp[M][N - 1] = dp[M - 1][N] = 1;
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return dp[0][0];
    }
};