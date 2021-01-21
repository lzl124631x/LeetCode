# [913. Cat and Mouse (Hard)](https://leetcode.com/problems/cat-and-mouse/)

<p>A game on an <strong>undirected</strong> graph is played by two players, Mouse and Cat, who alternate turns.</p>

<p>The graph is given as follows: <code>graph[a]</code> is a list of all nodes <code>b</code> such that <code>ab</code> is an edge of the graph.</p>

<p>The mouse starts at node <code>1</code> and goes first, the cat starts at node <code>2</code> and goes second, and there is a hole at node <code>0</code>.</p>

<p>During each player's turn, they <strong>must</strong> travel along one&nbsp;edge of the graph that meets where they are.&nbsp; For example, if the Mouse is at node 1, it <strong>must</strong> travel to any node in <code>graph[1]</code>.</p>

<p>Additionally, it is not allowed for the Cat to travel to the Hole (node 0.)</p>

<p>Then, the game can end in three&nbsp;ways:</p>

<ul>
	<li>If ever the Cat occupies the same node as the Mouse, the Cat wins.</li>
	<li>If ever the Mouse reaches the Hole, the Mouse wins.</li>
	<li>If ever a position is repeated (i.e., the players are in the same position as a previous turn, and&nbsp;it is the same player's turn to move), the game is a draw.</li>
</ul>

<p>Given a <code>graph</code>, and assuming both players play optimally, return</p>

<ul>
	<li><code>1</code>&nbsp;if the mouse wins the game,</li>
	<li><code>2</code>&nbsp;if the cat wins the game, or</li>
	<li><code>0</code>&nbsp;if the game is a draw.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/17/cat1.jpg" style="width: 300px; height: 300px;">
<pre><strong>Input:</strong> graph = [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
<strong>Output:</strong> 0
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/17/cat2.jpg" style="width: 200px; height: 200px;">
<pre><strong>Input:</strong> graph = [[1,3],[0],[3],[0,2]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= graph.length &lt;= 50</code></li>
	<li><code>1&nbsp;&lt;= graph[i].length &lt; graph.length</code></li>
	<li><code>0 &lt;= graph[i][j] &lt; graph.length</code></li>
	<li><code>graph[i][j] != i</code></li>
	<li><code>graph[i]</code> is unique.</li>
	<li>The mouse and the cat can always move.&nbsp;</li>
</ul>


**Related Topics**:  
[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/), [Minimax](https://leetcode.com/tag/minimax/)

**Similar Questions**:
* [Cat and Mouse II (Hard)](https://leetcode.com/problems/cat-and-mouse-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/cat-and-mouse/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
    vector<array<int, 3>> parents(vector<vector<int>> &G, int m, int c, int t) {
        vector<array<int, 3>> ans;
        if (t == 2) {
            for (int m2 : G[m]) ans.push_back({m2, c, 3 - t});
        } else {
            for (int c2 : G[c]) {
                if (c2 > 0) ans.push_back({m, c2, 3 - t});
            }
        }
        return ans;
    }
public:
    int catMouseGame(vector<vector<int>>& G) {
        int N = G.size(), DRAW = 0, MOUSE = 1, CAT = 2;
        int color[50][50][3] = {}, degree[50][50][3] = {};
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                degree[i][j][1] = G[i].size();
                degree[i][j][2] = G[j].size();
                for (int v : G[j]) {
                    if (v == 0) {
                        degree[i][j][2]--;
                        break;
                    }
                }
            }
        }
        queue<array<int, 4>> q;
        for (int i = 0; i < N; ++i) {
            for (int t = 1; t <= 2; ++t) {
                color[0][i][t] = MOUSE;
                q.push({0, i, t, MOUSE});
                if (i > 0) {
                    color[i][i][t] = CAT;
                    q.push({i, i, t, CAT});
                }
            }
        }
        while (q.size()) {
            auto [i, j, t, c] = q.front();
            q.pop();
            for (auto [i2, j2, t2] : parents(G, i, j, t)) {
                if (color[i2][j2][t2] == DRAW) {
                    if (t2 == c) {
                        color[i2][j2][t2] = c;
                        q.push({i2, j2, t2, c});
                    } else if (--degree[i2][j2][t2] == 0) {
                        color[i2][j2][t2] = 3 - t2;
                        q.push({i2, j2, t2, 3 - t2});
                    }
                }
            }
        }
        return color[1][2][1];
    }
};
```