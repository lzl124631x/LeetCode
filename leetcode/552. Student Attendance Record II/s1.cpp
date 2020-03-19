// OJ: https://leetcode.com/problems/student-attendance-record-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int checkRecord(int n) {
        auto dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3)));
        long long ans = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            for (int A = 0; A <= 1; ++A) {
                for (int L = 0; L <= 2; ++L) {
                    if (A + L > i + 1) continue;
                    int val = i == 0 ? 1 : dp[i][A][L];
                    if (A != 1) dp[i + 1][A + 1][0] = (dp[i + 1][A + 1][0] + val) % mod;
                    if (L != 2) dp[i + 1][A][L + 1] = (dp[i + 1][A][L + 1] + val) % mod;
                    dp[i + 1][A][0] = (dp[i + 1][A][0] + val) % mod;
                    if (i == n - 1) ans = (ans + val) % mod;
                }
            }
        }
        return ans;
    }
};