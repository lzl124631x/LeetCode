// OJ: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        make_heap(begin(nums), end(nums));
        pop_heap(begin(nums), end(nums));
        pop_heap(begin(nums), end(nums) - 1);
        return (nums.back() - 1) * (*(nums.end() - 2) - 1);
    }
};