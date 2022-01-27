# [1810. Minimum Path Cost in a Hidden Grid (Medium)](https://leetcode.com/problems/minimum-path-cost-in-a-hidden-grid/)

<p>This is an <strong>interactive problem</strong>.</p>

<p>There is a robot in a hidden grid, and you are trying to get it from its starting cell to the target cell in this grid. The grid is of size <code>m x n</code>, and each cell in the grid is either empty or blocked. It is <strong>guaranteed</strong> that the starting cell and the target cell are different, and neither of them is blocked.</p>

<p>Each cell has a <strong>cost</strong> that you need to pay each time you <strong>move</strong> to the cell. The starting cell's cost is <strong>not</strong> applied before the robot moves.</p>

<p>You want to find the minimum total cost to move the robot to the target cell. However, you <strong>do not know</strong> the grid's dimensions, the starting cell, nor the target cell. You are only allowed to ask queries to the <code>GridMaster</code> object.</p>

<p>The <code>GridMaster</code> class has the following functions:</p>

<ul>
	<li><code>boolean canMove(char direction)</code> Returns <code>true</code> if the robot can move in that direction. Otherwise, it returns <code>false</code>.</li>
	<li><code>int move(char direction)</code> Moves the robot in that direction and returns the cost of moving to that cell. If this move would move the robot to a blocked cell or off the grid, the move will be <strong>ignored</strong>, the robot will remain in the same position, and the function will return <code>-1</code>.</li>
	<li><code>boolean isTarget()</code> Returns <code>true</code> if the robot is currently on the target cell. Otherwise, it returns <code>false</code>.</li>
</ul>

<p>Note that <code>direction</code> in the above functions should be a character from <code>{'U','D','L','R'}</code>, representing the directions up, down, left, and right, respectively.</p>

<p>Return <em>the <strong>minimum total cost</strong> to get the robot from its initial starting cell to the target cell. If there is no valid path between the cells, return </em><code>-1</code>.</p>

<p><strong>Custom testing:</strong></p>

<p>The test input is read as a 2D matrix <code>grid</code> of size <code>m x n</code> and four integers <code>r1</code>, <code>c1</code>, <code>r2</code>, and <code><font face="monospace">c2</font></code> where:</p>

<ul>
	<li><code>grid[i][j] == 0</code> indicates that the cell <code>(i, j)</code> is blocked.</li>
	<li><code>grid[i][j] &gt;= 1</code> indicates that the cell <code>(i, j)</code> is empty and <code>grid[i][j]</code> is the <strong>cost</strong> to move to that cell.</li>
	<li><code>(r1, c1)</code> is the starting cell of the robot.</li>
	<li><code>(r2, c2)</code> is the target cell of the robot.</li>
</ul>

<p>Remember that you will <strong>not</strong> have this information in your code.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> grid = [[2,3],[1,1]], r1 = 0, c1 = 1, r2 = 1, c2 = 0
<strong>Output:</strong> 2
<strong>Explanation:</strong> One possible interaction is described below:
The robot is initially standing on cell (0, 1), denoted by the 3.
- master.canMove('U') returns false.
- master.canMove('D') returns true.
- master.canMove('L') returns true.
- master.canMove('R') returns false.
- master.move('L') moves the robot to the cell (0, 0) and returns 2.
- master.isTarget() returns false.
- master.canMove('U') returns false.
- master.canMove('D') returns true.
- master.canMove('L') returns false.
- master.canMove('R') returns true.
- master.move('D') moves the robot to the cell (1, 0) and returns 1.
- master.isTarget() returns true.
- master.move('L') doesn't move the robot and returns -1.
- master.move('R') moves the robot to the cell (1, 1) and returns 1.
We now know that the target is the cell (1, 0), and the minimum total cost to reach it is 2. </pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[0,3,1],[3,4,2],[1,2,0]], r1 = 2, c1 = 0, r2 = 0, c2 = 2
<strong>Output:</strong> 9
<strong>Explanation:</strong> The minimum cost path is (2,0) -&gt; (2,1) -&gt; (1,1) -&gt; (1,2) -&gt; (0,2).
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [[1,0],[0,1]], r1 = 0, c1 = 0, r2 = 1, c2 = 1
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no path from the robot to the target cell.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 100</code></li>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 100</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Interactive](https://leetcode.com/tag/interactive/)

**Similar Questions**:
* [Robot Room Cleaner (Hard)](https://leetcode.com/problems/robot-room-cleaner/)
* [Shortest Path in a Hidden Grid (Medium)](https://leetcode.com/problems/shortest-path-in-a-hidden-grid/)

## Solution 1. DFS + Dijkstra

DFS to probe the grid. Dijkstra to find the shortest path.

```cpp
// OJ: https://leetcode.com/problems/minimum-path-cost-in-a-hidden-grid/
// Author: github.com/lzl124631x
// Time: O(MNlog(MN))
// Space: O(MN)
const int maxN = 100, INF = 0x3f3f3f3f, init = maxN + 1;
class Solution {
    int grid[2 * maxN + 2][2 * maxN + 2] = {}, dist[2 * maxN + 2][2 * maxN + 2] = {}, tx = INF, ty = INF;
    tuple<char, int, int> dirs[4] = {{'U',-1,0}, {'D',1,0},{'R',0,1},{'L',0,-1}};
    void dfs(GridMaster &m, int x = init, int y = init) {
        if (m.isTarget()) tx = x, ty = y;
        for (int i = 0; i < 4; ++i) {
            auto &[dir, dx, dy] = dirs[i];
            int a = x + dx, b = y + dy;
            if (grid[a][b] != INF || !m.canMove(dir)) continue;
            grid[a][b] = m.move(dir);
            dfs(m, a, b);
            m.move(get<0>(dirs[i % 2 ? i - 1 : i + 1]));
        }
    }
public:
    int findShortestPath(GridMaster &m) {
        memset(grid, 0x3f, sizeof(grid));
        dfs(m);
        if (tx == INF) return -1;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({0, init, init});
        memset(dist, 0x3f, sizeof(dist));
        dist[init][init] = 0;
        while (pq.size()) {
            auto [d, x, y] = pq.top();
            pq.pop();
            if (d > dist[x][y]) continue;
            if (x == tx && y == ty) return d;
            for (auto &[dir, dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (grid[a][b] == INF) continue;
                int next = d + grid[a][b];
                if (next < dist[a][b]) {
                    dist[a][b] = next;
                    pq.push({ next, a, b });
                }
            }
        }
        return -1;
    }
};
```