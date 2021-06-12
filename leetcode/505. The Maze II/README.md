# [505. The Maze II (Medium)](https://leetcode.com/problems/the-maze-ii/)

<p>There is a ball in a <code>maze</code> with empty spaces (represented as <code>0</code>) and walls (represented as <code>1</code>). The ball can go through the empty spaces by rolling <strong>up, down, left or right</strong>, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.</p>

<p>Given the <code>m x n</code> <code>maze</code>, the ball's <code>start</code> position and the <code>destination</code>, where <code>start = [start<sub>row</sub>, start<sub>col</sub>]</code> and <code>destination = [destination<sub>row</sub>, destination<sub>col</sub>]</code>, return <em>the shortest <strong>distance</strong> for the ball to stop at the destination</em>. If the ball cannot stop at <code>destination</code>, return <code>-1</code>.</p>

<p>The <strong>distance</strong> is the number of <strong>empty spaces</strong> traveled by the ball from the start position (excluded) to the destination (included).</p>

<p>You may assume that <strong>the borders of the maze are all walls</strong> (see examples).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/31/maze1-1-grid.jpg" style="width: 573px; height: 573px;">
<pre><strong>Input:</strong> maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
<strong>Output:</strong> 12
<strong>Explanation:</strong> One possible way is : left -&gt; down -&gt; left -&gt; down -&gt; right -&gt; down -&gt; right.
The length of the path is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/31/maze1-2-grid.jpg" style="width: 573px; height: 573px;">
<pre><strong>Input:</strong> maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == maze.length</code></li>
	<li><code>n == maze[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>maze[i][j]</code> is <code>0</code> or <code>1</code>.</li>
	<li><code>start.length == 2</code></li>
	<li><code>destination.length == 2</code></li>
	<li><code>0 &lt;= start<sub>row</sub>, destination<sub>row</sub> &lt;= m</code></li>
	<li><code>0 &lt;= start<sub>col</sub>, destination<sub>col</sub> &lt;= n</code></li>
	<li>Both the ball and the destination exist in an empty space, and they will not be in the same position initially.</li>
	<li>The maze contains <strong>at least 2 empty spaces</strong>.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Snapchat](https://leetcode.com/company/snapchat), [Oracle](https://leetcode.com/company/oracle)

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [The Maze (Medium)](https://leetcode.com/problems/the-maze/)
* [The Maze III (Hard)](https://leetcode.com/problems/the-maze-iii/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/the-maze-ii/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int shortestDistance(vector<vector<int>>& A, vector<int>& S, vector<int>& E) {
        int M = A.size(), N = A[0].size();
        vector<vector<vector<int>>> dp(M, vector<vector<int>>(N, vector<int>(4, -1)));
        queue<tuple<int, int, int>> q;
        int step = 0, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for (int i = 0; i < 4; ++i) {
            q.emplace(S[0], S[1], i);
            dp[S[0]][S[1]][i] = 0;
        }
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [x, y, dir] = q.front();
                q.pop();
                auto [dx, dy] = dirs[dir];
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= M || ny < 0 || ny >= N || A[nx][ny] == 1) {
                    if (x == E[0] && y == E[1]) return step;
                    for (int d = 0; d < 4; ++d) {
                        if (d == dir) continue;
                        auto [dx2, dy2] = dirs[d];
                        nx = x + dx2, ny = y + dy2;
                        if (nx < 0 || nx >= M || ny < 0 || ny >= N || A[nx][ny] == 1 || dp[nx][ny][d] != -1) continue;
                        dp[nx][ny][d] = step;
                        q.emplace(nx, ny, d);
                    }
                } else if (dp[nx][ny][dir] == -1) {
                    dp[nx][ny][dir] = step;
                    q.emplace(nx, ny, dir);
                }
            }
            ++step;
        }
        return -1;
    }
};
```