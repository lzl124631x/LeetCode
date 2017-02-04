// https://discuss.leetcode.com/topic/35494/solution-explanation
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1, ans = 0, i = 0;
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) miss += nums[i++];
            else {
                miss += miss;
                ++ans;
            }
        }
        return ans;
    }
};