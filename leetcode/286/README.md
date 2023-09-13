# [286. Walls and Gates (Medium)](https://leetcode.com/problems/walls-and-gates/)

<p>You are given an <code>m x n</code> grid <code>rooms</code>&nbsp;initialized with these three possible values.</p>

<ul>
	<li><code>-1</code>&nbsp;A wall or an obstacle.</li>
	<li><code>0</code> A gate.</li>
	<li><code>INF</code> Infinity means an empty room. We use the value <code>2<sup>31</sup> - 1 = 2147483647</code> to represent <code>INF</code> as you may assume that the distance to a gate is less than <code>2147483647</code>.</li>
</ul>

<p>Fill each empty room with the distance to <em>its nearest gate</em>. If it is impossible to reach a gate, it should be filled with <code>INF</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/03/grid.jpg" style="width: 500px; height: 223px;">
<pre><strong>Input:</strong> rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
<strong>Output:</strong> [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> rooms = [[-1]]
<strong>Output:</strong> [[-1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == rooms.length</code></li>
	<li><code>n == rooms[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 250</code></li>
	<li><code>rooms[i][j]</code> is <code>-1</code>, <code>0</code>, or <code>2<sup>31</sup> - 1</code>.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [DoorDash](https://leetcode.com/company/doordash), [Amazon](https://leetcode.com/company/amazon), [Uber](https://leetcode.com/company/uber), [Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Surrounded Regions (Medium)](https://leetcode.com/problems/surrounded-regions/)
* [Number of Islands (Medium)](https://leetcode.com/problems/number-of-islands/)
* [Shortest Distance from All Buildings (Hard)](https://leetcode.com/problems/shortest-distance-from-all-buildings/)
* [Robot Room Cleaner (Hard)](https://leetcode.com/problems/robot-room-cleaner/)
* [Rotting Oranges (Medium)](https://leetcode.com/problems/rotting-oranges/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/walls-and-gates/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& A) {
       int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}; 
        queue<pair<int, int>> q;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 0) q.emplace(i, j);
            }
        }
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto &[dx, dy] : dirs) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || b < 0 || a >= M || b >= N || A[a][b] <= A[x][y] + 1) continue; 
                    A[a][b] = A[x][y] + 1;
                    q.emplace(a, b);
                }
            }
        }
    }
};
```