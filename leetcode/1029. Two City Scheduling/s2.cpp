// OJ: https://leetcode.com/problems/two-city-scheduling/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& A) {
        int N = A.size();
        vector<int> dp(N / 2 + 1);
        for (int i = 0; i < N; ++i) {
            for (int j = min(i + 1, N / 2); j >= 1; --j) {
                dp[j] = min((i + 1 > j ? dp[j] + A[i][1] : INT_MAX), dp[j - 1] + A[i][0]);
            }
            dp[0] += A[i][1];
        }
        return dp[N / 2];
    }
};