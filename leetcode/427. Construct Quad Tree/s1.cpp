// OJ: https://leetcode.com/problems/construct-quad-tree/
// Author: github.com/lzl124631x
// Time: O(logN * N^2)
// Space: O(logN)
class Solution {
private:
    Node *dfs(vector<vector<int>> &grid, int x, int y, int N) {
        bool same = true;
        for (int i = 0; i < N && same; ++i) {
            for (int j = 0; j < N && same; ++j) {
                same = grid[x][y] == grid[x + i][y + j];
            }
        }
        if (same) return new Node(grid[x][y], true, NULL, NULL, NULL, NULL);
        return new Node(true, false,
                             dfs(grid, x, y, N / 2),
                             dfs(grid, x, y + N / 2, N / 2),
                             dfs(grid, x + N / 2, y, N / 2),
                             dfs(grid, x + N / 2, y + N / 2, N / 2));
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, 0, 0, grid.size());
    }
};