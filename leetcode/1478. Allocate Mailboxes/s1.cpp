// OJ: https://leetcode.com/problems/allocate-mailboxes/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
    int minDistance(vector<int>& A, int K) {
        if (A.size() == K) return 0;
        sort(begin(A), end(A));
        int N = A.size(); 
        vector<vector<int>> dist(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int m = A[(i + j) / 2];
                for (int k = i; k <= j; ++k) dist[i][j] += abs(A[k] - m);
            }
        }
        vector<vector<int>> dp(K + 1, vector<int> (N + 1, 1e6));
        for (int i = 0; i < N; ++i) dp[1][i + 1] = dist[0][i];
        for (int k = 2; k <= K && k <= N; ++k) dp[k][k] = 0;
        for (int k = 2; k <= K; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = i; j > 0; --j) {
                    dp[k][i + 1] = min(dp[k][i + 1], dp[k - 1][j] + dist[j][i]);
                }
            }
        }
        return dp[K][N];
    }
};