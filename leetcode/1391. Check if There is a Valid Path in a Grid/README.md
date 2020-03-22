# [1391. Check if There is a Valid Path in a Grid (Medium)](https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/)

Given a <em>m</em> x <em>n</em> <code>grid</code>. Each cell of the <code>grid</code> represents a street. The street of&nbsp;<code>grid[i][j]</code> can be:
<ul>
	<li><strong>1</strong> which means a street connecting the left cell and the right cell.</li>
	<li><strong>2</strong> which means a street connecting the upper cell and the lower cell.</li>
	<li><b>3</b>&nbsp;which means a street connecting the left cell and the lower cell.</li>
	<li><b>4</b> which means a street connecting the right cell and the lower cell.</li>
	<li><b>5</b> which means a street connecting the left cell and the upper cell.</li>
	<li><b>6</b> which means a street connecting the right cell and the upper cell.</li>
</ul>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/03/05/main.png" style="width: 450px; height: 708px;"></p>

<p>You will initially start at the street of the&nbsp;upper-left cell <code>(0,0)</code>. A valid path in the grid is a path which starts from the upper left&nbsp;cell <code>(0,0)</code> and ends at the bottom-right&nbsp;cell <code>(m - 1, n - 1)</code>. <strong>The path should only follow the streets</strong>.</p>

<p><strong>Notice</strong> that you are <strong>not allowed</strong> to change any street.</p>

<p>Return <i>true</i>&nbsp;if there is a valid path in the grid or <em>false</em> otherwise.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/03/05/e1.png" style="width: 455px; height: 311px;">
<pre><strong>Input:</strong> grid = [[2,4,3],[6,5,2]]
<strong>Output:</strong> true
<strong>Explanation:</strong> As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/03/05/e2.png" style="width: 455px; height: 293px;">
<pre><strong>Input:</strong> grid = [[1,2,1],[1,2,1]]
<strong>Output:</strong> false
<strong>Explanation:</strong> As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1,2]]
<strong>Output:</strong> false
<strong>Explanation:</strong> You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1,1,1,1,1,3]]
<strong>Output:</strong> true
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> grid = [[2],[2],[2],[2],[2],[2],[6]]
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 6</code></li>
</ul>

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. Union Find

```cpp
// OJ: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class UnionFind {
private:
    vector<int> id, rank;
    int find (int i) {
        if (id[i] == i) return i;
        return id[i] = find(id[i]);
    }
public:
    UnionFind(int n) : id(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) id[i] = i;
    }
    void connect(int i, int j) {
        int p = find(i), q = find(j);
        if (p == q) return;
        if (rank[p] > rank[q]) id[p] = q;
        else {
            id[q] = p;
            if (rank[p] == rank[q]) rank[p]++;
        }
    }
    bool connected(int i, int j) { return find(i) == find(j); }
};
class Solution {
    int M, N;
    int h(int x, int y) { return x * N + y; }
    const int dirs[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
    const int neighbor[6][2] = {{0,1}, {2,3}, {0,3}, {1,3}, {0,2}, {1,2}};
public:
    bool hasValidPath(vector<vector<int>>& A) {
        M = A.size(), N = A[0].size();
        UnionFind uf(M * N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int n : neighbor[A[i][j] - 1]) {
                    int x = i + dirs[n][0], y = j + dirs[n][1];
                    if (x < 0 || x >= M || y < 0 || y >= N) continue;
                    int r = n ^ 1;
                    auto &rn = neighbor[A[x][y] - 1];
                    if (rn[0] != r && rn[1] != r) continue;
                    uf.connect(h(x, y), h(i, j));
                }
            }
        }
        return uf.connected(h(0,0), h(M-1,N-1));
    }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
// Ref: https://www.youtube.com/watch?v=SpMez87v0O8
class Solution {
    int M, N;
    vector<vector<int>> A;
    vector<vector<bool>> vis;
    int h(int x, int y) { return x * N + y; }
    int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1}, t[6] = {4|8, 1|2, 8|1, 4|1, 8|2, 4|2};
    bool dfs(int i, int j) {
        if (i == M - 1 && j == N - 1) return 1;
        vis[i][j] = 1;
        for (int k = 0; k < 4; ++k) {
            if (t[A[i][j] - 1] >> k & 1 ^ 1) continue; // If A[i][j] can't extend to this direction, skip
            int x = i + dx[k], y = j + dy[k];
            if (x < 0 || x >= M || y < 0 || y >= N || vis[x][y]) continue;
            int rk = k ^ 1;
            if (t[A[x][y] - 1] >> rk & 1 ^ 1) continue; // If A[x][y] can't extend back, skip
            if (dfs(x, y)) return 1;
        }
        return 0;
    }
public:
    bool hasValidPath(vector<vector<int>>& A) {
        M = A.size(), N = A[0].size();
        this->A = A;
        vis.assign(M, vector<bool>(N));
        return dfs(0, 0);
    }
};
```