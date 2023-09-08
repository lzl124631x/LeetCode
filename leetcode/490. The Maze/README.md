# [490. The Maze (Medium)](https://leetcode.com/problems/the-maze)

<p>There is a ball in a <code>maze</code> with empty spaces (represented as <code>0</code>) and walls (represented as <code>1</code>). The ball can go through the empty spaces by rolling <strong>up, down, left or right</strong>, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.</p>
<p>Given the <code>m x n</code> <code>maze</code>, the ball's <code>start</code> position and the <code>destination</code>, where <code>start = [start<sub>row</sub>, start<sub>col</sub>]</code> and <code>destination = [destination<sub>row</sub>, destination<sub>col</sub>]</code>, return <code>true</code> if the ball can stop at the destination, otherwise return <code>false</code>.</p>
<p>You may assume that <strong>the borders of the maze are all walls</strong> (see examples).</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/31/maze1-1-grid.jpg" style="width: 573px; height: 573px;">
<pre><strong>Input:</strong> maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
<strong>Output:</strong> true
<strong>Explanation:</strong> One possible way is : left -&gt; down -&gt; left -&gt; down -&gt; right -&gt; down -&gt; right.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/31/maze1-2-grid.jpg" style="width: 573px; height: 573px;">
<pre><strong>Input:</strong> maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
<strong>Output:</strong> false
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
[Facebook](https://leetcode.com/company/facebook), [TikTok](https://leetcode.com/company/tiktok), [Square](https://leetcode.com/company/square)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [The Maze III (Hard)](https://leetcode.com/problems/the-maze-iii/)
* [The Maze II (Medium)](https://leetcode.com/problems/the-maze-ii/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/the-maze/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    bool hasPath(vector<vector<int>>& A, vector<int>& start, vector<int>& dest) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<bool>> seen(M, vector<bool>(N));
        queue<pair<int, int>> q{{{start[0], start[1]}}};
        seen[start[0]][start[1]] = true;
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == dest[0] && y == dest[1]) return true;
            for (auto &[dx, dy] : dirs) {
                int a = x, b = y;
                while (a >= 0 && a < M && b >= 0 && b < N && A[a][b] != 1) a += dx, b += dy;
                a -= dx, b -= dy;
                if ((a == x && b == y) || seen[a][b]) continue;
                seen[a][b] = true;
                q.emplace(a, b);
            }
        }
        return false;
    }
};
```