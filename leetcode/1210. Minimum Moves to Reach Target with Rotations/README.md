# [1210. Minimum Moves to Reach Target with Rotations (Hard)](https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/)

<p>In an&nbsp;<code>n*n</code>&nbsp;grid, there is a snake that spans 2 cells and starts moving from the top left corner at <code>(0, 0)</code> and <code>(0, 1)</code>. The grid has empty cells represented by zeros and blocked cells represented by ones. The snake wants to reach the lower right corner at&nbsp;<code>(n-1, n-2)</code>&nbsp;and&nbsp;<code>(n-1, n-1)</code>.</p>

<p>In one move the snake can:</p>

<ul>
	<li>Move one cell to the right&nbsp;if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.</li>
	<li>Move down one cell&nbsp;if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.</li>
	<li>Rotate clockwise if it's in a horizontal position and the two cells under it are both empty. In that case the snake moves from&nbsp;<code>(r, c)</code>&nbsp;and&nbsp;<code>(r, c+1)</code>&nbsp;to&nbsp;<code>(r, c)</code>&nbsp;and&nbsp;<code>(r+1, c)</code>.<br>
	<img alt="" src="https://assets.leetcode.com/uploads/2019/09/24/image-2.png" style="width: 300px; height: 134px;"></li>
	<li>Rotate counterclockwise&nbsp;if it's in a vertical position and the two cells to its right are both empty. In that case the snake moves from&nbsp;<code>(r, c)</code>&nbsp;and&nbsp;<code>(r+1, c)</code>&nbsp;to&nbsp;<code>(r, c)</code>&nbsp;and&nbsp;<code>(r, c+1)</code>.<br>
	<img alt="" src="https://assets.leetcode.com/uploads/2019/09/24/image-1.png" style="width: 300px; height: 121px;"></li>
</ul>

<p>Return the minimum number of moves to reach the target.</p>

<p>If there is no way to reach the target, return&nbsp;<code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/09/24/image.png" style="width: 400px; height: 439px;"></strong></p>

<pre><strong>Input:</strong> grid = [[0,0,0,0,0,1],
               [1,1,0,0,1,0],
&nbsp;              [0,0,0,0,1,1],
&nbsp;              [0,0,1,0,1,0],
&nbsp;              [0,1,1,0,0,0],
&nbsp;              [0,1,1,0,0,0]]
<strong>Output:</strong> 11
<strong>Explanation:
</strong>One possible solution is [right, right, rotate clockwise, right, down, down, down, down, rotate counterclockwise, right, down].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[0,0,1,1,1,1],
&nbsp;              [0,0,0,0,1,1],
&nbsp;              [1,1,0,0,0,1],
&nbsp;              [1,1,1,0,0,1],
&nbsp;              [1,1,1,0,0,1],
&nbsp;              [1,1,1,0,0,0]]
<strong>Output:</strong> 9
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 1</code></li>
	<li>It is guaranteed that the snake starts at empty cells.</li>
</ul>


**Related Topics**:  
[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. BFS

Since we are looking for the shortest path, BFS is our first option.

```cpp
// OJ: https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int minimumMoves(vector<vector<int>>& G) {
        queue<int> q;
        q.push(0);
        unordered_set<int> seen;
        seen.insert(0);
        int step = 0, N = G.size();
        auto safe = [&](int p) {
            int y = p % 1000, x = p / 1000 % 1000, dir = p / 1000000;
            if (x < 0 || y < 0 || x >= N || y >= N || G[x][y] == 1) return false;
            return (dir == 0 && y + 1 < N && G[x][y + 1] == 0)
                || (dir == 1 && x + 1 < N && G[x + 1][y] == 0);
        };
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                int p = q.front(), y = p % 1000, x = p / 1000 % 1000, dir = p / 1000000;
                if (x == N - 1 && y == N - 2) return step;
                q.pop();
                // move right
                int r = p + 1;
                if (seen.count(r) == 0 && safe(r)) {
                    seen.insert(r);
                    q.push(r);
                }
                // move down
                int d = p + 1000;
                if (seen.count(d) == 0 && safe(d)) {
                    seen.insert(d);
                    q.push(d);
                }
                // rotate closewise
                if (dir == 0) {
                    int p2 = 1000000 + x * 1000 + y, cx = x + 1, cy = y + 1;
                    if (seen.count(p2) || !safe(p2) || cx < 0 || cy < 0 || cx >= N || cy >= N || G[cx][cy] == 1) continue;
                    seen.insert(p2);
                    q.push(p2);
                }
                // rotate counterclosewise
                if (dir == 1) {
                    int p2 = x * 1000 + y, cx = x + 1, cy = y + 1;
                    if (seen.count(p2) || !safe(p2) || cx < 0 || cy < 0 || cx >= N || cy >= N || G[cx][cy] == 1) continue;
                    seen.insert(p2);
                    q.push(p2);
                }
            }
            ++step;
        }
        return -1;
    }
};
```