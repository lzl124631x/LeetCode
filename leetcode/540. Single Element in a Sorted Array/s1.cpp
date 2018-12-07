// OJ: https://leetcode.com/problems/single-element-in-a-sorted-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
private:
public:
    int singleNonDuplicate(vector<int>& nums) {
        int L = 0, R = nums.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (nums[M] == nums[M - 1]) {
                if ((M - L + 1) % 2) R = M;
                else L = M + 1;
            } else {
                if ((R - M + 1) % 2) L = M;
                else R = M - 1;
            } 
        }
        return nums[L];
    }
};