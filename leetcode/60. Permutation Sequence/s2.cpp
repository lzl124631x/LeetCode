// OJ: https://leetcode.com/problems/permutation-sequence/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    string getPermutation(int n, int k) {
        int fac = 1;
        string ans;
        for (int i = 1; i <= n; ++i) {
            fac *= i;
            ans += '0' + i;
        }
        --k;
        for (int i = 0; i < n; ++i) {
            fac /= n - i;
            int j = k / fac + i, tmp = ans[j];
            for (; j > i; --j) ans[j] = ans[j - 1];
            ans[j] = tmp;
            k %= fac;
        }
        return ans;
    }
};