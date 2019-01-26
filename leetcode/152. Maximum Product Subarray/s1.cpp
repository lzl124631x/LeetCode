// OJ: https://leetcode.com/problems/maximum-product-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, N = nums.size(), prod = 1;
        for (int i = 0, j = 0; j < N; ) {
            while (j < N && nums[j]) {
                prod *= nums[j++];
                ans = max(ans, prod);
            }
            while (prod < 0 && i < j - 1) {
                prod /= nums[i++];
                ans = max(ans, prod);
            }
            while (j < N && !nums[j]) {
                i = ++j;
                ans = max(ans, 0);
                prod = 1;
            }
        }
        return ans;
    }
};