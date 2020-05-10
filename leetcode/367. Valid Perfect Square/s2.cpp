// OJ: https://leetcode.com/problems/valid-perfect-square/
// Author: github.com/lzl124631x
// Time: O(log(num))
// Space: O(1)
class Solution {
public:
    bool isPerfectSquare(int num) {
        long L = 1, R = num;
        while (L <= R) {
            long M = L + (R - L) / 2;
            if (M * M == num) return true;
            if (num / M < M) R = M - 1;
            else L = M + 1;
        }
        return false;
    }
};