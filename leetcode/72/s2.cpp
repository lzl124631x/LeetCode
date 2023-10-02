// OJ: https://leetcode.com/problems/edit-distance
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int minDistance(string A, string B) {
        int M = A.size(), N = B.size();
        if (M < N) swap(A, B), swap(M, N); 
        vector<vector<int>> dp(2, vector<int>(N + 1, INT_MAX));
        for (int i = 0; i <= M; ++i) {
            for (int j = 0; j <= N; ++j) {
                if (i == 0 || j == 0) dp[i % 2][j] = i + j;
                else if (A[i - 1] == B[j - 1]) dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
                else dp[i % 2][j] = 1 + min({ dp[(i - 1) % 2][j], dp[i % 2][j - 1], dp[(i - 1) % 2][j - 1] });
            }
        }
        return dp[M % 2][N];
    }
};