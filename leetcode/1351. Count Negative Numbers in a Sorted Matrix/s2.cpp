// OJ: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
// Author: github.com/lzl124631x
// Time: O(MlogN)
// Space: O(1)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for (auto &row : grid) {
            ans += upper_bound(row.rbegin(), row.rend(), -1) - row.rbegin();
        }
        return ans;
    }
};