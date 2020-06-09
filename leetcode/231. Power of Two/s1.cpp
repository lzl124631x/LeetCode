// OJ: https://leetcode.com/problems/power-of-two/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while ((n & 1) == 0) n >>= 1;
        return n == 1;
    }
};