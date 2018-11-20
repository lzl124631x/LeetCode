// OJ: https://leetcode.com/problems/subsets-ii/
// Author: github.com/lzl124631x
// Time: O(N^2 * 2^N)
// Space: O(N)
class Solution {
private:
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, int start, vector<int> &sub, int len) {
        if (!len) {
            ans.push_back(sub);
            return;
        }
        for (int i = start; i <= nums.size() - len; ++i) {
            if (i != start && nums[i] == nums[i - 1]) continue;
            sub.push_back(nums[i]);
            dfs(nums, i + 1, sub, len - 1);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        for (int i = 0; i <= nums.size(); ++i) dfs(nums, 0, v, i);
        return ans;
    }
};