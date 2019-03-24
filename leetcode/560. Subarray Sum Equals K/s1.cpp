// OJ: https://leetcode.com/problems/subarray-sum-equals-k/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        unordered_map<int, int> m{{0, 1}};
        for (int n : nums) {
            sum += n;
            auto it = m.find(sum - k);
            if (it != m.end()) ans += it->second;
            m[sum]++;
        }
        return ans;
    }
};