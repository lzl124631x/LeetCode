// https://discuss.leetcode.com/topic/79906/easy-java-o-n-solution-presum-hashmap/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (!nums[i]) nums[i] = -1;
        }
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (m.count(sum)) ans = max(ans, i - m[sum]);
            else m[sum] = i;
        }
        return ans;
    }
};