// OJ: https://leetcode.com/problems/fibonacci-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int fib(int N) {
        if (!N) return 0;
        if (N == 1) return 1;
        int prev = 0, cur = 1;
        while (--N > 0) {
            int tmp = prev + cur;
            prev = cur;
            cur = tmp;
        }
        return cur;
    }
};