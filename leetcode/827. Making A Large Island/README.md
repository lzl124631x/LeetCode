# [827. Making A Large Island (Hard)](https://leetcode.com/problems/making-a-large-island/)

<p>You are given an <code>n x n</code> binary matrix <code>grid</code>. You are allowed to change <strong>at most one</strong> <code>0</code> to be <code>1</code>.</p>

<p>Return <em>the size of the largest <strong>island</strong> in</em> <code>grid</code> <em>after applying this operation</em>.</p>

<p>An <strong>island</strong> is a 4-directionally connected group of <code>1</code>s.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> grid = [[1,0],[0,1]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1],[1,0]]
<strong>Output:</strong> 4
<strong>Explanation: </strong>Change the 0 to 1 and make the island bigger, only one island with area = 4.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1],[1,1]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Can't change any 0 to 1, only one island with area = 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>grid[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Union Find](https://leetcode.com/tag/union-find/), [Matrix](https://leetcode.com/tag/matrix/)

## Solution 1. Union Find

```cpp
// OJ: https://leetcode.com/problems/making-a-large-island/
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
    int getSize(int x) { return size[find(x)]; }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& G) {
        int M = G.size(), N = G[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}, ans = 0;
        UnionFind uf(M * N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (G[i][j] == 0) continue;
                for (auto &[dx, dy] : dirs) {
                    int x = i + dx, y = j + dy;
                    if (x < 0 || y < 0 || x >= M || y >= N || G[x][y] == 0) continue;
                    uf.connect(i * N + j, x * N + y);
                }
                ans = max(ans, uf.getSize(i * N + j));
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (G[i][j] == 1) continue;
                unordered_map<int, int> m;
                for (auto &[dx, dy] : dirs) {
                    int x = i + dx, y = j + dy;
                    if (x < 0 || y < 0 || x >= M || y >= N || G[x][y] == 0) continue;
                    m[uf.find(x * N + y)] = uf.getSize(x * N + y);
                }
                int size = 1;
                for (auto &p : m) size += p.second;
                ans = max(ans, size);
            }
        }
        return ans;
    }
};
```