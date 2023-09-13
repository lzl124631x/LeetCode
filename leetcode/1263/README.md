# [1263. Minimum Moves to Move a Box to Their Target Location (Hard)](https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/)

<p>A storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to target locations.</p>

<p>The game is represented by an <code>m x n</code> grid of characters <code>grid</code> where each element is a wall, floor, or box.</p>

<p>Your task is to move the box <code>'B'</code> to the target position <code>'T'</code> under the following rules:</p>

<ul>
	<li>The character <code>'S'</code> represents the player. The player can move up, down, left, right in <code>grid</code> if it is a floor (empty cell).</li>
	<li>The character <code>'.'</code> represents the floor which means a free cell to walk.</li>
	<li>The character <code>'#' </code>represents the wall which means an obstacle (impossible to walk there).</li>
	<li>There is only one box <code>'B'</code> and one target cell <code>'T'</code> in the <code>grid</code>.</li>
	<li>The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a <strong>push</strong>.</li>
	<li>The player cannot walk through the box.</li>
</ul>

<p>Return <em>the minimum number of <strong>pushes</strong> to move the box to the target</em>. If there is no way to reach the target, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/11/06/sample_1_1620.png" style="width: 600px; height: 403px;">
<pre><strong>Input:</strong> grid = [["#","#","#","#","#","#"],
               ["#","T","#","#","#","#"],
&nbsp;              ["#",".",".","B",".","#"],
&nbsp;              ["#",".","#","#",".","#"],
&nbsp;              ["#",".",".",".","S","#"],
&nbsp;              ["#","#","#","#","#","#"]]
<strong>Output:</strong> 3
<strong>Explanation: </strong>We return only the number of times the box is pushed.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [["#","#","#","#","#","#"],
               ["#","T","#","#","#","#"],
&nbsp;              ["#",".",".","B",".","#"],
&nbsp;              ["#","#","#","#",".","#"],
&nbsp;              ["#",".",".",".","S","#"],
&nbsp;              ["#","#","#","#","#","#"]]
<strong>Output:</strong> -1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [["#","#","#","#","#","#"],
&nbsp;              ["#","T",".",".","#","#"],
&nbsp;              ["#",".","#","B",".","#"],
&nbsp;              ["#",".",".",".",".","#"],
&nbsp;              ["#",".",".",".","S","#"],
&nbsp;              ["#","#","#","#","#","#"]]
<strong>Output:</strong> 5
<strong>Explanation:</strong>  push the box down, left, left, up and up.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> grid = [["#","#","#","#","#","#","#"],
&nbsp;              ["#","S","#",".","B","T","#"],
&nbsp;              ["#","#","#","#","#","#","#"]]
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 20</code></li>
	<li><code>grid</code> contains only characters <code>'.'</code>, <code>'#'</code>, <code>'S'</code>, <code>'T'</code>, or <code>'B'</code>.</li>
	<li>There is only one character <code>'S'</code>, <code>'B'</code>, and <code>'T'</code> in the <code>grid</code>.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Matrix](https://leetcode.com/tag/matrix/)

## Solution 1. BFS + DP

`'.'` might be on the edges.

Some moves increase the step if it pushes the box while others doesn't increase the step. Since we want to minimize the moves, we need to prioritize the states with less steps, but this will also prioritize meaningless random wandering, which is not wanted.

`dp[sx][sy][bx][by]` is the minimal number of pushes needed to make `S` at `(sx, sy)` and `B` at `(bx, by)`.

```cpp
// OJ: https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/
// Author: github.com/lzl124631x
// Time: O((MN)^2)
// Space: O((MN)^2)
class Solution {
public:
    int minPushBox(vector<vector<char>>& A) {
        int M = A.size(), N = A[0].size(), tx, ty, sx, sy, bx, by, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}, dp[20][20][20][20] = {}, ans = INT_MAX;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 'S') sx = i, sy = j;
                else if (A[i][j] == 'B') bx = i, by = j;
                else if (A[i][j] == 'T') tx = i, ty = j;
            }
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[sx][sy][bx][by] = 0;
        queue<array<int, 4>> q{{{sx, sy, bx, by}}};
        while (q.size()) {
            auto [sx, sy, bx, by] = q.front();
            q.pop();
            int step = dp[sx][sy][bx][by];
            if (bx == tx && by == ty) ans = min(ans, step);
            for (auto &[dx, dy] : dirs) {
                int a = sx + dx, b = sy + dy, bx2 = bx, by2 = by, step2 = step;
                if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] == '#') continue;
                if (a == bx && b == by) bx2 += dx, by2 += dy, step2++;
                if (bx2 < 0 || bx2 >= M || by2 < 0 || by2 >= N || A[bx2][by2] == '#' || step2 >= dp[a][b][bx2][by2]) continue;
                dp[a][b][bx2][by2] = step2;
                q.push({a, b, bx2, by2});
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
```