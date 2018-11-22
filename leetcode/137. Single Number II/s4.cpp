// OJ: https://leetcode.com/problems/single-number-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int low = 0, high = 0;
        for (int n : nums) {
            high ^= low & n;
            low ^= n;
            unsigned mask = ~(high & low);
            high &= mask;
            low &= mask;
        }
        return low;
    }
};