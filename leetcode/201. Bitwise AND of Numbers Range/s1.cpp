// OJ: https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for (int i = 0; i < 31; ++i) {
            int k = 1 << i, a = m / k, b = n / k;
            ans |= (a == b && a % 2) << i;
        }
        return ans;
    }
};