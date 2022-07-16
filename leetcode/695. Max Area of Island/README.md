# [695. Max Area of Island (Medium)](https://leetcode.com/problems/max-area-of-island/)

<p>You are given an <code>m x n</code> binary matrix <code>grid</code>. An island is a group of <code>1</code>'s (representing land) connected <strong>4-directionally</strong> (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.</p>

<p>The <strong>area</strong> of an island is the number of cells with a value <code>1</code> in the island.</p>

<p>Return <em>the maximum <strong>area</strong> of an island in </em><code>grid</code>. If there is no island, return <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/01/maxarea1-grid.jpg" style="width: 500px; height: 310px;">
<pre><strong>Input:</strong> grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The answer is not 11, because the island must be connected 4-directionally.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[0,0,0,0,0,0,0,0]]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>grid[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>

**Companies**:  
[Google](https://leetcode.com/company/google), [Affirm](https://leetcode.com/company/affirm), [Amazon](https://leetcode.com/company/amazon), [Qualtrics](https://leetcode.com/company/qualtrics), [Facebook](https://leetcode.com/company/facebook), [Uber](https://leetcode.com/company/uber), [DoorDash](https://leetcode.com/company/doordash)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Union Find](https://leetcode.com/tag/union-find/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Number of Islands (Medium)](https://leetcode.com/problems/number-of-islands/)
* [Island Perimeter (Easy)](https://leetcode.com/problems/island-perimeter/)
* [Largest Submatrix With Rearrangements (Medium)](https://leetcode.com/problems/largest-submatrix-with-rearrangements/)
* [Detonate the Maximum Bombs (Medium)](https://leetcode.com/problems/detonate-the-maximum-bombs/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/max-area-of-island/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{-1,0},{1,0}}, ans = 0;
        function<int(int, int)> dfs = [&](int i, int j) {
            A[i][j] = 0;
            int cnt = 1;
            for (auto &[dx, dy] : dirs) {
                int x = i + dx, y = j + dy;
                if (x < 0 || x >= M || y < 0 || y >= N || A[x][y] == 0) continue;
                cnt += dfs(x, y);
            }
            return cnt;
        };
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 0) continue;
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};
```

## Solution 2. BFS

```cpp
// OJ: https://leetcode.com/problems/max-area-of-island/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(M + N)
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{-1,0},{1,0}}, ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 0) continue;
                queue<pair<int, int>> q{{{i, j}}};
                A[i][j] = 0;
                int cnt = 0;
                while (q.size()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (auto &[dx, dy] : dirs) {
                        int a = x + dx, b = y + dy;
                        if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] == 0) continue;
                        A[a][b] = 0;
                        q.emplace(a, b);
                    }
                    ++cnt;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
```

## Solution 3. Union Find

```cpp
// OJ: https://leetcode.com/problems/max-area-of-island/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class UnionFind {
    vector<int> id, size;
public:
    UnionFind(int N) : id(N), size(N, 1) {
        iota(begin(id), end(id), 0);
    }
    int find(int x) {
        return id[x] == x ? x : (id[x] = find(id[x]));
    }
    void connect(int x, int y) {
        int p = find(x), q = find(y);
        if (p == q) return;
        id[p] = q;
        size[q] += size[p];
    }
    int getSize(int x) { return size[x]; }
};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{-1,0},{1,0}}, ans = 0;
        UnionFind uf(M * N);
        auto key = [&](int x, int y) { return x * N + y; };
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 0) continue;
                for (auto &[dx, dy] : dirs) {
                    int a = i + dx, b = j + dy;
                    if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] == 0) continue;
                    uf.connect(key(i, j), key(a, b));
                }
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 1) ans = max(ans, uf.getSize(key(i, j)));
            }
        }
        return ans;
    }
};
```