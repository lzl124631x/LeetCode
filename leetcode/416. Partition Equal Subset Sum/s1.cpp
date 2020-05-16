// OJ: https://leetcode.com/problems/partition-equal-subset-sum/
// Author: github.com/lzl124631x
// Time: O(NS)
// Space: O(NS)
class Solution {
public:
    bool canPartition(vector<int>& A) {
        int sum = accumulate(begin(A), end(A), 0);
        if (sum % 2) return false;
        int N = A.size();
        sum /= 2;
        vector<vector<bool>> dp(N + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= N; ++i) dp[i][0] = true;
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= sum; ++j) {
                dp[i + 1][j] = dp[i][j] || (j >= A[i] && dp[i][j - A[i]]);
            }
        }
        return dp[N][sum];
    }
};