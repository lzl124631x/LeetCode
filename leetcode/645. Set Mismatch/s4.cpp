// OJ: https://leetcode.com/problems/set-mismatch/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup, missing;
        for (int n : nums) {
            if (nums[abs(n) - 1] < 0) dup = abs(n);
            else nums[abs(n) - 1] *= -1;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) missing = i + 1;
        }
        return { dup, missing };
    }
};