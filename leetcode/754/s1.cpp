// OJ: https://leetcode.com/problems/reach-a-number/
// Author: github.com/lzl124631x
// Time: O(sqrt(T))
// Space: O(1)
class Solution {
public:
    int reachNumber(int target) {
        int i = 0, sum = 0;
        target = abs(target);
        while (sum < target || (sum - target) % 2 != 0) {
            sum += ++i;
        }
        return i;
    }
};