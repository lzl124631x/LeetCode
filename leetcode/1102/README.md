# [1102. Path With Maximum Minimum Value (Medium)](https://leetcode.com/problems/path-with-maximum-minimum-value/)

<p>Given an <code>m x n</code> integer matrix <code>grid</code>, return <em>the maximum <strong>score</strong> of a path starting at </em><code>(0, 0)</code><em> and ending at </em><code>(m - 1, n - 1)</code> moving in the 4 cardinal directions.</p>

<p>The <strong>score</strong> of a path is the minimum value in that path.</p>

<ul>
	<li>For example, the score of the path <code>8 → 4 → 5 → 9</code> is <code>4</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/05/maxgrid1.jpg" style="width: 244px; height: 245px;">
<pre><strong>Input:</strong> grid = [[5,4,5],[1,2,6],[7,4,6]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The path with the maximum score is highlighted in yellow. 
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/05/maxgrid2.jpg" style="width: 484px; height: 165px;">
<pre><strong>Input:</strong> grid = [[2,2,1,2,2,2],[1,2,2,2,1,2]]
<strong>Output:</strong> 2
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/05/maxgrid3.jpg" style="width: 404px; height: 485px;">
<pre><strong>Input:</strong> grid = [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Union Find](https://leetcode.com/tag/union-find/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Path With Minimum Effort (Medium)](https://leetcode.com/problems/path-with-minimum-effort/)

## Solution 1. Heap

We use a max heap to do a BFS -- greedily extending towards the path with maximum score.

```cpp
// OJ: https://leetcode.com/problems/path-with-maximum-minimum-value/
// Author: github.com/lzl124631x
// Time: O(MNlog(MN))
// Space: O(MN)
class Solution {
    typedef array<int, 3> T;
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        priority_queue<T> pq;
        pq.push({A[0][0],0,0});
        A[0][0] = -1;
        while (pq.size()) {
            auto [score, x, y] = pq.top();
            pq.pop();
            if (x == M - 1 && y == N - 1) return score;
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] == -1) continue;
                pq.push({ min(score, A[a][b]), a, b });
                A[a][b] = -1;
            }
        }
        return -1;
    }
};
```

## Solution 2. UnionFind

```cpp
// OJ: https://leetcode.com/problems/path-with-maximum-minimum-value/
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
    void connect(int a, int b) {
        id[find(a)] = find(b);
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};
class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}, ans = INT_MAX;
        vector<array<int, 2>> pos;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                pos.push_back({i, j});
            }
        }
        sort(begin(pos), end(pos), [&](auto &a, auto &b) { return A[a[0]][a[1]] > A[b[0]][b[1]]; }); // Greedily pick the cells with greatest value first.
        UnionFind uf(M * N);
        for (auto &[x, y] : pos) {
            ans = min(ans, A[x][y]);
            A[x][y] = -1; // Mark A[x][y] = -1 as visited
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || b < 0 || a >= M || b >= N || A[a][b] != -1) continue;
                uf.connect(x * N + y, a * N + b); // Connect the current position with a visited neighbor
            }
            if (uf.connected(0, M * N - 1)) return ans; // If (0,0) and (m-1, n-1) are connected, we've found the path
        }
        return -1;
    }
};
```