// OJ: https://leetcode.com/problems/subsets
// Author: github.com/lzl124631x
// Time: O(N^2 * 2^N)
// Space: O(N)
class Solution {
private:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int i, vector<int> &v) {
        if (i == nums.size()) {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        dfs(nums, i + 1, v);
        v.pop_back();
        dfs(nums, i + 1, v);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        dfs(nums, 0, v);
        return ans;
    }
};