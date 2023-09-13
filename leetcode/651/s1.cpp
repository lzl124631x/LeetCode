// OJ: https://leetcode.com/problems/4-keys-keyboard/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
// Ref: https://leetcode.com/problems/4-keys-keyboard/solution/
class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N + 1);
        for (int i = 1; i <= N; ++i) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 2; j < i - 1; ++j) dp[i] = max(dp[i], dp[i - j - 1] * j);
        }
        return dp[N];
    }
};