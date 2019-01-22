// OJ: https://leetcode.com/problems/integer-break/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/45341/a-simple-explanation-of-the-math-part-and-a-o-n-solution
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int p = 1;
        while (n > 4) {
            p *= 3;
            n -= 3;
        }
        p *= n;
        return p;
    }
};