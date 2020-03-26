// OJ: https://leetcode.com/problems/delete-operation-for-two-strings/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M,N))
class Solution {
public:
    int minDistance(string A, string B) {
        int M = A.size(), N = B.size();
        if (M < N) swap(M, N), swap(A, B);
        vector<int> dp(N + 1, INT_MAX);
        for (int i = 0; i <= M; ++i) {
            int prev;
            for (int j = 0; j <= N; ++j) {
                int cur = dp[j];
                if (i == 0 || j == 0) dp[j] = i + j;
                else if (A[i - 1] == B[j - 1]) dp[j] = prev;
                else dp[j] = 1 + min(dp[j], dp[j - 1]);
                prev = cur;
            }
        }
        return dp[N];
    }
};