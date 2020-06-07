// OJ: https://leetcode.com/problems/shuffle-the-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> a, b, ans;
        for (int i = 0; i < 2 * n; ++i) {
            if (i < n) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        for (int i = 0; i < n; ++i) {
            ans.push_back(a[i]);
            ans.push_back(b[i]);
        }
        return ans;
    }
};