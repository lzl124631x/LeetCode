// OJ: https://leetcode.com/problems/regions-cut-by-slashes/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
private:
    unordered_set<int> seen;
    int ans = 0, N;
    int hash(int i, int j, int pos) {
        return i + j  * 100 + pos * 10000;
    }
    void insert(queue<int> &q, int h) {
        if (seen.find(h) != seen.end()) return;
        q.push(h);
        seen.insert(h);
    }
    int bfs(vector<string>& grid, int i, int j, int pos) {
        int h = hash(i, j, pos);
        if (seen.find(h) != seen.end()) return 0;
        seen.insert(h);
        queue<int> q;
        q.push(h);
        while (q.size()) {
            int val = q.front();
            q.pop();
            i = val % 100;
            j = val / 100 % 100;
            pos = val / 10000;
            if (grid[i][j] == '\\') {
                if (pos == 0) {
                    if (j - 1 >= 0) insert(q, hash(i, j - 1, 1));
                    if (i + 1 < N) insert(q, hash(i + 1, j, grid[i + 1][j] == '\\' ? 1 : 0));
                } else {
                    if (i - 1 >= 0) insert(q, hash(i - 1, j, grid[i - 1][j] == '\\' ? 0 : 1));
                    if (j + 1 < N) insert(q, hash(i, j + 1, 0));
                }
            } else if (grid[i][j] == '/') {
                if (pos == 0) {
                    if (j - 1 >= 0) insert(q, hash(i, j - 1, 1));
                    if (i - 1 >= 0) insert(q, hash(i - 1, j, grid[i - 1][j] == '\\' ? 0 : 1));
                } else {
                    if (j + 1 < N) insert(q, hash(i, j + 1, 0));
                    if (i + 1 < N) insert(q, hash(i + 1, j, grid[i + 1][j] == '\\' ? 1 : 0));
                }
            } else {
                insert(q, hash(i, j, 1 - pos));
                if (i - 1 >= 0) insert(q, hash(i - 1, j, grid[i - 1][j] == '\\' ? 0 : 1));
                if (j + 1 < N) insert(q, hash(i, j + 1, 0));
                if (i + 1 < N) insert(q, hash(i + 1, j, grid[i + 1][j] == '\\' ? 1 : 0));
                if (j - 1 >= 0) insert(q, hash(i, j - 1, 1));
            }
        }
        return 1;
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        N = grid.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                ans += bfs(grid, i, j, 0);
                ans += bfs(grid, i, j, 1);
            }
        }
        return ans;
    }
};