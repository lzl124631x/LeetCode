// OJ: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumSum(vector<int>& A) {
        int N = A.size(), ans = INT_MIN;
        auto dp = vector<vector<int>>(2, vector<int>(2));
        dp[0][0] = dp[0][1] = INT_MIN;
        for (int i = 0; i < N; ++i) {
            dp[(i + 1) % 2][0] = max(A[i], dp[i % 2][0] == INT_MIN ? INT_MIN : (dp[i % 2][0] + A[i]));
            dp[(i + 1) % 2][1] = max(dp[i % 2][1] == INT_MIN ? INT_MIN : (A[i] + dp[i % 2][1]), dp[i % 2][0]);
            ans = max({ ans, dp[(i + 1) % 2][0], dp[(i + 1) % 2][1] });
        }
        return ans;
    }
};