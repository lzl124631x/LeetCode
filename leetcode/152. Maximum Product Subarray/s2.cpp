// OJ: https://leetcode.com/problems/maximum-product-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& A) {
        int maxProd = 1, minProd = 1, ans = INT_MIN;
        for (int n : A) {
            int a = n * maxProd, b = n * minProd;
            maxProd = max({n, a, b});
            minProd = min({n, a, b});
            ans = max(ans, maxProd);
        }
        return ans;
    }
};