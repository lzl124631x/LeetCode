# [675. Cut Off Trees for Golf Event (Hard)](https://leetcode.com/problems/cut-off-trees-for-golf-event/)

<p>You are asked to cut off all the trees in a forest for a golf event. The forest is represented as an <code>m x n</code> matrix. In this matrix:</p>

<ul>
	<li><code>0</code> means the cell cannot be walked through.</li>
	<li><code>1</code> represents an empty cell that can be walked through.</li>
	<li>A number greater than <code>1</code> represents a tree in a cell that can be walked through, and this number is the tree's height.</li>
</ul>

<p>In one step, you can walk in any of the four directions: north, east, south, and west. If you are standing in a cell with a tree, you can choose whether to cut it off.</p>

<p>You must cut off the trees in order from shortest to tallest. When you cut off a tree, the value at its cell becomes <code>1</code> (an empty cell).</p>

<p>Starting from the point <code>(0, 0)</code>, return <em>the minimum steps you need to walk to cut off all the trees</em>. If you cannot cut off all the trees, return <code>-1</code>.</p>

<p>You are guaranteed that no two trees have the same height, and there is at least one tree needs to be cut off.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/26/trees1.jpg" style="width: 242px; height: 242px;">
<pre><strong>Input:</strong> forest = [[1,2,3],[0,0,4],[7,6,5]]
<strong>Output:</strong> 6
<strong>Explanation:</strong> Following the path above allows you to cut off the trees from shortest to tallest in 6 steps.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/26/trees2.jpg" style="width: 242px; height: 242px;">
<pre><strong>Input:</strong> forest = [[1,2,3],[0,0,0],[7,6,5]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> The trees in the bottom row cannot be accessed as the middle row is blocked.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> forest = [[2,3,4],[0,0,5],[8,7,6]]
<strong>Output:</strong> 6
<b>Explanation:</b> You can follow the same path as Example 1 to cut off all the trees.
Note that you can cut off the first tree at (0, 0) before making any steps.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == forest.length</code></li>
	<li><code>n == forest[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>0 &lt;= forest[i][j] &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Matrix](https://leetcode.com/tag/matrix/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/cut-off-trees-for-golf-event/
// Author: github.com/lzl124631x
// Time: O((MN)^2)
// Space: O(MN)
class Solution {
public:
    int cutOffTree(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        vector<array<int, 2>> v;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] > 1) v.push_back({i, j});
            }
        }
        sort(begin(v), end(v), [&](auto &a, auto &b) { return A[a[0]][a[1]] < A[b[0]][b[1]]; });
        int seen[51][51] = {}, ans = 0, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        auto bfs = [&](array<int, 2> &from, array<int, 2> &to) {
            queue<array<int, 2>> q{{from}};
            memset(seen, 0, sizeof(seen));
            int step = 0;
            while (q.size()) {
                int cnt = q.size();
                while (cnt--) {
                    auto [x, y] = q.front();
                    q.pop();
                    if (x == to[0] && y == to[1]) return step;
                    for (auto &[dx, dy] : dirs) {
                        int a = x + dx, b = y + dy;
                        if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] == 0 || seen[a][b]) continue;
                        seen[a][b] = 1;
                        q.push({a, b});
                    }
                }
                ++step;
            }
            return -1;
        };
        array<int, 2> prev = {0,0};
        for (auto &p : v) {
            int len = bfs(prev, p);
            if (len == -1) return -1;
            ans += len;
            prev = p;
        }
        return ans;
    }
};
```