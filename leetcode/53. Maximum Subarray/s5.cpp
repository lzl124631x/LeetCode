// OJ: https://leetcode.com/problems/maximum-subarray/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(logN)
class Solution {
private:
    int crossSum(vector<int>& nums, int L, int R, int p) {
        if (L == R) return nums[L];
        int left = INT_MIN, right = INT_MIN, i, sum;
        for (i = p, sum = 0; i >= L; --i) left = max(left, sum += nums[i]);
        for (i = p + 1, sum = 0; i <= R; ++i) right = max(right, sum += nums[i]);
        return left + right;
    }
    
    int helper(vector<int>& nums, int L, int R) {
        if (L == R) return nums[L];
        int p = (L + R) / 2;
        int left = helper(nums, L, p);
        int right = helper(nums, p + 1, R);
        int cross = crossSum(nums, L, R, p);
        return max(left, max(right, cross));
    }
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};