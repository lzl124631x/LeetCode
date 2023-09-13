// OJ: https://leetcode.com/problems/remove-boxes/
// Author: github.com/lzl124631x
// Time: O(N^4)
// Space: O(N^3)
// Ref: https://leetcode.com/problems/remove-boxes/discuss/101310/Java-top-down-and-bottom-up-DP-solutions
class Solution {
    vector<vector<vector<int>>> dp;
    int solve(vector<int> &A, int i, int j, int k) {
        if (i > j) return 0;
        if (dp[i][j][k] > 0) return dp[i][j][k];
        for (; i + 1 <= j && A[i + 1] == A[i]; ++i, ++k);
        int ans = (k + 1) * (k + 1) + solve(A, i + 1, j, 0);
        for (int m = i + 1; m <= j; ++m) {
            if (A[i] != A[m]) continue;
            ans = max(ans, solve(A, i + 1, m - 1, 0) + solve(A, m, j, k + 1));
        }
        return dp[i][j][k] = ans;
    }
public:
    int removeBoxes(vector<int>& A) {
        int N = A.size();
        dp.assign(N, vector<vector<int>>(N, vector<int>(N)));
        return solve(A, 0, N - 1, 0);
    }
};