// OJ: https://leetcode.com/problems/angle-between-hands-of-a-clock/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    double angleClock(int h, int m) {
        double a = h * 30 + m * 0.5, b = m * 6, d = abs(a - b);
        return min(d, 360 - d);
    }
};