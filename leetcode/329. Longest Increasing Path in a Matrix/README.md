# [329. Longest Increasing Path in a Matrix (Hard)](https://leetcode.com/problems/longest-increasing-path-in-a-matrix)

Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

**Example 1:**
```
nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
```
Return `4`
The longest increasing path is `[1, 2, 6, 9]`.

**Example 2:**
```
nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
```
Return `4`
The longest increasing path is `[3, 4, 5, 6]`. Moving diagonally is not allowed.

# Solution 1. DFS
Typical DFS. Use a `vector<vector<int>> cnt`, where `cnt[i][j]` is the length of longest increasing path starting from `matrix[i][j]`. Initially values in `cnt` are all zeroes.

For each position `matrix[x][y]`,
* if `cnt[x][y]` is not zero, which means it's already visited, return `cnt[x][y]` right away.
* otherwise, probe the 4 directions, `cnt[x][y]` is one greater than its largest neightbor.

```cpp
// OJ: https://leetcode.com/problems/longest-increasing-path-in-a-matrix
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
private:
  int M, N, ans = 0, dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  vector<vector<int>> cnt;
  int dfs(vector<vector<int>> &matrix, int x, int y) {
    if (cnt[x][y]) return cnt[x][y];
    cnt[x][y] = 1;
    for (auto dir : dirs) {
      int i = x + dir[0], j = y + dir[1];
      if (i < 0 || i >= M || j < 0 || j >= N || matrix[i][j] <= matrix[x][y]) continue;
      cnt[x][y] = max(cnt[x][y], 1 + dfs(matrix, i, j));
    }
    ans = max(ans, cnt[x][y]);
    return cnt[x][y];
  }
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    M = matrix.size(), N = matrix[0].size();
    cnt = vector<vector<int>> (M, vector<int>(N, 0));
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        dfs(matrix, i, j);
    return ans;
  }
};
```