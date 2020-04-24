// OJ: https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while (m && n && m != n) {
            m >>= 1;
            n >>= 1;
            ++count;
        }
        return m << count;
    }
};