# [130. Surrounded Regions (Medium)](https://leetcode.com/problems/surrounded-regions/)

<p>Given a 2D board containing <code>'X'</code> and <code>'O'</code> (<strong>the letter O</strong>), capture all regions surrounded by <code>'X'</code>.</p>

<p>A region is captured by flipping all <code>'O'</code>s into <code>'X'</code>s in that surrounded region.</p>

<p><strong>Example:</strong></p>

<pre>X X X X
X O O X
X X O X
X O X X
</pre>

<p>After running your function, the board should be:</p>

<pre>X X X X
X X X X
X X X X
X O X X
</pre>

<p><strong>Explanation:</strong></p>

<p>Surrounded regions shouldn’t be on the border, which means that any <code>'O'</code>&nbsp;on the border of the board are not flipped to <code>'X'</code>. Any <code>'O'</code>&nbsp;that is not on the border and it is not connected to an <code>'O'</code>&nbsp;on the border will be flipped to <code>'X'</code>. Two cells are connected if they are adjacent cells connected horizontally or vertically.</p>


**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/), [Union Find](https://leetcode.com/tag/union-find/)

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
    int M, N, dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<char>> &board, int x, int y) {
        if (x < 0 || x >= M || y < 0 || y >= N || board[x][y] != 'O') return;
        board[x][y] = '#';
        for (auto &dir : dirs) dfs(board, x + dir[0], y + dir[1]);
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        M = board.size(), N = board[0].size();
        for (int i = 0; i < M; ++i) {
            dfs(board, i, 0);
            dfs(board, i, N - 1);
        }
        for (int j = 0; j < N; ++j) {
            dfs(board, 0, j);
            dfs(board, M - 1, j);
        }
        for (auto &row : board) {
            for (auto &cell : row) {
                cell = cell == '#' ? 'O' : 'X';
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
#define FILL(x, y) do { if (board[x][y] == 'O') { q.emplace(x, y); board[x][y] = '#'; }} while(0)
class Solution {
private:
  const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
  void solve(vector<vector<char>>& board) {
    if (board.empty() || board[0].empty()) return;
    int M = board.size(), N = board[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < N; ++i) {
        FILL(0, i);
        FILL(M - 1, i);
    }
    for (int i = 1; i < M - 1; ++i) {
        FILL(i, 0);
        FILL(i, N - 1);
    }
    while (q.size()) {
      auto p = q.front();
      q.pop();
      for (auto dir : dirs) {
        int x = p.first + dir[0], y = p.second + dir[1];
        if (x >= 0 && x < M && y >= 0 && y < N) FILL(x, y);
      }
    }
    for (auto &row : board)
      for (char &c : row) c = c == '#' ? 'O' : 'X';
  }
};
```

## Solution 3. Union Find

```cpp
// OJ: https://leetcode.com/problems/surrounded-regions
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
// Ref: https://discuss.leetcode.com/topic/1944/solve-it-using-union-find
class UnionFind {
    vector<int> id, rank;
public:
    UnionFind(int n): id(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) id[i] = i;
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        if (rank[x] <= rank[y]) {
            id[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        } else id[y] = x;
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};
class Solution {
    int M, N, dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    inline int get(int x, int y) { return N * x + y; }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        M = board.size(), N = board[0].size();
        UnionFind uf(M * N + 1);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] != 'O') continue;
                if (!i || i == M - 1 || !j || j == N - 1) uf.connect(get(i, j), M * N);
                for (auto &dir : dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    if (x < 0 || x >= M || y < 0 || y >= N || board[x][y] != 'O') continue;
                    uf.connect(get(i, j), get(x, y));
                }
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!uf.connected(get(i, j), M * N)) board[i][j] = 'X';
            }
        }
    }
};
```