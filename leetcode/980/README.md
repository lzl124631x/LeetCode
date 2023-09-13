# [980. Unique Paths III (Hard)](https://leetcode.com/problems/unique-paths-iii/)

<p>You are given an <code>m x n</code> integer array <code>grid</code> where <code>grid[i][j]</code> could be:</p>

<ul>
	<li><code>1</code> representing the starting square. There is exactly one starting square.</li>
	<li><code>2</code> representing the ending square. There is exactly one ending square.</li>
	<li><code>0</code> representing empty squares we can walk over.</li>
	<li><code>-1</code> representing obstacles that we cannot walk over.</li>
</ul>

<p>Return <em>the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/02/lc-unique1.jpg" style="width: 324px; height: 245px;">
<pre><strong>Input:</strong> grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/02/lc-unique2.jpg" style="width: 324px; height: 245px;">
<pre><strong>Input:</strong> grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/02/lc-unique3-.jpg" style="width: 164px; height: 165px;">
<pre><strong>Input:</strong> grid = [[0,1],[2,0]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 20</code></li>
	<li><code>1 &lt;= m * n &lt;= 20</code></li>
	<li><code>-1 &lt;= grid[i][j] &lt;= 2</code></li>
	<li>There is exactly one starting cell and one ending cell.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Cruise Automation](https://leetcode.com/company/cruise-automation), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Sudoku Solver (Hard)](https://leetcode.com/problems/sudoku-solver/)
* [Unique Paths II (Medium)](https://leetcode.com/problems/unique-paths-ii/)
* [Word Search II (Hard)](https://leetcode.com/problems/word-search-ii/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/unique-paths-iii/
// Author: github.com/lzl124631x
// Time: O(3^(MN))
// Space: O(MN) due to call stack
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), sx, sy, goal = 0, ans = 0, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        function<void(int, int)> dfs = [&](int x, int y) {
            if (A[x][y] == 2) {
                ans += goal == 1;
                return;
            }
            A[x][y] = -1;
            --goal;
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] == -1) continue;
                dfs(a, b);
            }
            ++goal;
            A[x][y] = 0;
        };
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] != -1) ++goal;
                if (A[i][j] == 1) sx = i, sy = j;
            }
        }
        dfs(sx, sy);
        return ans;
    }
};
```

Or we are not allowed to change the grid, we can use a bitmask to track visited cells.

```cpp
// OJ: https://leetcode.com/problems/unique-paths-iii/
// Author: github.com/lzl124631x
// Time: O(3^(MN))
// Space: O(MN)
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), sx, sy, goal = 0, ans = 0, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}, seen = 0;
        function<void(int, int)> dfs = [&](int x, int y) {
            if (A[x][y] == 2) {
                ans += goal == 1;
                return;
            }
            int bit = 1 << (x * N + y);
            seen ^= bit;
            --goal;
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] == -1 || seen & (1 << (a * N + b))) continue;
                dfs(a, b);
            }
            ++goal;
            seen ^= bit;
        };
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] != -1) ++goal;
                if (A[i][j] == 1) sx = i, sy = j;
            }
        }
        dfs(sx, sy);
        return ans;
    }
};
```