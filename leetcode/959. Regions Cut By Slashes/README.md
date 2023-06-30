# [959. Regions Cut By Slashes (Medium)](https://leetcode.com/problems/regions-cut-by-slashes/)

<p>In a N x N&nbsp;<code>grid</code> composed of 1 x 1 squares, each 1 x 1 square consists of a <code>/</code>, <code>\</code>, or blank space.&nbsp; These characters divide the square into contiguous regions.</p>

<p>(Note that backslash characters are escaped, so a <code>\</code>&nbsp;is represented as <code>"\\"</code>.)</p>

<p>Return the number of regions.</p>

<p>&nbsp;</p>

<div>
<div>
<div>
<div>
<div>
<ol>
</ol>
</div>
</div>
</div>
</div>
</div>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:
</strong><span id="example-input-1-1">[
&nbsp; " /",
&nbsp; "/ "
]</span>
<strong>Output: </strong><span id="example-output-1">2</span>
<strong>Explanation: </strong>The 2x2 grid is as follows:
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/15/1.png" style="width: 82px; height: 82px;">
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input:
</strong><span id="example-input-2-1">[
&nbsp; " /",
&nbsp; "  "
]</span>
<strong>Output: </strong><span id="example-output-2">1</span>
<strong>Explanation: </strong>The 2x2 grid is as follows:
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/15/2.png" style="width: 82px; height: 82px;">
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input:
</strong><span id="example-input-3-1">[
&nbsp; "\\/",
&nbsp; "/\\"
]</span>
<strong>Output: </strong><span id="example-output-3">4</span>
<strong>Explanation: </strong>(Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
The 2x2 grid is as follows:
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/15/3.png" style="width: 82px; height: 82px;">
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input:
</strong><span id="example-input-4-1">[
&nbsp; "/\\",
&nbsp; "\\/"
]</span>
<strong>Output: </strong><span id="example-output-4">5</span>
<strong>Explanation: </strong>(Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
The 2x2 grid is as follows:
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/15/4.png" style="width: 82px; height: 82px;">
</pre>

<div>
<p><strong>Example 5:</strong></p>

<pre><strong>Input:
</strong><span id="example-input-5-1">[
&nbsp; "//",
&nbsp; "/ "
]</span>
<strong>Output: </strong><span id="example-output-5">3</span>
<strong>Explanation: </strong>The 2x2 grid is as follows:
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/15/5.png" style="width: 82px; height: 82px;">
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= grid.length == grid[0].length &lt;= 30</code></li>
	<li><code>grid[i][j]</code> is either <code>'/'</code>, <code>'\'</code>, or <code>' '</code>.</li>
</ol>
</div>
</div>
</div>
</div>
</div>

**Companies**:  
[Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Union Find](https://leetcode.com/tag/union-find/), [Graph](https://leetcode.com/tag/graph/)

## Solution 1.

For a square, if it's split by a `\` or `/`, the left region (the one touches the left border) is denoted as `0`, the right region is denoted as `1`.

```cpp
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
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/regions-cut-by-slashes/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    const int dirs[4][2] = {{0, 1}, {0,-1}, {1, 0}, {-1, 0}};
    int N;
    void dfs(vector<vector<int>> &g, int x, int y, int color) {
        if (x < 0 || x >= N || y < 0 || y >= N || g[x][y]) return;
        g[x][y] = color;
        for (auto &dir : dirs) dfs(g, x + dir[0], y + dir[1], color);
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        N = grid.size();
        vector<vector<int>> g(3 * N, vector<int>(3 * N, 0));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == '/') g[3 * i][3 * j + 2] = g[3 * i + 1][3 * j + 1] = g[3 * i + 2][3 * j] = 1;
                else if (grid[i][j] == '\\') g[3 * i][3 * j] = g[3 * i + 1][3 * j + 1] = g[3 * i + 2][3 * j + 2] = 1;
            }
        }
        N *= 3;
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                 if (!g[i][j]) dfs(g, i, j, ++ans + 1);
            }
        }
        return ans;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/regions-cut-by-slashes/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
#define TO(d) dfs(grid, g, x + dirs[d][0], y + dirs[d][1], d, color)
class Solution {
    int N;
    void setLeftColor(vector<vector<int>> &g, int x, int y, int color) {
        g[x][y] += color * 100;
    }
    void setRightColor(vector<vector<int>> &g, int x, int y, int color) {
        g[x][y] += color;
    }
    int getLeftColor(vector<vector<int>> &g, int x, int y) {
        return g[x][y] / 100;
    }
    int getRightColor(vector<vector<int>> &g, int x, int y) {
        return g[x][y] % 100;
    }
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    // 0 U, 1 R, 2 D, 3 L
    void dfs(vector<string>& grid, vector<vector<int>> &g, int x, int y, int d, int color) {
        if (x < 0 || x >= N || y < 0 || y >= N) return;
        if (grid[x][y] == ' ') {
            if (g[x][y]) return;
            g[x][y] = color;
            for (int i = 0; i < 4; ++i) TO(i);
        } else if (grid[x][y] == '/') {
            if (!getLeftColor(g, x, y) && (d == 2 || d == 1)) {
                setLeftColor(g, x, y, color);
                TO(0);
                TO(3);
            }
            if (!getRightColor(g, x, y) && (d == 0 || d == 3)) {
                setRightColor(g, x, y, color);
                TO(1);
                TO(2);
            }
        } else {
            if (!getLeftColor(g, x, y) && (d == 1 || d == 0)) {
               setLeftColor(g, x, y, color);
                TO(2);
                TO(3);
            }
            if (!getRightColor(g, x, y) && (d == 2 || d == 3)) {
                setRightColor(g, x, y, color);
                TO(0);
                TO(1);
            }
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        N = grid.size();
        int color = 0;
        vector<vector<int>> g(N, vector<int>(N, 0));
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                if (grid[x][y] == ' ') {
                    if (!g[x][y]) dfs(grid, g, x, y, 0, ++color);
                }
                else if (grid[x][y] == '/') {
                    if (!getLeftColor(g, x, y)) {
                        ++color;
                        dfs(grid, g, x, y, 1, color);
                        dfs(grid, g, x, y, 2, color);
                    }
                    if (!getRightColor(g, x, y)) {
                        ++color;
                        dfs(grid, g, x, y, 0, color);
                        dfs(grid, g, x, y, 3, color);
                    }
                } else {
                    if (!getLeftColor(g, x, y)) {
                        ++color;
                        dfs(grid, g, x, y, 0, color);
                        dfs(grid, g, x, y, 1, color);
                    }
                    if (!getRightColor(g, x, y)) {
                        ++color;
                        dfs(grid, g, x, y, 2, color);
                        dfs(grid, g, x, y, 3, color);
                    }
                }
            }
        }
        return color;
    }
};
```

## Solution 4. Union Find

Split each cell to 4 parts, top/right/bottom/left indexed by 0/1/2/3.

For each cell:
* If it's `' '`, connect all 4 sub-cells
* If it's `'/'`, connect top-left and bottom-right.
* If it's `'\'`, connect top-right and bottom-left.
* Connect the 4 sub-cells with the neighboring sub-cells. For example, connect the top sub-cell with the bottom sub-cell of the cell above.

```cpp
// OJ: https://leetcode.com/problems/regions-cut-by-slashes
// Author: github.com/lzl124631x
// Time: O(N^2 * log(N^2))
// Space: O(N^2)
class UnionFind {
    vector<int> id;
    int cnt;
public:
    UnionFind(int n) : id(n), cnt(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[x] = y;
        --cnt;
    }
    int getCount() { return cnt; }
};;
class Solution {
public:
    int regionsBySlashes(vector<string>& A) {
        int N = A.size(), dirs[4][2] = {{-1,0}, {0,1}, {1,0},{0,-1}}; // TRBL 0123
        UnionFind uf(4 * N * N);
        auto key = [&](int x, int y, int dir) { return 4 * (x * N + y) + dir; };
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == ' ') {
                    for (int k = 1; k < 4; ++k) uf.connect(key(i, j, 0), key(i, j, k));
                } else if (A[i][j] == '/') {
                    uf.connect(key(i, j, 0), key(i, j, 3));
                    uf.connect(key(i, j, 1), key(i, j, 2));
                } else {
                    uf.connect(key(i, j, 0), key(i, j, 1));
                    uf.connect(key(i, j, 2), key(i, j, 3));
                }
                for (int k = 0; k < 4; ++k) {
                    auto &[dx, dy] = dirs[k];
                    int a = i + dx, b = j + dy;
                    if (a < 0 || a >= N || b < 0 || b >= N) continue;
                    uf.connect(key(i, j, k), key(a, b, (k + 2) % 4));
                }
            }
        }
        return uf.getCount();
    }
};
```