// OJ: https://leetcode.com/problems/maximal-square/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<int> dp(N + 1, 0);
        for (int i = 0; i < M; ++i) {
            int prev = 0;
            for (int j = 0; j < N; ++j) {
                int cur = dp[j + 1];
                if (A[i][j] == '1') dp[j + 1] = 1 + min({dp[j], dp[j + 1], prev});
                else dp[j + 1] = 0;
                prev = cur;
                ans = max(ans, dp[j + 1]);
            }
        }
        return ans * ans;
    }
};