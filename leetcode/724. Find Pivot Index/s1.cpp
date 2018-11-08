// OJ: https://leetcode.com/problems/find-pivot-index
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty()) return -1;
        int sum = accumulate(nums.begin(), nums.end(), 0) - nums[0];
        int left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (left == sum) return i;
            left += nums[i];
            if (i + 1 < nums.size()) sum -= nums[i + 1];
        }
        return -1;
    }
};