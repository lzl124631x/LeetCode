// OJ: https://leetcode.com/problems/jump-game/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
private:
    vector<bool> visited;
    bool dfs(vector<int> &nums, int start) {
        if (visited[start]) return false;
        visited[start] = true;
        if (start + nums[start] >= nums.size() - 1) return true;
        for (int i = nums[start]; i >= 0; --i) {
            if (dfs(nums, start + i)) return true;
        }
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        visited = vector<bool>(nums.size());
        return dfs(nums, 0);
    }
};