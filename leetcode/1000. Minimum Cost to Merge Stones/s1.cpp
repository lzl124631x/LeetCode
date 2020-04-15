// OJ: https://leetcode.com/problems/minimum-cost-to-merge-stones/
// Author: github.com/lzl124631x
// Time: O(N^3 / K)
// Space: O(N^2)
// Ref: https://leetcode.com/problems/minimum-cost-to-merge-stones/discuss/247567/JavaC%2B%2BPython-DP
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int N = stones.size();
        if ((N - 1) % (K - 1)) return -1;
        vector<int> prefix(N + 1);
        partial_sum(stones.begin(), stones.end(), prefix.begin() + 1);
        vector<vector<int>> dp(N, vector<int>(N));
        for (int m = K; m <= N; ++m) {
            for (int i = 0; i + m <= N; ++i) {
                int j = i + m - 1;
                dp[i][j] = INT_MAX;
                for (int mid = i; mid < j; mid += K - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
                }
                if ((j - i) % (K - 1) == 0) dp[i][j] += prefix[j + 1] - prefix[i];
            }
        }
        return dp[0][N - 1];
    }
};