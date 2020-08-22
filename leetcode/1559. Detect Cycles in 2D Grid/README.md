## Solution 1. DFS

We can use DFS for each `A[x][y]` to see if we can form a circle from `A[x][y]`.

Let `seen[x][y]` be the length of the sequence containing the same character ending with `A[x][y]`.

In the DFS, assume the next location we want to visit is `<a, b>`.

We shouldn't visit `a, b` if either of these is true:
* `a, b` are out-of-bound.
* `A[a][b] != A[x][y]`
* `seen[a][b] != 0` and `seen[x][y] - seen[a][b] < 3`, meaning that we've visited `A[a][b]` in the sequence and the distance between `A[a][b]` and `A[x][y]` is too small to form a valid circle.

Once we find a `<a, b>` pair satisfying `seen[a][b] && seen[x][y] - seen[a][b] >= 3`, we've found a valid circle from `A[a][b]` to `A[x][y]` with length more than or equal to 4, and we can return `true`.

```cpp
// OJ: https://leetcode.com/contest/biweekly-contest-33/problems/detect-cycles-in-2d-grid/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
    int M, N, seen[500][500] = {}, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    bool dfs(vector<vector<char>>&A, int x, int y, int len) {
        seen[x][y] = len;
        for (auto &dir : dirs) {
            int a = x + dir[0], b = y + dir[1];
            if (a < 0 || b < 0 || a >= M || b >= N || A[a][b] != A[x][y] || (seen[a][b] && seen[x][y] - seen[a][b] < 3)) continue;
            if (seen[a][b] && seen[x][y] - seen[a][b] >= 3) return true;
            if (dfs(A, a, b, len + 1)) return true;
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& A) {
        M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (seen[i][j]) continue;
                if (dfs(A, i, j, 1)) return true;
            }
        }
        return false;
    }
};
```