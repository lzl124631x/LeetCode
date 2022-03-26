# [499. The Maze III (Hard)](https://leetcode.com/problems/the-maze-iii/)

<p>There is a ball in a <code>maze</code> with empty spaces (represented as <code>0</code>) and walls (represented as <code>1</code>). The ball can go through the empty spaces by rolling <strong>up, down, left or right</strong>, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction. There is also a hole in this maze. The ball will drop into the hole if it rolls onto the hole.</p>

<p>Given the <code>m x n</code> <code>maze</code>, the ball's position <code>ball</code> and the hole's position <code>hole</code>, where <code>ball = [ball<sub>row</sub>, ball<sub>col</sub>]</code> and <code>hole = [hole<sub>row</sub>, hole<sub>col</sub>]</code>, return <em>a string </em><code>instructions</code><em> of all the instructions that the ball should follow to drop in the hole with the <strong>shortest distance</strong> possible</em>. If there are multiple valid instructions, return the <strong>lexicographically minimum</strong> one. If the ball can't drop in the hole, return <code>"impossible"</code>.</p>

<p>If there is a way for the ball to drop in the hole, the answer <code>instructions</code> should contain the characters <code>'u'</code> (i.e., up), <code>'d'</code> (i.e., down), <code>'l'</code> (i.e., left), and <code>'r'</code> (i.e., right).</p>

<p>The <strong>distance</strong> is the number of <strong>empty spaces</strong> traveled by the ball from the start position (excluded) to the destination (included).</p>

<p>You may assume that <strong>the borders of the maze are all walls</strong> (see examples).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/31/maze3-1-grid.jpg" style="width: 573px; height: 573px;">
<pre><strong>Input:</strong> maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], ball = [4,3], hole = [0,1]
<strong>Output:</strong> "lul"
<strong>Explanation:</strong> There are two shortest ways for the ball to drop into the hole.
The first way is left -&gt; up -&gt; left, represented by "lul".
The second way is up -&gt; left, represented by 'ul'.
Both ways have shortest distance 6, but the first way is lexicographically smaller because 'l' &lt; 'u'. So the output is "lul".
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/31/maze3-2-grid.jpg" style="width: 573px; height: 573px;">
<pre><strong>Input:</strong> maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], ball = [4,3], hole = [3,0]
<strong>Output:</strong> "impossible"
<strong>Explanation:</strong> The ball cannot reach the hole.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> maze = [[0,0,0,0,0,0,0],[0,0,1,0,0,1,0],[0,0,0,0,1,0,0],[0,0,0,0,0,0,1]], ball = [0,4], hole = [3,5]
<strong>Output:</strong> "dldr"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == maze.length</code></li>
	<li><code>n == maze[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>maze[i][j]</code> is <code>0</code> or <code>1</code>.</li>
	<li><code>ball.length == 2</code></li>
	<li><code>hole.length == 2</code></li>
	<li><code>0 &lt;= ball<sub>row</sub>, hole<sub>row</sub> &lt;= m</code></li>
	<li><code>0 &lt;= ball<sub>col</sub>, hole<sub>col</sub> &lt;= n</code></li>
	<li>Both the ball and the hole exist in an empty space, and they will not be in the same position initially.</li>
	<li>The maze contains <strong>at least 2 empty spaces</strong>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Shortest Path](https://leetcode.com/tag/shortest-path/)

**Similar Questions**:
* [The Maze (Medium)](https://leetcode.com/problems/the-maze/)
* [The Maze II (Medium)](https://leetcode.com/problems/the-maze-ii/)

## Solution 1. Dijkstra

```cpp
// OJ: https://leetcode.com/problems/the-maze-iii/
// Author: github.com/lzl124631x
// Time: O((MN)^2log(MN))
// Space: O((MN)^2)
class Solution {
    typedef tuple<int, string, int, int> item; // distance, instruction, x, y
public:
    string findShortestWay(vector<vector<int>>& A, vector<int>& ball, vector<int>& hole) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{1,0},{0,-1},{0,1},{-1,0}};
        string chars = "dlru";
        vector<vector<int>> dist(M, vector<int>(N, INT_MAX));
        dist[ball[0]][ball[1]] = 0;
        vector<vector<string>> ins(M, vector<string>(N));
        priority_queue<item, vector<item>, greater<>> pq;
        pq.push({0, "", ball[0], ball[1]});
        while (pq.size()) {
            auto [cost, inst, x, y] = pq.top();
            pq.pop();
            if (x == hole[0] && y == hole[1]) return inst;
            if (cost > dist[x][y]) continue;
            for (int i = 0; i < 4; ++i) {
                auto [dx, dy] = dirs[i];
                int a = x + dx, b = y + dy, step = 1;
                while (a >= 0 && a < M && b >= 0 && b < N && A[a][b] == 0 && (a != hole[0] || b != hole[1])) a += dx, b += dy, ++step;
                if (a != hole[0] || b != hole[1]) a -= dx, b -= dy, --step;
                if (a == x && b == y) continue;
                int newCost = cost + step;
                auto newInst = inst + chars[i];
                if (dist[a][b] > newCost) {
                    dist[a][b] = newCost;
                    ins[a][b] = newInst;
                    pq.push({newCost, newInst, a, b});
                } else if (dist[a][b] == newCost && (ins[a][b].empty() || newInst < ins[a][b])) {
                    ins[a][b] = newInst;
                    pq.push({newCost, newInst, a, b});
                } 
            }
        }
        return "impossible";
    }
};
```