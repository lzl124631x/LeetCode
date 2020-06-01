// OJ: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = 0, b = 0;
        for (int n : nums) {
            if (n >= a) {
                b = a;
                a = n;
            } else if (n > b) b = n;
        }
        return (a - 1) * (b - 1);
    }
};