// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    typedef long long LL;
public:
    string stoneGameIII(vector<int>& A) {
        int N = A.size();
        vector<LL> dp(4, INT_MIN);
        dp[N % 4] = 0;
        for (int i = N - 1; i >= 0; --i) {
            int s = 0;
            dp[i % 4] = INT_MIN;
            for (int j = 0; j < 3; ++j) {
                if (i + j >= N) break;
                s += A[i + j];
                dp[i % 4] = max(dp[i % 4], s - dp[(i + j + 1) % 4]);
            }
        }
        return dp[0] > 0 ? "Alice" : (dp[0] < 0 ? "Bob" : "Tie");
    }
};