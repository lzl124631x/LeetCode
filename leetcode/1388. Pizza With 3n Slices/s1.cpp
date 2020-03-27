// OJ: https://leetcode.com/problems/pizza-with-3n-slices/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    int solve(vector<int> A, int cnt) {
        int N = A.size();
        vector<vector<int>> dp(N + 1, vector<int>(cnt + 1, -1e9));
        for (int i = 0; i <= N; ++i) dp[i][0] = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= min(cnt, i / 2 + 1); ++j) {
                dp[i + 1][j] = max(dp[i][j], (i == 0 ? 0 : dp[i - 1][j - 1]) + A[i]);
            }
        }
        return dp[N][cnt];
    }
public:
    int maxSizeSlices(vector<int>& A) {
        int N = A.size(), ans = 0;
        return max(solve(vector<int>(A.begin(), A.end() - 1), N / 3),
                    solve(vector<int>(A.begin() + 1, A.end()), N / 3));
    }
};