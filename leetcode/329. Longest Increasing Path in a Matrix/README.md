# [329. Longest Increasing Path in a Matrix (Hard)](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)

<p>Given an <code>m x n</code> integers <code>matrix</code>, return <em>the length of the longest increasing path in </em><code>matrix</code>.</p>

<p>From each cell, you can either move in four directions: left, right, up, or down. You <strong>may not</strong> move <strong>diagonally</strong> or move <strong>outside the boundary</strong> (i.e., wrap-around is not allowed).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/05/grid1.jpg" style="width: 242px; height: 242px;">
<pre><strong>Input:</strong> matrix = [[9,9,4],[6,6,8],[2,1,1]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The longest increasing path is <code>[1, 2, 6, 9]</code>.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/27/tmp-grid.jpg" style="width: 253px; height: 253px;">
<pre><strong>Input:</strong> matrix = [[3,4,5],[3,2,6],[2,2,1]]
<strong>Output:</strong> 4
<strong>Explanation: </strong>The longest increasing path is <code>[3, 4, 5, 6]</code>. Moving diagonally is not allowed.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> matrix = [[1]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>0 &lt;= matrix[i][j] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Topological Sort](https://leetcode.com/tag/topological-sort/), [Memoization](https://leetcode.com/tag/memoization/)

# Solution 1. Topological Sort (DFS)

A DFS version topoligical sort is **Post-order Traversal + Memo**.

Use a `vector<vector<int>> cnt`, where `cnt[i][j]` is the length of longest increasing path starting from `matrix[i][j]`. Initially values in `cnt` are all zeroes.

For each position `matrix[x][y]`,
* if `cnt[x][y]` is not zero, which means it's already visited, return `cnt[x][y]` right away.
* otherwise, probe the 4 directions, `cnt[x][y]` is one greater than its largest neightbor.

```cpp
// OJ: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
    vector<vector<int>> cnt;
    int ans = 0, M, N, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(vector<vector<int>> &A, int x, int y) {
        if (cnt[x][y]) return cnt[x][y];
        cnt[x][y] = 1;
        for (auto &dir : dirs) {
            int a = x + dir[0], b = y + dir[1];
            if (a < 0 || b < 0 || a >= M || b >= N || A[a][b] <= A[x][y]) continue;
            cnt[x][y] = max(cnt[x][y], 1 + dfs(A, a, b));
        }
        return cnt[x][y];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        M = A.size(), N = A[0].size();
        cnt.assign(M, vector<int>(N));
        for (int i = 0; i < M; ++i) 
            for (int j = 0; j < N; ++j) 
                ans = max(ans, dfs(A, i, j));
        return ans;
    }
};
```

## Solution 2. Topological Sort (BFS)

```cpp
// OJ: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}, ans = 0;
        vector<vector<int>> indegree(M, vector<int>(N));
        queue<pair<int, int>> q;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                for (auto &[dx, dy] : dirs) {
                    int a = i + dx, b = j + dy;
                    if (a < 0 || b < 0 || a >= M || b >= N || A[a][b] >= A[i][j]) continue;
                    indegree[i][j]++;
                }
                if (indegree[i][j] == 0) q.push({ i, j });
            }
        }
        while (q.size()) {
           int cnt = q.size(); 
            ++ans;
            while (cnt--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto &[dx, dy] : dirs) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || b < 0 || a >= M || b >= N || A[a][b] <= A[x][y]) continue;
                    if (--indegree[a][b] == 0) q.push({ a, b });
                }
            }
        }
        return ans;
    }
};
```