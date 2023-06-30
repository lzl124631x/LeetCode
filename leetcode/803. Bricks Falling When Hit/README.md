# [803. Bricks Falling When Hit (Hard)](https://leetcode.com/problems/bricks-falling-when-hit)

<p>You are given an <code>m x n</code> binary <code>grid</code>, where each <code>1</code> represents a brick and <code>0</code> represents an empty space. A brick is <strong>stable</strong> if:</p>

<ul>
	<li>It is directly connected to the top of the grid, or</li>
	<li>At least one other brick in its four adjacent cells is <strong>stable</strong>.</li>
</ul>

<p>You are also given an array <code>hits</code>, which is a sequence of erasures we want to apply. Each time we want to erase the brick at the location <code>hits[i] = (row<sub>i</sub>, col<sub>i</sub>)</code>. The brick on that location&nbsp;(if it exists) will disappear. Some other bricks may no longer be stable because of that erasure and will <strong>fall</strong>. Once a brick falls, it is <strong>immediately</strong> erased from the <code>grid</code> (i.e., it does not land on other stable bricks).</p>

<p>Return <em>an array </em><code>result</code><em>, where each </em><code>result[i]</code><em> is the number of bricks that will <strong>fall</strong> after the </em><code>i<sup>th</sup></code><em> erasure is applied.</em></p>

<p><strong>Note</strong> that an erasure may refer to a location with no brick, and if it does, no bricks drop.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
<strong>Output:</strong> [2]
<strong>Explanation: </strong>Starting with the grid:
[[1,0,0,0],
 [<u>1</u>,1,1,0]]
We erase the underlined brick at (1,0), resulting in the grid:
[[1,0,0,0],
 [0,<u>1</u>,<u>1</u>,0]]
The two underlined bricks are no longer stable as they are no longer connected to the top nor adjacent to another stable brick, so they will fall. The resulting grid is:
[[1,0,0,0],
 [0,0,0,0]]
Hence the result is [2].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[1,0,0,0],[1,1,0,0]], hits = [[1,1],[1,0]]
<strong>Output:</strong> [0,0]
<strong>Explanation: </strong>Starting with the grid:
[[1,0,0,0],
 [1,<u>1</u>,0,0]]
We erase the underlined brick at (1,1), resulting in the grid:
[[1,0,0,0],
 [1,0,0,0]]
All remaining bricks are still stable, so no bricks fall. The grid remains the same:
[[1,0,0,0],
 [<u>1</u>,0,0,0]]
Next, we erase the underlined brick at (1,0), resulting in the grid:
[[1,0,0,0],
 [0,0,0,0]]
Once again, all remaining bricks are still stable, so no bricks fall.
Hence the result is [0,0].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>grid[i][j]</code> is <code>0</code> or <code>1</code>.</li>
	<li><code>1 &lt;= hits.length &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>hits[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i&nbsp;</sub>&lt;= m - 1</code></li>
	<li><code>0 &lt;=&nbsp;y<sub>i</sub> &lt;= n - 1</code></li>
	<li>All <code>(x<sub>i</sub>, y<sub>i</sub>)</code> are unique.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Union Find](https://leetcode.com/tag/union-find/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Last Day Where You Can Still Cross (Hard)](https://leetcode.com/problems/last-day-where-you-can-still-cross/)
* [Number of Ways to Build Sturdy Brick Wall (Hard)](https://leetcode.com/problems/number-of-ways-to-build-sturdy-brick-wall/)

## Solution 1. Union Find + Back in Time

It's related to graph component connection, so we can think of DFS/BFS/Union Find. Since we are breaking the connections gradually, we can use Union Find with "Back in Time". Traverse the hits in reverse order and connect the bricks gradually.

```cpp
// OJ: https://leetcode.com/problems/bricks-falling-when-hit
// Author: github.com/lzl124631x
// Time: O((MN + H) * log(MN))
// Space: O(MN)
class UnionFind {
    vector<int> id, size;
public:
    UnionFind(int n) : id(n), size(n, 1) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    void connect(int a, int b) {
        int p = find(a), q = find(b);
        if (p == q) return;
        id[p] = q;
        size[q] += size[p];
    }
    int getSize(int a) {
        return size[find(a)];
    }
};
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& G, vector<vector<int>>& H) {
        int M = G.size(), N = G[0].size(), wall = M * N, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        UnionFind uf(M * N + 1);
        for (auto &h : H) {
            if (G[h[0]][h[1]] == 1) G[h[0]][h[1]] = 2; // replace brick with 2
        }
        for (int j = 0; j < N; ++j) {
            if (G[0][j] == 1) uf.connect(j, wall); // connect the bricks in the first row with the wall
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (G[i][j] != 1) continue;
                for (auto &[dx, dy] : dirs) {
                    int a = i + dx, b = j + dy;
                    if (a < 0 || a >= M || b < 0 || b >= N || G[a][b] != 1) continue;
                    uf.connect(i * N + j, a * N + b); // group 1's together
                }
            }
        }
        vector<int> ans(H.size());
        int cnt = uf.getSize(wall);
        for (int i = H.size() - 1; i >= 0; --i) {
            int x = H[i][0], y = H[i][1];
            if (G[x][y] == 0) continue; // if the hit place has no brick, there is no effect, skip.
            G[x][y] = 1; // recover brick
            if (x == 0) uf.connect(wall, y); // if this brick is in the first row, connect it to the wall
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= M || b < 0 || b >= N || G[a][b] != 1) continue;
                uf.connect(x * N + y, a * N + b); // connect this recovered brick with surrounding bricks.
            }
            if (uf.connected(wall, x * N + y)) ans[i] = uf.getSize(wall) - cnt - 1;
            // if this recovered brick is now connected to the wall, the number of fallen bricks is {#new stable bricks} - {#old stable bricks} - 1.
            // if this recovered brick is still not connected to the wall, this hit takes no effect. This recovered brick must be fallen already (by an earlier hit) when this cell gets hit.
            cnt = uf.getSize(wall);
        }
        return ans;
    }
};
```