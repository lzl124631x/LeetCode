// OJ: https://leetcode.com/problems/longest-continuous-increasing-subsequence/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0, len = 0, prev = INT_MAX;
        for (int n : nums) {
            if (n > prev) ++len;
            else len = 1;
            prev = n;
            ans = max(ans, len);
        }
        return ans;
    }
};