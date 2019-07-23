# [1162. As Far from Land as Possible (Medium)](https://leetcode.com/problems/as-far-from-land-as-possible/)

<p>Given an N x N <code>grid</code>&nbsp;containing only values <code>0</code> and <code>1</code>, where&nbsp;<code>0</code> represents water&nbsp;and <code>1</code> represents land, find a water cell such that its distance to the nearest land cell is maximized and return the distance.</p>

<p>The distance used in this problem is the <em>Manhattan distance</em>:&nbsp;the distance between two cells <code>(x0, y0)</code> and <code>(x1, y1)</code> is <code>|x0 - x1| + |y0 - y1|</code>.</p>

<p>If no land or water exists in the grid, return <code>-1</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/05/03/1336_ex1.JPG" style="width: 185px; height: 87px;"></strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[[1,0,1],[0,0,0],[1,0,1]]</span>
<strong>Output: </strong><span id="example-output-1">2</span>
<strong>Explanation: </strong>
The cell (1, 1) is as far as possible from all the land with distance 2.
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/05/03/1336_ex2.JPG" style="width: 184px; height: 87px;"></strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[[1,0,0],[0,0,0],[0,0,0]]</span>
<strong>Output: </strong><span id="example-output-2">4</span>
<strong>Explanation: </strong>
The cell (2, 2) is as far as possible from all the land with distance 4.
</pre>

<p>&nbsp;</p>

<p><span><strong>Note:</strong></span></p>

<ol>
	<li><span><code>1 &lt;= grid.length == grid[0].length&nbsp;&lt;= 100</code></span></li>
	<li><span><code>grid[i][j]</code>&nbsp;is <code>0</code> or <code>1</code></span></li>
</ol>


**Companies**:  
[Uipath](https://leetcode.com/company/uipath)

**Related Topics**:  
[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [Shortest Distance from All Buildings (Hard)](https://leetcode.com/problems/shortest-distance-from-all-buildings/)

## Solution 1. Brute Force

For each water cell, compute its minimal distance to all lands. The maximum of those minimal distances is the answer.

Note that if `dist` is already smaller than or equal to the current best answer `ans`, this cell should be skipped because it can't yield better result (`if (dist <= ans) break;`).

```cpp
// OJ: https://leetcode.com/problems/as-far-from-land-as-possible/
// Author: github.com/lzl124631x
// Time: O(MNL) where grid is of size M*N and L is the count of lands.
// Space: O(L)
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<pair<int, int>> lands;
        int M = grid.size(), N = grid[0].size(), ans = -1;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) lands.emplace_back(i, j);
            }
        }
        if (lands.empty() || M * N == lands.size()) return -1;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) continue;
                int dist = INT_MAX;
                for (auto &p : lands) {
                    int d = abs(p.first - i) + abs(p.second - j);
                    dist = min(dist, d);
                    if (dist <= ans) break;
                }
                ans = max(ans, dist);
            }
        }
        return ans;
    }
};
```

## Solution 2. BFS

Starts from lands, do BFS layer by layer. The maximum layer number you get is the answer.

```cpp
// OJ: https://leetcode.com/problems/as-far-from-land-as-possible/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int M = grid.size(), N = grid[0].size(), ans = -1;
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) q.emplace(i, j);
            }
        }
        if (q.empty() || M * N == q.size()) return -1;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto p = q.front();
                q.pop();
                for (auto &dir : dirs) {
                    int x = p.first + dir[0], y = p.second + dir[1];
                    if (x < 0 || x >= M || y < 0 || y >= N || grid[x][y]) continue;
                    q.emplace(x, y);
                    grid[x][y] = 1;
                }
            }
            ++ans;
        }
        return ans;
    }
};
```