# [2503. Maximum Number of Points From Grid Queries (Hard)](https://leetcode.com/problems/maximum-number-of-points-from-grid-queries)

<p>You are given an <code>m x n</code> integer matrix <code>grid</code> and an array <code>queries</code> of size <code>k</code>.</p>

<p>Find an array <code>answer</code> of size <code>k</code> such that for each integer <code>queries[i]</code> you start in the <strong>top left</strong> cell of the matrix and repeat the following process:</p>

<ul>
	<li>If <code>queries[i]</code> is <strong>strictly</strong> greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any <strong>adjacent</strong> cell in all <code>4</code> directions: up, down, left, and right.</li>
	<li>Otherwise, you do not get any points, and you end this process.</li>
</ul>

<p>After the process, <code>answer[i]</code> is the <strong>maximum</strong> number of points you can get. <strong>Note</strong> that for each query you are allowed to visit the same cell <strong>multiple</strong> times.</p>

<p>Return <em>the resulting array</em> <code>answer</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/10/19/yetgriddrawio.png" style="width: 571px; height: 151px;" />
<pre>
<strong>Input:</strong> grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
<strong>Output:</strong> [5,8,1]
<strong>Explanation:</strong> The diagrams above show which cells we visit to get points for each query.</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/10/20/yetgriddrawio-2.png" />
<pre>
<strong>Input:</strong> grid = [[5,2,1],[1,1,2]], queries = [3]
<strong>Output:</strong> [0]
<strong>Explanation:</strong> We can not get any points because the value of the top left cell is already greater than or equal to 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 1000</code></li>
	<li><code>4 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>k == queries.length</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= grid[i][j], queries[i] &lt;= 10<sup>6</sup></code></li>
</ul>


**Companies**:
[JPMorgan](https://leetcode.com/company/jpmorgan)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Two Pointers](https://leetcode.com/tag/two-pointers), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search), [Union Find](https://leetcode.com/tag/union-find), [Sorting](https://leetcode.com/tag/sorting), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue), [Matrix](https://leetcode.com/tag/matrix)

**Similar Questions**:
* [Trapping Rain Water II (Hard)](https://leetcode.com/problems/trapping-rain-water-ii)
* [Escape the Spreading Fire (Hard)](https://leetcode.com/problems/escape-the-spreading-fire)

**Hints**:
* The queries are all given to you beforehand so you can answer them in any order you want.
* Sort the queries knowing their original order to be able to build the answer array.
* Run a BFS on the graph and answer the queries in increasing order.

## Solution 1. Offline Query + Heap

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-points-from-grid-queries
// Author: github.com/lzl124631x
// Time: O(MNlogMN)
// Space: O(MN)
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& A, vector<int>& Q) {
        int M = A.size(), N = A[0].size(), seen = 0, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<int> id(Q.size()), ans(Q.size());
        iota(begin(id), end(id), 0);
        sort(begin(id), end(id), [&](int a, int b) { return Q[a] < Q[b]; });
        typedef array<int, 3> Node;
        A[0][0] = -A[0][0];
        priority_queue<Node> pq;
        pq.push({A[0][0], 0, 0});
        for (int i = 0; i < Q.size(); ++i) {
            int q = Q[id[i]];
            while (pq.size()) {
                auto [val, x, y] = pq.top();
                if (-val >= q) break;
                pq.pop();
                ++seen;
                for (auto &[dx, dy] : dirs) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] < 0) continue;
                    A[a][b] = -A[a][b];
                    pq.push({A[a][b], a, b});
                }
            }
            ans[id[i]] = seen;
        }
        return ans;
    }
};
```