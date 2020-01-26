// OJ: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
// Author: github.com/lzl124631x
// Time: O(N^2 * D)
// Space: O(N^2 + ND)
class Solution {
    int get(int from, int to) { return from * 1000 + to; }
public:
    int minDifficulty(vector<int>& A, int d) {
        unordered_map<int, int> m;
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            int maxV = A[i];
            for (int j = i; j < N; ++j) {
                m[get(i, j)] = maxV = max(maxV, A[j]);
            }
        }
        vector<vector<int>> dp(N + 1, vector<int>(d + 1, INT_MAX));
        for (int i = 0; i < N; ++i) dp[i + 1][1] = m[get(0,i)];
        for (int j = 2; j <= d; ++j) {
            for (int i = 0; i < N; ++i) {
                int minV = INT_MAX;
                for (int k = 0; k < i; ++k) {
                    minV = min(minV, dp[k + 1][j - 1] == INT_MAX ? INT_MAX : dp[k + 1][j - 1] + m[get(k + 1, i)]);
                }
                dp[i + 1][j] = minV;
            }
        }
        return dp[N][d] == INT_MAX ? -1 : dp[N][d];
    }
};