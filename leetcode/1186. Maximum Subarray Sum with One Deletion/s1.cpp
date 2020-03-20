// OJ: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maximumSum(vector<int>& A) {
        int N = A.size(), ans = A[0];
        auto dp = vector<vector<int>>(N, vector<int>(2));
        dp[0][0] = A[0];
        for (int i = 1; i < N; ++i) {
            dp[i][0] = max(A[i], dp[i - 1][0] + A[i]);
            dp[i][1] = max(A[i] + dp[i - 1][1], dp[i - 1][0]);
            ans = max({ ans, dp[i][0], dp[i][1] });
        }
        return ans;
    }
};