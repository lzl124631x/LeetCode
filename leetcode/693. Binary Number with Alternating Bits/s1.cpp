// OJ: https://leetcode.com/problems/binary-number-with-alternating-bits/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        while (n) {
            int d = n % 2;
            n /= 2;
            if (prev == d) return false;
            prev = d;
        }
        return true;
    }
};