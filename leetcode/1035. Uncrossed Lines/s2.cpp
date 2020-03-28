// OJ: https://leetcode.com/problems/uncrossed-lines/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int M = A.size(), N = B.size();
        if (M < N) swap(M, N), swap(A, B);
        vector<int> dp(N + 1);
        for (int i = 0; i < M; ++i) {
            int prev = 0;
            for (int j = 0; j < N; ++j) {
                int cur = dp[j + 1];
                if (A[i] == B[j]) dp[j + 1] = 1 + prev;
                else dp[j + 1] = max(dp[j + 1], dp[j]);
                prev = cur;
            }
        }
        return dp[N];
    }
};