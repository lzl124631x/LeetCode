// OJ: https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
// Author: github.com/lzl124631x
// Time: O(F(k)) where F(k) is the steps to compute the fibonacci number greater than k
// Space: O(1)
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if (k == 0) return 0;
        int a = 1, b = 1;
        while (a + b <= k) {
            int c = a + b;
            a = b;
            b = c;
        }
        return findMinFibonacciNumbers(k - b) + 1;
    }
};