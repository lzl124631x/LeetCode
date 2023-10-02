// OJ: https://leetcode.com/problems/2-keys-keyboard/
// Author: github.com/lzl124631x
// Time: O(sqrt(N))
// Space: O(1)
// Ref: https://leetcode.com/problems/2-keys-keyboard/solution/
class Solution {
public:
    int minSteps(int n) {
        int ans = 0, d = 2;
        while (n > 1) {
            while (n % d == 0) {
                ans += d;
                n /= d;
            }
            ++d;
        }
        return ans;
    }
};