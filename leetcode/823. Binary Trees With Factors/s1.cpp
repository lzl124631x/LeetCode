// OJ: https://leetcode.com/problems/binary-trees-with-factors/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        int mod = 1e9 + 7, N = A.size();
        sort(A.begin(), A.end());
        vector<long long> dp(N, 1);
        unordered_map<int, long long> m;
        for (int i = 0; i < N; ++i) m[A[i]] = i;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (A[i] % A[j] || m.find(A[i] / A[j]) == m.end()) continue;
                dp[i] = (dp[i] + dp[j] * dp[m[A[i] / A[j]]]) % mod;
            }
        }
        int ans = 0;
        for (auto n : dp) ans = (ans + n) % mod;
        return ans;
    }
};