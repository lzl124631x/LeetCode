// OJ: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/discuss/574943/Java-Detailed-Explanation-with-Graph-Demo-DP-Easy-Understand
class Solution {
    typedef long long LL;
public:
    int numOfWays(int n) {
        LL mod = 1e9+7, color2 = 6, color3 = 6;
        for (int i = 2; i <= n; ++i) {
            LL c3 = (2 * color3 + 2 * color2) % mod;
            LL c2 = (2 * color3 + 3 * color2) % mod;
            color2 = c2, color3 = c3;
        }
        return (color2 + color3) % mod;
    }
};