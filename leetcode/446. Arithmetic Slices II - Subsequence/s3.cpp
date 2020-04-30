// OJ: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        int N = A.size(), ans = 0;
        vector<vector<int>> dp(N, vector<int>(N));
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < N; ++i) pos[A[i]].push_back(i);
        for (int i = 2; i < N; ++i) {
            for (int j = 1; j < i; ++j) {
                long num = 2l * A[j] - A[i];
                if (num < INT_MIN || num > INT_MAX || !pos.count(num)) continue;
                for (int k : pos[num]) {
                    if (k >= j) break;
                    dp[i][j] += dp[j][k] + 1;
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};