// OJ: https://leetcode.com/problems/split-array-largest-sum/
// Author: github.com/lzl124631x
// Time: O(N^2 * M)
// Space: O(NM)
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int N = nums.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(N + 1, LLONG_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= N && i <= m; ++i) dp[i][i] = max(dp[i - 1][i - 1], (long long)nums[i - 1]);
        for (int i = 2; i <= N; ++i) dp[1][i] = dp[1][i - 1] + nums[i - 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                long long s = 0;
                for (int k = j - 1; k >= 0; --k) {
                    long long val = min(dp[i][j], max(s += nums[k], dp[i - 1][k]));
                    if (val > dp[i][j]) break;
                    dp[i][j] = val;
                }
            }
        }
        return dp[m][N];
    }
};