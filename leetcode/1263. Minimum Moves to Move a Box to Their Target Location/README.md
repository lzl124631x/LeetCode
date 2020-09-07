# [1263. Minimum Moves to Move a Box to Their Target Location (Hard)](https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/)

<p>Storekeeper is a&nbsp;game&nbsp;in which the player pushes boxes around in a warehouse&nbsp;trying to get them to target locations.</p>

<p>The game is represented by a <code>grid</code> of size&nbsp;<code>m x n</code>, where each element is a wall, floor, or a box.</p>

<p>Your task is move the box <code>'B'</code> to the target position <code>'T'</code> under the following rules:</p>

<ul>
	<li>Player is represented by character <code>'S'</code>&nbsp;and&nbsp;can move up, down, left, right in the <code>grid</code> if it is a floor (empy cell).</li>
	<li>Floor is represented by character <code>'.'</code> that means free cell to walk.</li>
	<li>Wall is represented by character <code>'#'</code> that means obstacle&nbsp;&nbsp;(impossible to walk there).&nbsp;</li>
	<li>There is only one box <code>'B'</code> and one&nbsp;target cell <code>'T'</code> in the <code>grid</code>.</li>
	<li>The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a <strong>push</strong>.</li>
	<li>The player cannot walk through the box.</li>
</ul>

<p>Return the minimum number of <strong>pushes</strong> to move the box to the target. If there is no way to reach the target, return&nbsp;<code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/11/06/sample_1_1620.png" style="width: 520px; height: 386px;"></strong></p>

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
	<li><code>m ==&nbsp;grid.length</code></li>
	<li><code>n ==&nbsp;grid[i].length</code></li>
	<li><code>1 &lt;= m &lt;= 20</code></li>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>grid</code> contains only characters&nbsp;<code>'.'</code>, <code>'#'</code>,&nbsp; <code>'S'</code> , <code>'T'</code>,&nbsp;or <code>'B'</code>.</li>
	<li>There is only one character&nbsp;<code>'S'</code>, <code>'B'</code>&nbsp;<font face="sans-serif, Arial, Verdana, Trebuchet MS">and&nbsp;</font><code>'T'</code>&nbsp;in the <code>grid</code>.</li>
</ul>


**Related Topics**:  
[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. BFS + DP

`dp[sx][sy][bx][by]` is the minimal number of pushes needed to make `S` at `(sx, sy)` and `B` at `(bx, by)`.

```cpp
// OJ: https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/
// Author: github.com/lzl124631x
// Time: O((MN)^2)
// Space: O((MN)^2)
class Solution {
public:
    int minPushBox(vector<vector<char>>& G) {
        int dp[20][20][20][20] = {}, M = G.size(), N = G[0].size(), sx, sy, bx, by, tx, ty, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}, ans = INT_MAX;
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (G[i][j] == 'S') sx = i, sy = j;
                else if (G[i][j] == 'B') bx = i, by = j;
                else if (G[i][j] == 'T') tx = i, ty = j;
            }
        }
        queue<vector<int>> q;
        q.push({ sx, sy, bx, by, 0 });
        dp[sx][sy][bx][by] = 0;
        while (q.size()) {
            auto v = q.front();
            q.pop();
            int sx = v[0], sy = v[1], bx = v[2], by = v[3], push = v[4];
            if (bx == tx && by == ty) ans = min(ans, push);
            for (auto [dx, dy] : dirs) {
                int x = sx + dx, y = sy + dy;
                if (x < 0 || y < 0 || x >= M || y >= N || G[x][y] == '#') continue;
                int bx2 = bx, by2 = by, push2 = push;
                if (x == bx && y == by) bx2 += dx, by2 += dy, ++push2;
                if (bx2 < 0 || by2 < 0 || bx2 >= M || by2 >= N || G[bx2][by2] == '#' || push2 >= dp[x][y][bx2][by2]) continue;
                dp[x][y][bx2][by2] = push2;
                q.push({ x, y, bx2, by2, push2 });
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
```