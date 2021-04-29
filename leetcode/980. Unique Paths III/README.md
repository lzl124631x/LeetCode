# [980. Unique Paths III (Hard)](https://leetcode.com/problems/unique-paths-iii/)

<p>On a 2-dimensional&nbsp;<code>grid</code>, there are 4 types of squares:</p>

<ul>
	<li><code>1</code> represents the starting square.&nbsp; There is exactly one starting square.</li>
	<li><code>2</code> represents the ending square.&nbsp; There is exactly one ending square.</li>
	<li><code>0</code> represents empty squares we can walk over.</li>
	<li><code>-1</code> represents obstacles that we cannot walk over.</li>
</ul>

<p>Return the number of 4-directional walks&nbsp;from the starting square to the ending square, that <strong>walk over every non-obstacle square&nbsp;exactly once</strong>.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]</span>
<strong>Output: </strong><span id="example-output-1">2</span>
<strong>Explanation: </strong>We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[[1,0,0,0],[0,0,0,0],[0,0,0,2]]</span>
<strong>Output: </strong><span id="example-output-2">4</span>
<strong>Explanation: </strong>We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">[[0,1],[2,0]]</span>
<strong>Output: </strong><span id="example-output-3">0</span>
<strong>Explanation: </strong>
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
</pre>
</div>
</div>
</div>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= grid.length * grid[0].length &lt;= 20</code></li>
</ol>

**Companies**:  
[LimeBike](https://leetcode.com/company/limebike)

**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Sudoku Solver (Hard)](https://leetcode.com/problems/sudoku-solver/)
* [Unique Paths II (Medium)](https://leetcode.com/problems/unique-paths-ii/)
* [Word Search II (Hard)](https://leetcode.com/problems/word-search-ii/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/unique-paths-iii/
// Author: github.com/lzl124631x
// Time: O(4^(MN))
// Space: O(1)
class Solution {
private:
    int ans = 0, target = 0, M, N, dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void dfs(vector<vector<int>>& grid, int x, int y) {
        if (grid[x][y] == 2) {
            ans += target == 1;
            return;
        }
        grid[x][y] = -1;
        --target;
        for (auto &[dx, dy] : dirs) {
            int i = x + dx, j = y + dy;
            if (i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == -1) continue;
            dfs(grid, i, j);
        }
        ++target;
        grid[x][y] = 0;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        M = grid.size(), N = grid[0].size();
        int x, y;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                target += grid[i][j] != -1;
                if (grid[i][j] == 1) x = i, y = j;
            }
        }
        dfs(grid, x, y);
        return ans;
    }
};
```