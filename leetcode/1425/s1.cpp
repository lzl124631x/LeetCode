// OJ: https://leetcode.com/problems/constrained-subsequence-sum/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(N)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& A, int k) {
        int maxVal = *max_element(begin(A), end(A));
        if (maxVal <= 0) return maxVal;
        int N = A.size(), ans = 0;
        vector<int> dp(N);
        for (int i = 0; i < N; ++i) {
            int mx = 0;
            for (int j = 1; j <= k; ++j) {
                if (i - j < 0) break;
                mx = max(mx, dp[i - j]);
                if (A[i - j] > 0) break;
            }
            dp[i] = mx + A[i];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};