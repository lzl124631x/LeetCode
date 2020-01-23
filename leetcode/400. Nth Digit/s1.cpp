// OJ: https://leetcode.com/problems/nth-digit/
// Author: github.com/lzl124631x
// Time: O(lgN)
// Space: O(1)
class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1, p = 1, cnt = 9;
        while (n > cnt) {
            n -= cnt;
            ++len;
            cnt = 9 * len * (p *= 10);
        }
        int k = p + (n - 1) / len, r = (n - 1) % len, i = len - r - 1;
        while (i--) k /= 10;
        return k % 10;
    }
};