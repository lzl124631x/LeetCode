// OJ: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.size() < B.size()) swap(A, B);
        int M = A.size(), N = B.size(), ans = 0;
        vector<int> dp(N + 1, 0);
        for (int i = 0; i < M; ++i) {
            for (int j = N - 1; j >= 0; --j) {
                dp[j + 1] = A[i] == B[j] ? 1 + dp[j] : 0;
                ans = max(ans, dp[j + 1]);
            }
        }
        return ans;
    }
};