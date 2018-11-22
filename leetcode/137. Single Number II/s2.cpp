// OJ: https://leetcode.com/problems/single-number-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            unsigned long bit = 0, mask = 1 << i;
            for (int n : nums) {
                bit += (unsigned)n & mask;
                if (bit && (bit % 3 == 0)) bit = 0;
            }
            ans |= bit;
        }
        return ans;
    }
};