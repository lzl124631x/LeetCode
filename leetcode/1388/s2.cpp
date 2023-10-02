// OJ: https://leetcode.com/problems/pizza-with-3n-slices/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
    int solve(vector<int> A, int cnt) {
        int N = A.size();
        vector<vector<int>> dp(3, vector<int>(cnt + 1, -1e9));
        for (int i = 0; i < 3; ++i) dp[i][0] = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= min(cnt, i / 2 + 1); ++j) {
                dp[(i + 1) % 3][j] = max(dp[i % 3][j], (i == 0 ? 0 : dp[(i + 2) % 3][j - 1]) + A[i]);
            }
        }
        return dp[N % 3][cnt];
    }
public:
    int maxSizeSlices(vector<int>& A) {
        int N = A.size(), ans = 0;
        return max(solve(vector<int>(A.begin(), A.end() - 1), N / 3),
                    solve(vector<int>(A.begin() + 1, A.end()), N / 3));
    }
};