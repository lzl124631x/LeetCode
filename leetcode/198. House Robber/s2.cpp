// OJ: https://leetcode.com/problems/house-robber/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, prev2 = 0;
        for (int n : nums) {
            int cur = max(prev, prev2 + n);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};