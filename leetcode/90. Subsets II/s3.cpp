// OJ: https://leetcode.com/problems/subsets-ii/
// Author: github.com/lzl124631x
// Time: O(N^2 * 2^N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans(1);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ) {
            int cnt = 0, n = nums[i], len = ans.size();
            while (i < nums.size() && nums[i] == n) ++cnt, ++i;
            for (int j = 0; j < len; ++j) {
                vector<int> sub = ans[j];
                for (int k = 0; k < cnt; ++k) {
                    sub.push_back(n);
                    ans.push_back(sub);
                }
            }
        }
        return ans;
    }
};