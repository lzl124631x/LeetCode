// OJ: https://leetcode.com/problems/divide-two-integers/
// Author: github.com/lzl124631x
// Time: O(logD) where D is |dividend|
// Space: O(1)
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor) return 0;  // divide-by-zero error
        bool pos1 = dividend > 0, pos2 = divisor > 0, pos = !(pos1^pos2);
        if (pos1) dividend = -dividend;
        if (pos2) divisor = -divisor;
        int q = 0, d = divisor, t = 1;
        while (t > 0 && dividend < 0) {
            if (dividend - d <= 0) {
                dividend -= d;
                q -= t;
                if ((INT_MIN >> 1) < d) {
                    t <<= 1;
                    d <<= 1;  
                }           
            } else {
                d >>= 1;
                t >>= 1;
            }
        }
        return pos? -q : q;
    }
};