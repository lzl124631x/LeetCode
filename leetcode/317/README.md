# [317. Shortest Distance from All Buildings (Hard)](https://leetcode.com/problems/shortest-distance-from-all-buildings/)

<p>You are given an <code>m x n</code> grid <code>grid</code> of values <code>0</code>, <code>1</code>, or <code>2</code>, where:</p>

<ul>
	<li>each <code>0</code> marks <strong>an empty land</strong> that you can pass by freely,</li>
	<li>each <code>1</code> marks <strong>a building</strong> that you cannot pass through, and</li>
	<li>each <code>2</code> marks <strong>an obstacle</strong> that you cannot pass through.</li>
</ul>

<p>You want to build a house on an empty land that reaches all buildings in the <strong>shortest total travel</strong> distance. You can only move up, down, left, and right.</p>

<p>Return <em>the <strong>shortest travel distance</strong> for such a house</em>. If it is not possible to build such a house according to the above rules, return <code>-1</code>.</p>

<p>The <strong>total travel distance</strong> is the sum of the distances between the houses of the friends and the meeting point.</p>

<p>The distance is calculated using <a href="http://en.wikipedia.org/wiki/Taxicab_geometry" target="_blank">Manhattan Distance</a>, where <code>distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/buildings-grid.jpg" style="width: 413px; height: 253px;">
<pre><strong>Input:</strong> grid = [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2).
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal.
So return 7.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[1,0]]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [[1]]
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>grid[i][j]</code> is either <code>0</code>, <code>1</code>, or <code>2</code>.</li>
	<li>There will be <strong>at least one</strong> building in the <code>grid</code>.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [DoorDash](https://leetcode.com/company/doordash), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Walls and Gates (Medium)](https://leetcode.com/problems/walls-and-gates/)
* [Best Meeting Point (Hard)](https://leetcode.com/problems/best-meeting-point/)
* [As Far from Land as Possible (Medium)](https://leetcode.com/problems/as-far-from-land-as-possible/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/shortest-distance-from-all-buildings/
// Author: github.com/lzl124631x
// Time: O(LMN) where `L` is the number of ones
// Space: O(MN)
class Solution {
    int M, N;
    void updateDistance(vector<vector<int>> &A, int x, int y, vector<vector<int>> &B) {
        queue<pair<int, int>> q;
        q.emplace(x, y);
        vector<vector<bool>> seen(M, vector<bool>(N));
        int step = 0, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}, cnt = 0;
        while (q.size()) {
            int cnt = q.size();
            ++step;
            while (cnt--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto &[dx, dy] : dirs) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || b < 0 || a >= M || b >= N || A[a][b] != 0 || seen[a][b]) continue;
                    seen[a][b] = true;
                    q.emplace(a, b);
                    if (B[a][b] != INT_MAX) B[a][b] += step;
                }
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 0 && !seen[i][j]) B[i][j] = INT_MAX;
            }
        }
    }
public:
    int shortestDistance(vector<vector<int>>& A) {
        M = A.size(), N = A[0].size();
        int ans = INT_MAX;
        vector<vector<int>> B(M, vector<int>(N)); // distance
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 1) updateDistance(A, i, j, B);
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 0) ans = min(ans, B[i][j]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};