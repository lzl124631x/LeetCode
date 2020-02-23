// OJ: https://leetcode.com/problems/dungeon-game
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        vector<int> dp(N + 1, INT_MAX);
        dp[N - 1] = 1;
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                dp[j] = max(min(dp[j + 1], dp[j]) - A[i][j], 1);
            }
        }
        return dp[0];
    }
};