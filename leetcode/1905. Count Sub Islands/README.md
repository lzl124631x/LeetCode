# [1905. Count Sub Islands (Medium)](https://leetcode.com/problems/count-sub-islands/)

<p>You are given two <code>m x n</code> binary matrices <code>grid1</code> and <code>grid2</code> containing only <code>0</code>'s (representing water) and <code>1</code>'s (representing land). An <strong>island</strong> is a group of <code>1</code>'s connected <strong>4-directionally</strong> (horizontal or vertical). Any cells outside of the grid are considered water cells.</p>

<p>An island in <code>grid2</code> is considered a <strong>sub-island </strong>if there is an island in <code>grid1</code> that contains <strong>all</strong> the cells that make up <strong>this</strong> island in <code>grid2</code>.</p>

<p>Return the <em><strong>number</strong> of islands in </em><code>grid2</code> <em>that are considered <strong>sub-islands</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/10/test1.png" style="width: 493px; height: 205px;">
<pre><strong>Input:</strong> grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
<strong>Output:</strong> 3
<strong>Explanation: </strong>In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/03/testcasex2.png" style="width: 491px; height: 201px;">
<pre><strong>Input:</strong> grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
<strong>Output:</strong> 2 
<strong>Explanation: </strong>In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid1.length == grid2.length</code></li>
	<li><code>n == grid1[i].length == grid2[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>grid1[i][j]</code> and <code>grid2[i][j]</code> are either <code>0</code> or <code>1</code>.</li>
</ul>


**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Union Find](https://leetcode.com/tag/union-find/)

**Similar Questions**:
* [Number of Islands (Medium)](https://leetcode.com/problems/number-of-islands/)
* [Number of Distinct Islands (Medium)](https://leetcode.com/problems/number-of-distinct-islands/)

## Solution 1. DFS

**Intuition**: If an island in `B` overlaps with a water cell in `A`, then this island shouldn't be considered.

**Algorithm**

1. For each water cell `A[i][j]`, sink the island in `B` containing `B[i][j]` into water.
2. Count the number of islands in `B`.

```cpp
// OJ: https://leetcode.com/problems/count-sub-islands/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
    int dirs[4][2] = {{0,1},{0,-1},{-1,0},{1,0}}, M, N;
    void dfs(vector<vector<int>> &B, int x, int y, int color) {
        if (B[x][y] == color) return;
        B[x][y] = color;
        for (auto &[dx, dy] : dirs) {
            int a = x + dx, b = y + dy;
            if (a < 0 || a >= M || b < 0 || b >= N) continue;
            dfs(B, a, b, color);
        }
    }
public:
    int countSubIslands(vector<vector<int>>& A, vector<vector<int>>& B) {
        M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 0) dfs(B, i, j, 0); // sink this island at B[i][j]
            }
        }
        int cnt = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (B[i][j] == 1) {
                    dfs(B, i, j, 0);
                    ++cnt; // count islands in `B`
                }
            }
        }
        return cnt;
    }
};
```