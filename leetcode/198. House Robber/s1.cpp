// OJ: https://leetcode.com/problems/house-robber/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = 0, skip = 0;
        for (int n : nums) {
            int tmp = skip;
            skip = max(rob, skip);
            rob = tmp + n;
        }
        return max(rob, skip);
    }
};