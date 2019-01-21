// OJ: https://leetcode.com/problems/permutation-sequence/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        for (int i = 1; i <= n; ++i) ans += '0' + i;
        k--;
        for (int i = n; i > 0; --i) {
            int p = 1;
            for (int j = 1; j < i; ++j) p *= j;
            int t = n - i + k / p, tmp = ans[t];
            for (; t > n - i; --t) ans[t] = ans[t - 1];
            ans[n - i] = tmp;
            k %= p;
        }
        return ans.substr(0, n);
    }
};