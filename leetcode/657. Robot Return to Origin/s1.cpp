// OJ: https://leetcode.com/problems/robot-return-to-origin/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool judgeCircle(string moves) {
        int V = 0, H = 0;
        for (char c : moves) {
            switch (c) {
                case 'U': ++V; break;
                case 'D': --V; break;
                case 'L': ++H; break;
                case 'R': --H; break;
            }
        }
        return !V && !H;
    }
};