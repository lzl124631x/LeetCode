// OJ: https://leetcode.com/problems/2-keys-keyboard/
// Author: github.com/lzl124631x
// Time: O(N^(3/2))
// Space: O(N)
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1, end = sqrt(i); j <= end; ++j) {
                if (i % j) continue;
                dp[i] = min({ dp[i], dp[j] + i / j, j == 1 ? INT_MAX : (dp[i / j] + j) });
            }
        }
        return dp[n];
    }
};