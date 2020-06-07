// OJ: https://leetcode.com/problems/shuffle-the-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            if (i < n) ans[2 * i] = nums[i];
            else ans[2 * (i - n) + 1] = nums[i];
        }
        return ans;
    }
};