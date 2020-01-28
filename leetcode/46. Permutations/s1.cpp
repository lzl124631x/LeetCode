// OJ: https://leetcode.com/problems/permutations/
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(N)
class Solution {
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, int start) {
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            swap(nums[i], nums[start]);
            dfs(nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};