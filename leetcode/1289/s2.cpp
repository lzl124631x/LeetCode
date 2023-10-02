// OJ: https://leetcode.com/problems/minimum-falling-path-sum-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
    pair<int, int> getSmallestTwo(vector<int> &A) {
        auto p = make_pair(-1, -1);
        for (int i = 0; i < A.size(); ++i) {
            if (p.first == -1 || A[i] < A[p.first]) {
                p.second = p.first;
                p.first = i;
            } else if (p.second == -1 || A[i] < A[p.second]) p.second = i;
        }
        return p;
    }
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int N = A.size();
        if (N == 1) return A[0][0];
        vector<vector<int>> dp(2, vector<int>(N));
        for (int i = 0; i < N; ++i) dp[1][i] = A[0][i];
        for (int i = 1; i < N; ++i) {
            auto p = getSmallestTwo(dp[i % 2]);
            for (int j = 0; j < N; ++j) {
                dp[(i + 1) % 2][j] = A[i][j] + dp[i % 2][p.first == j ? p.second : p.first];
            }
        }
        return *min_element(dp[N % 2].begin(), dp[N % 2].end());
    }
};