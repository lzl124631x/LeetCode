// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/lzl124631x
// Time: O(N! * N)
// Space: O(N)
class Solution {
    vector<vector<int>> ans;
    void move(vector<int> &nums, int from, int to) {
        int tmp = nums[from], d = from > to ? -1 : 1;
        for (int i = from; i != to; i += d) nums[i] = nums[i + d];
        nums[to] = tmp;
    }
    void permute(vector<int> &nums, int start) {
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }
        int prev = nums[start];
        for (int i = start; i < nums.size(); ++i) {
            if (i != start && nums[i] == prev) continue;
            move(nums, i, start);
            permute(nums, start + 1);
            move(nums, start, i);
            prev = nums[i];
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        permute(nums, 0);
        return ans;
    }
};