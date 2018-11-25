// OJ: https://leetcode.com/problems/k-inverse-pairs-array/
// Author: github.com/lzl124631x
// Time: O(N * K^2)
// Space: O(K)
class Solution {
public:
    int kInversePairs(int n, int k) {
        if (k > n * (n - 1) / 2) return 0;
        int mod = 1e9 + 7;
        vector<int> prev(1, 1);
        for (int i = 1; i <= n; ++i) {
            vector<int> cnt(min(k + 1, (int)prev.size() + i - 1));
            for (int j = 0; j < i; ++j) {
                for (int t = 0; t < prev.size(); ++t) {
                    if (j + t > k) break;
                    cnt[j + t] = (cnt[j + t] + prev[t]) % mod;
                }
            }
            prev = cnt;
        }
        return prev[k];
    }
};