// OJ: https://leetcode.com/problems/contiguous-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://discuss.leetcode.com/topic/79906/easy-java-o-n-solution-presum-hashmap/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m{{0, -1}};
        int N = nums.size(), sum = 0, ans = 0;
        for (int i = 0; i < N; ++i) {
            sum += nums[i] ? 1 : -1;
            if (m.count(sum)) ans = max(ans, i - m[sum]);
            else m[sum] = i;
        }
        return ans;
    }
};