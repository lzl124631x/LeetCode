// OJ: https://leetcode.com/problems/minimum-size-subarray-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, i = 0, j = 0, N = nums.size(), ans = INT_MAX;
        while (j < N) {
            while (j < N && sum < s) sum += nums[j++];
            if (sum < s) break;
            while (i < j && sum >= s) sum -= nums[i++];
            ans = min(ans, j - i + 1);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};