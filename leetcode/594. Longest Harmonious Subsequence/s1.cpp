// OJ: https://leetcode.com/problems/longest-harmonious-subsequence/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnts;
        int ans = 0;
        for (int n : nums) cnts[n]++;
        for (auto &p : cnts) {
            if (cnts.find(p.first + 1) == cnts.end()) continue;
            ans = max(ans, p.second + cnts[p.first + 1]);
        }
        return ans;
    }
};