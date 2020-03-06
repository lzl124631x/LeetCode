// OJ: https://leetcode.com/problems/strange-printer/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
// Ref: https://leetcode.com/problems/strange-printer/discuss/106810/Java-O(n3)-DP-Solution-with-Explanation-and-Simple-Optimization
class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) return 0;
        int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            dp[i][i] = 1;
            if (i > 0) dp[i - 1][i] = s[i - 1] == s[i] ? 1 : 2;
        }
        for (int len = 3; len <= N; ++len) {
            for (int i = 0; i + len <= N; ++i) {
                int val = len;
                for (int j = 0; j < len - 1; ++j) {
                    val = min(val, dp[i][i + j] + dp[i + j + 1][i + len - 1] - (s[i + j] == s[i + len - 1]));
                }
                dp[i][i + len - 1] = val;
            }
        } 
        return dp[0][N - 1];
    }
};