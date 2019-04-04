// OJ: https://leetcode.com/problems/degree-of-an-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> cnt, left, right;
        int deg = 0, ans = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            cnt[n]++;
            if (cnt[n] > deg) deg = cnt[n];
            if (cnt[n] == 1) left[n] = i;
            right[n] = i;
        }
        for (auto p : cnt) {
            if (p.second != deg) continue;
            ans = min(ans, right[p.first] - left[p.first] + 1);
        }
        return ans;
    }
};