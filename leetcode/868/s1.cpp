// OJ: https://leetcode.com/problems/binary-gap/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int binaryGap(int N) {
        int prev = -1, i = 0, ans = 0;
        while (N) {
            if (N % 2) {
                if (prev != -1) ans = max(ans, i - prev);
                prev = i;
            }
            N /= 2;
            ++i;
        }
        return ans;
    }
};