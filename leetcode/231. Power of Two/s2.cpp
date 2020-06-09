// OJ: https://leetcode.com/problems/power-of-two/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n - (n & -n));
    }
};