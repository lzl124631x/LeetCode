// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(N)
// Ref: https://youtu.be/nYFd7VHKyWQ
class Solution {
    vector<int> cnt;
    vector<int> digit;
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, int start) {
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = 0; i < cnt.size(); ++i) {
            if (!cnt[i]) continue;
            cnt[i]--;
            nums[start] = digit[i];
            dfs(nums, start + 1);
            cnt[i]++;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> m;
        for (int n : nums) m[n]++;
        for (auto p : m) {
            digit.push_back(p.first);
            cnt.push_back(p.second);
        }
        dfs(nums, 0);
        return ans;
    }
};