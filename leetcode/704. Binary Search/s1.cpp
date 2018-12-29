// OJ: https://leetcode.com/problems/binary-search/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (nums[M] > target) R = M - 1;
            else if (nums[M] < target) L = M + 1;
            else return M;
        }
        return -1;
    }
};