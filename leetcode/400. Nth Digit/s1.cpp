// OJ: https://leetcode.com/problems/nth-digit/
// Author: github.com/lzl124631x
// Time: O(lgN)
// Space: O(1)
class Solution {
public:
    int findNthDigit(int n) {
        int k, r, len = 1;
        long long total = 0, p = 1;
        while (n > total + p * 9 * len) {
            total += p * 9 * len;
            p *= 10;
            len++;
        }
        k = p + (n - total - 1) / len;
        r = (n - total - 1) % len;
        r = len - r - 1;
        while (r--) {
            k /= 10;
        }
        return k % 10;
    }
};