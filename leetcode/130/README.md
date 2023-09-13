# [130. Surrounded Regions (Medium)](https://leetcode.com/problems/surrounded-regions/)

<p>Given an <code>m x n</code> matrix <code>board</code> containing <code>'X'</code> and <code>'O'</code>, <em>capture all regions that are 4-directionally&nbsp;surrounded by</em> <code>'X'</code>.</p>

<p>A region is <strong>captured</strong> by flipping all <code>'O'</code>s into <code>'X'</code>s in that surrounded region.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/xogrid.jpg" style="width: 550px; height: 237px;">
<pre><strong>Input:</strong> board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
<strong>Output:</strong> [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
<strong>Explanation:</strong> Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> board = [["X"]]
<strong>Output:</strong> [["X"]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>board[i][j]</code> is <code>'X'</code> or <code>'O'</code>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Union Find](https://leetcode.com/tag/union-find/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Number of Islands (Medium)](https://leetcode.com/problems/number-of-islands/)
* [Walls and Gates (Medium)](https://leetcode.com/problems/walls-and-gates/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/surrounded-regions/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    void solve(vector<vector<char>>& A) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        function<void(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || x >= M || y < 0 || y >= N || A[x][y] != 'O') return;
            A[x][y] = '#';
            for (auto &[dx, dy] : dirs) dfs(x + dx, y + dy);
        };
        for (int i = 0; i < M; ++i) dfs(i, 0), dfs(i, N - 1);
        for (int j = 0; j < N; ++j) dfs(0, j), dfs(M - 1, j);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                A[i][j] = A[i][j] == '#' ? 'O' : 'X';
            }
        }
    }
};
```

## Solution 2. BFS

```cpp
// OJ: https://leetcode.com/problems/surrounded-regions
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    void solve(vector<vector<char>>& A) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        auto bfs = [&](int x, int y) {
            if (A[x][y] != 'O') return;
            queue<pair<int, int>> q{{{x, y}}};
            A[x][y] = '#';
            while (q.size()) {
                auto [x, y] = q.front();
                q.pop();
                for (auto &[dx, dy] : dirs) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] != 'O') continue;
                    A[a][b] = '#';
                    q.emplace(a, b);
                }
            }
        };
        for (int i = 0; i < M; ++i) bfs(i, 0), bfs(i, N - 1);
        for (int j = 0; j < N; ++j) bfs(0, j), bfs(M - 1, j);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                A[i][j] = A[i][j] == '#' ? 'O' : 'X';
            }
        }
    }
};
```

## Solution 3. Union Find

```cpp
// OJ: https://leetcode.com/problems/surrounded-regions
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class UnionFind {
    vector<int> id;
public:
    UnionFind(int N) : id(N) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        id[find(a)] = find(b);
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};
class Solution {
public:
    void solve(vector<vector<char>>& A) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}, edge = M * N;
        auto key = [&](int x, int y) { return x * N + y; };
        UnionFind uf(M * N + 1);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] != 'O') continue;
                if (i == 0 || i == M - 1 || j == 0 || j == N - 1) uf.connect(key(i, j), edge);
                for (auto &[dx, dy] : dirs) {
                    int a = i + dx, b = j + dy;
                    if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] != 'O') continue;
                    uf.connect(key(a, b), key(i, j));
                }
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                A[i][j] = uf.connected(key(i, j), edge) ? 'O' : 'X';
            }
        }
    }
};
```