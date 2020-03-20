// OJ: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maximumSum(vector<int>& A) {
        int N = A.size(), ans = INT_MIN;
        auto dp = vector<vector<int>>(N + 1, vector<int>(2));
        dp[0][0] = dp[0][1] = INT_MIN;
        for (int i = 0; i < N; ++i) {
            dp[i + 1][0] = max(A[i], dp[i][0] == INT_MIN ? INT_MIN : (dp[i][0] + A[i]));
            dp[i + 1][1] = max(dp[i][1] == INT_MIN ? INT_MIN : (A[i] + dp[i][1]), dp[i][0]);
            ans = max({ ans, dp[i + 1][0], dp[i + 1][1] });
        }
        return ans;
    }
};