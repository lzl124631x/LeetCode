// OJ: https://leetcode.com/problems/maximum-product-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = 1, minProd = 1, ans = INT_MIN;
        for (int n : nums) {
            int maxP = max(max(maxProd * n, minProd * n), n);
            int minP = min(min(maxProd * n, minProd * n), n);
            maxProd = maxP;
            minProd = minP;
            ans = max(ans, maxProd);
        }
        return ans;
    }
};