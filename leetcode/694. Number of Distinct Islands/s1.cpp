// OJ: https://leetcode.com/problems/number-of-distinct-islands/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
// Ref: https://leetcode.com/problems/number-of-distinct-islands/discuss/194673/C%2B%2B-easy-to-understand
class Solution {
private:
    unordered_set<string> s;
    int M, N;
    void explore(vector<vector<int>>& grid, int x, int y, string &path, char dir) {
        if (x < 0 || x >= M || y < 0 || y >= N || !grid[x][y]) return;
        grid[x][y] = 0;
        path.push_back(dir);
        explore(grid, x + 1, y, path, 'd');
        explore(grid, x, y + 1, path, 'r');
        explore(grid, x - 1, y, path, 'u');
        explore(grid, x, y - 1, path, 'l');
        path.push_back('x');
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                string path;
                explore(grid, i, j, path, 'o');
                if (path.size()) s.insert(path);
            }
        }
        return s.size();
    }
};