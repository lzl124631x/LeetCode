# [778. Swim in Rising Water (Hard)](https://leetcode.com/problems/swim-in-rising-water/)

<p>On an N x N <code>grid</code>, each square <code>grid[i][j]</code> represents the elevation at that point <code>(i,j)</code>.</p>

<p>Now rain starts to fall. At time <code>t</code>, the depth of the water everywhere is <code>t</code>. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are&nbsp;at most&nbsp;<code>t</code>. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.</p>

<p>You start at the top left square <code>(0, 0)</code>. What is the least time until you can reach the bottom right square <code>(N-1, N-1)</code>?</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [[0,2],[1,3]]
<strong>Output:</strong> 3
<strong>Explanation:</strong>
At time <code>0</code>, you are in grid location <code>(0, 0)</code>.
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

You cannot reach point <code>(1, 1)</code> until time <code>3</code>.
When the depth of water is <code>3</code>, we can swim anywhere inside the grid.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
<strong>Output:</strong> 16
<strong>Explanation:</strong>
<strong> 0  1  2  3  4</strong>
24 23 22 21  <strong>5</strong>
<strong>12 13 14 15 16</strong>
<strong>11</strong> 17 18 19 20
<strong>10  9  8  7  6</strong>

The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
</pre>

<p><strong>Note:</strong></p>

<ol>
	<li><code>2 &lt;= N &lt;= 50</code>.</li>
	<li>grid[i][j] is a permutation of [0, ..., N*N - 1].</li>
</ol>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Heap](https://leetcode.com/tag/heap/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Union Find](https://leetcode.com/tag/union-find/)

## Solution 1. Binary Answer

```cpp
// OJ: https://leetcode.com/problems/swim-in-rising-water/
// Author: github.com/lzl124631x
// Time: O(N^2 * logN)
// Space: O(N^2)
class Solution {
    int N, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<bool>> seen;
    bool dfs(vector<vector<int>> &G, int x, int y, int height) {
        if (G[x][y] > height) return false;
        if (x == N - 1 && y == N - 1) return true;
        seen[x][y] = true;
        for (auto &[dx, dy] : dirs) {
            int a = x + dx, b = y + dy;
            if (a < 0 || a >= N || b < 0 || b >= N || seen[a][b]) continue;
            if (dfs(G, a, b, height)) return true;
        }
        return false;
    }
    bool valid(vector<vector<int>>& G, int height) {
        seen.assign(N, vector<bool>(N, false));
        return dfs(G, 0, 0, height);
    }
public:
    int swimInWater(vector<vector<int>>& G) {
        N = G.size();
        int L = 0, R = N * N - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(G, M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};
```

## Solution 2. Heap

```cpp
// OJ: https://leetcode.com/problems/swim-in-rising-water/
// Author: github.com/lzl124631x
// Time: O(N^2 * logN)
// Space: O(N^2)
class Solution {
    typedef tuple<int, int, int> Point; // height, x, y
public:
    int swimInWater(vector<vector<int>>& G) {
        priority_queue<Point, vector<Point>, greater<>> pq;
        pq.emplace(G[0][0], 0, 0);
        int ans = 0, N = G.size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while (true) {
            auto [height, x, y] = pq.top();
            pq.pop();
            ans = max(ans, height);
            if (x == N - 1 && y == N- 1) return ans;
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= N || b < 0 || b >= N || G[a][b] == -1) continue;
                pq.emplace(G[a][b], a, b);
                G[a][b] = -1;
            }
        }
    }
};
```