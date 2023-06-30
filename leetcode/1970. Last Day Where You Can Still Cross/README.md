# [1970. Last Day Where You Can Still Cross (Hard)](https://leetcode.com/problems/last-day-where-you-can-still-cross)

<p>There is a <strong>1-based</strong> binary matrix where <code>0</code> represents land and <code>1</code> represents water. You are given integers <code>row</code> and <code>col</code> representing the number of rows and columns in the matrix, respectively.</p>

<p>Initially on day <code>0</code>, the <strong>entire</strong> matrix is <strong>land</strong>. However, each day a new cell becomes flooded with <strong>water</strong>. You are given a <strong>1-based</strong> 2D array <code>cells</code>, where <code>cells[i] = [r<sub>i</sub>, c<sub>i</sub>]</code> represents that on the <code>i<sup>th</sup></code> day, the cell on the <code>r<sub>i</sub><sup>th</sup></code> row and <code>c<sub>i</sub><sup>th</sup></code> column (<strong>1-based</strong> coordinates) will be covered with <strong>water</strong> (i.e., changed to <code>1</code>).</p>

<p>You want to find the <strong>last</strong> day that it is possible to walk from the <strong>top</strong> to the <strong>bottom</strong> by only walking on land cells. You can start from <strong>any</strong> cell in the top row and end at <strong>any</strong> cell in the bottom row. You can only travel in the<strong> four</strong> cardinal directions (left, right, up, and down).</p>

<p>Return <em>the <strong>last</strong> day where it is possible to walk from the <strong>top</strong> to the <strong>bottom</strong> by only walking on land cells</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/27/1.png" style="width: 624px; height: 162px;">
<pre><strong>Input:</strong> row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/27/2.png" style="width: 504px; height: 178px;">
<pre><strong>Input:</strong> row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/27/3.png" style="width: 666px; height: 167px;">
<pre><strong>Input:</strong> row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= row, col &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>4 &lt;= row * col &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>cells.length == row * col</code></li>
	<li><code>1 &lt;= r<sub>i</sub> &lt;= row</code></li>
	<li><code>1 &lt;= c<sub>i</sub> &lt;= col</code></li>
	<li>All the values of <code>cells</code> are <strong>unique</strong>.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Union Find](https://leetcode.com/tag/union-find/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Bricks Falling When Hit (Hard)](https://leetcode.com/problems/bricks-falling-when-hit/)
* [Escape the Spreading Fire (Hard)](https://leetcode.com/problems/escape-the-spreading-fire/)

## Solution 1. Union Find

Consider `A` in reverse order -- find the first day (from the last day) that start connects with end.

Initially, use Union Find to connect all lands in the first row with `start = M * N`, and connect all lands in the last row with `end = M * N + 1`. For each cell `(x, y)`, its Union Find ID is `x * N + y`.

Traverse `A` in reverse order, connect this new land `(A[i][0], A[i][1])` with neighboring lands.

Once we find `start` connects with `end`, this day is the answer.

```cpp
// OJ: https://leetcode.com/problems/last-day-where-you-can-still-cross
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
    int latestDayToCross(int M, int N, vector<vector<int>>& A) {
        UnionFind uf(M * N + 2);
        int start = M * N, end = M * N + 1, dirs[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
        vector<vector<int>> G(M, vector<int>(N));
        for (auto &c : A) G[c[0] - 1][c[1] - 1] = 1;
        for (int j = 0; j < N; ++j) {
            if (G[0][j] == 0) uf.connect(j, start);
            if (G[M - 1][j] == 0) uf.connect((M - 1) * N + j, end);
        }
        for (int i = A.size() - 1; i >= 0; --i) {
            int x = A[i][0] - 1, y = A[i][1] - 1;
            G[x][y] = 0;
            if (x == 0) uf.connect(y, start);
            if (x == M - 1) uf.connect(x * N + y, end);
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= M || b < 0 || b >= N || G[a][b] == 1) continue;
                uf.connect(x * N + y, a * N + b);
            }
            if (uf.connected(start, end)) return i;
        }
        return 0;
    }
};
```