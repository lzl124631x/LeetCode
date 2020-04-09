// OJ: https://leetcode.com/problems/filling-bookcase-shelves/
// Author: github.com/lzl124631x
// Time: O(NW)
// Space: O(N)
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& A, int W) {
        int N = A.size();
        vector<int> dp(N, INT_MAX);
        for (int i = 0; i < N; ++i) {
            int sum = 0, mx = 0;
            for (int j = i; j >= 0 && sum + A[j][0] <= W; --j) {
                sum += A[j][0];
                mx = max(mx, A[j][1]);
                dp[i] = min(dp[i], (j - 1 >= 0 ? dp[j - 1] : 0) + mx);
            }
        }
        return dp[N - 1];
    }
};