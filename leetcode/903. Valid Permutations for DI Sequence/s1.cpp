// OJ: https://leetcode.com/problems/valid-permutations-for-di-sequence/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
// Ref: https://leetcode.com/problems/valid-permutations-for-di-sequence/discuss/168278/C%2B%2BJavaPython-DP-Solution-O(N2)
class Solution {
public:
    int numPermsDISequence(string S) {
        int N = S.size(), mod = 1e9 + 7;
        vector<int> dp(N + 1, 1), dp2(N);
        for (int i = 0; i < N; dp = dp2, ++i) {
            if (S[i] == 'I') {
                for (int j = 0, cur = 0; j < N - i; ++j) dp2[j] = cur = (cur + dp[j]) % mod;
            } else {
                for (int j = N - i - 1, cur = 0; j >= 0; --j) dp2[j] = cur = (cur + dp[j + 1]) % mod;
            }
        }
        return dp[0];
    }
};