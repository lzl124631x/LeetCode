// OJ: https://leetcode.com/problems/max-dot-product-of-two-subsequences/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int maxDotProduct(vector<int>& s, vector<int>& t) {
        int M = s.size(), N = t.size();
        if (M < N) swap(M, N), swap(s, t);
        vector<int> dp(N + 1, INT_MIN);
        for (int i = 0; i < M; ++i) {
            int prev = INT_MIN;
            for (int j = 0; j < N; ++j) {
                int cur = dp[j + 1];
                dp[j + 1] = max({ max(0, prev) + s[i] * t[j], dp[j], dp[j + 1] });
                prev = cur;
            }
        }
        return dp[N];
    }
};