# [305. Number of Islands II (Hard)](https://leetcode.com/problems/number-of-islands-ii)

<p>You are given an empty 2D binary grid <code>grid</code> of size <code>m x n</code>. The grid represents a map where <code>0</code>'s represent water and <code>1</code>'s represent land. Initially, all the cells of <code>grid</code> are water cells (i.e., all the cells are <code>0</code>'s).</p>

<p>We may perform an add land operation which turns the water at position into a land. You are given an array <code>positions</code> where <code>positions[i] = [r<sub>i</sub>, c<sub>i</sub>]</code> is the position <code>(r<sub>i</sub>, c<sub>i</sub>)</code> at which we should operate the <code>i<sup>th</sup></code> operation.</p>

<p>Return <em>an array of integers</em> <code>answer</code> <em>where</em> <code>answer[i]</code> <em>is the number of islands after turning the cell</em> <code>(r<sub>i</sub>, c<sub>i</sub>)</code> <em>into a land</em>.</p>

<p>An <strong>island</strong> is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/10/tmp-grid.jpg" style="width: 500px; height: 294px;">
<pre><strong>Input:</strong> m = 3, n = 3, positions = [[0,0],[0,1],[1,2],[2,1]]
<strong>Output:</strong> [1,1,2,3]
<strong>Explanation:</strong>
Initially, the 2d grid is filled with water.
- Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land. We have 1 island.
- Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land. We still have 1 island.
- Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land. We have 2 islands.
- Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land. We have 3 islands.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> m = 1, n = 1, positions = [[0,0]]
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n, positions.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>4</sup></code></li>
	<li><code>positions[i].length == 2</code></li>
	<li><code>0 &lt;= r<sub>i</sub> &lt; m</code></li>
	<li><code>0 &lt;= c<sub>i</sub> &lt; n</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you solve it in time complexity <code>O(k log(mn))</code>, where <code>k == positions.length</code>?</p>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Union Find](https://leetcode.com/tag/union-find/)

**Similar Questions**:
* [Number of Islands (Medium)](https://leetcode.com/problems/number-of-islands/)
* [Process Restricted Friend Requests (Medium)](https://leetcode.com/problems/process-restricted-friend-requests/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-islands-ii
// Author: github.com/lzl124631x
// Time: O(P * log(MN))
// Space: O(MN)
class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[y] = x; // this makes sure that after connecting, the find(a), i.e. x, is kept as the new id of the connected component.
    }
};
class Solution {
public:
    vector<int> numIslands2(int M, int N, vector<vector<int>>& A) {
        vector<vector<int>> G(M, vector<int>(N));
        UnionFind uf(M * N);
        unordered_set<int> s;
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        auto key = [&](int x, int y) { return x * N + y; };
        vector<int> ans;
        for (auto &p : A) {
            int x = p[0], y = p[1], xy = uf.find(key(x, y));
            G[x][y] = 1;
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= M || b < 0 || b >= N || G[a][b] != 1) continue;
                int ab = uf.find(key(a, b));
                s.erase(ab);
                uf.connect(xy, ab);
            }
            s.insert(xy);
            ans.push_back(s.size());
        }
        return ans;
    }
};
```