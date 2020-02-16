// OJ: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
// Author: github.com/lzl124631x
// Time: O(M+N)
// Space: O(1)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size(), x = 0, y = N - 1, ans = 0;
        while (x < M) {
            while (y >= 0 && grid[x][y] < 0) --y;
            ans += N - 1 - y;
            ++x;
        }
        return ans;
    }
};