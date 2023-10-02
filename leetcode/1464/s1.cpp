// OJ: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) ans = max(ans, (nums[i] - 1) * (nums[j] - 1)) ;
        }
        return ans;
    }
};