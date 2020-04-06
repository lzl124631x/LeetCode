// OJ: https://leetcode.com/problems/stone-game-iii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    typedef long long LL;
public:
    string stoneGameIII(vector<int>& A) {
        int N = A.size();
        vector<LL> dp(N + 1, INT_MIN);
        dp[N] = 0;
        for (int i = N - 1; i >= 0; --i) {
            int s = 0;
            for (int j = 0; j < 3; ++j) {
                if (i + j >= N) break;
                s += A[i + j];
                dp[i] = max(dp[i], s - dp[i + j + 1]);
            }
        }
        return dp[0] > 0 ? "Alice" : (dp[0] < 0 ? "Bob" : "Tie");
    }
};