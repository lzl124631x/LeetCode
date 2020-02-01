// OJ: https://leetcode.com/problems/count-vowels-permutation/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1e9 + 7, a = 1, e = 1, i = 1, o = 1, u = 1;
        while (--n) {
            int aa = ((e + i) % mod + u) % mod;
            int ee = (a + i) % mod;
            int ii = (e + o) % mod;
            int oo = i;
            int uu = (i + o) % mod;
            a = aa, e = ee, i = ii, o = oo, u = uu;
        }
        return ((((a + e) % mod + i) % mod + o) % mod + u) % mod;
    }
};