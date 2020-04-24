// OJ: https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) n = n & (n - 1);
        return n;
    }
};