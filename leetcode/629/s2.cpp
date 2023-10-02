// OJ: https://leetcode.com/problems/k-inverse-pairs-array/
// Author: github.com/lzl124631x
// Time: O(NK * min(N, K))
// Space: O(K)
class Solution {
public:
    int kInversePairs(int N, int K) {
        if (K > N * (N - 1) / 2) return 0;
        vector<int> m(K + 1, 0);
        m[0] = 1;
        int mod = 1e9 + 7;
        for (int n = 2; n <= N; ++n) {
            for (int k = min(K, (n * (n - 1) / 2)); k > 0; --k) {
                for (int i = max(0, k - n + 1); i < k && m[i]; ++i) {
                    m[k] = (m[k] + m[i]) % mod;
                }
            }
        }
        return m[K];
    }
};