// OJ: https://leetcode.com/problems/maximum-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, cur = INT_MIN;
        for (int n : nums) {
            cur = max(cur, 0) + n;
            ans = max(ans, cur);
        }
        return ans;
    }
};