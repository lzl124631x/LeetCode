# [200. Number of Islands (Medium)](https://leetcode.com/problems/number-of-islands/)

<p>Given a 2d grid map of <code>'1'</code>s (land) and <code>'0'</code>s (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.</p>

<p><b>Example 1:</b></p>

<pre><strong>Input:</strong>
11110
11010
11000
00000

<strong>Output:</strong>&nbsp;1
</pre>

<p><b>Example 2:</b></p>

<pre><strong>Input:</strong>
11000
11000
00100
00011

<strong>Output: </strong>3
</pre>

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/), [Union Find](https://leetcode.com/tag/union-find/)

**Similar Questions**:
* [Surrounded Regions (Medium)](https://leetcode.com/problems/surrounded-regions/)
* [Walls and Gates (Medium)](https://leetcode.com/problems/walls-and-gates/)
* [Number of Islands II (Hard)](https://leetcode.com/problems/number-of-islands-ii/)
* [Number of Connected Components in an Undirected Graph (Medium)](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)
* [Number of Distinct Islands (Medium)](https://leetcode.com/problems/number-of-distinct-islands/)
* [Max Area of Island (Medium)](https://leetcode.com/problems/max-area-of-island/)

## Solution 1. Union Find

```cpp
// OJ: https://leetcode.com/problems/number-of-islands/
// Author: github.com/lzl124631x
// Time: O(MNlog(MN))
// Space: O(MN)
class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    void connect(int a, int b) {
        id[find(a)] = find(b);
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& A) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        UnionFind uf(M * N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == '0') continue;
                for (auto &[dx, dy] : dirs) {
                    int a = i + dx, b = j + dy;
                    if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] == '0') continue;
                    uf.connect(i * N + j, a * N + b);
                }
            }
        }
        unordered_set<int> s;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == '1') s.insert(uf.find(i * N + j));
            }
        }
        return s.size();
    }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/number-of-islands/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
    int M, N;
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<char>>& A, int x, int y) {
        if (x < 0 || y < 0 || x >= M || y >= N || A[x][y] != '1') return;
        A[x][y] = 'x';
        for (auto &dir : dirs) dfs(A, x + dir[0], y + dir[1]);
    }
public:
    int numIslands(vector<vector<char>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int ans = 0;
        M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] != '1') continue;
                ++ans;
                dfs(A, i, j);
            }
        }
        return ans;
    }
};
```

## Solution 3. BFS

```cpp
// OJ: https://leetcode.com/problems/number-of-islands/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
    int M, N;
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    void bfs(vector<vector<char>> &A, int x, int y) {
        queue<pair<int, int>> q;
        q.emplace(x, y);
        A[x][y] = 'x';
        while (q.size()) {
            x = q.front().first, y = q.front().second;
            q.pop();
            for (auto &dir : dirs) {
                int i = x + dir[0], j = y + dir[1];
                if (i < 0 || j < 0 || i >= M || j >= N || A[i][j] != '1') continue;
                A[i][j] = 'x';
                q.emplace(i, j);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int ans = 0;
        M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] != '1') continue;
                ++ans;
                bfs(A, i, j);
            }
        }
        return ans;
    }
};
```