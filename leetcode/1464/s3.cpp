// OJ: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto it = max_element(begin(nums), end(nums));
        swap(*it, nums[0]);
        it = max_element(begin(nums) + 1, end(nums));
        return (nums[0] - 1) * (*it - 1);
    }
};