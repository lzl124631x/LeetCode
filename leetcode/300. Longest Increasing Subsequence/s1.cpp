// OJ: https://leetcode.com/problems/longest-increasing-subsequence/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size();
        vector<int> dp(N, 1);
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (A[j] < A[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(begin(dp), end(dp));
    }
};