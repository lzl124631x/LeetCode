# [741. Cherry Pickup (Hard)](https://leetcode.com/problems/cherry-pickup/)

<p>You are given an <code>n x n</code> <code>grid</code> representing a field of cherries, each cell is one of three possible integers.</p>

<ul>
	<li><code>0</code> means the cell is empty, so you can pass through,</li>
	<li><code>1</code> means the cell contains a cherry that you can pick up and pass through, or</li>
	<li><code>-1</code> means the cell contains a thorn that blocks your way.</li>
</ul>

<p>Return <em>the maximum number of cherries you can collect by following the rules below</em>:</p>

<ul>
	<li>Starting at the position <code>(0, 0)</code> and reaching <code>(n - 1, n - 1)</code> by moving right or down through valid path cells (cells with value <code>0</code> or <code>1</code>).</li>
	<li>After reaching <code>(n - 1, n - 1)</code>, returning to <code>(0, 0)</code> by moving left or up through valid path cells.</li>
	<li>When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell <code>0</code>.</li>
	<li>If there is no valid path between <code>(0, 0)</code> and <code>(n - 1, n - 1)</code>, then no cherries can be collected.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/14/grid.jpg" style="width: 242px; height: 242px;">
<pre><strong>Input:</strong> grid = [[0,1,-1],[1,0,-1],[1,1,1]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>grid[i][j]</code> is <code>-1</code>, <code>0</code>, or <code>1</code>.</li>
	<li><code>grid[0][0] != -1</code></li>
	<li><code>grid[n - 1][n - 1] != -1</code></li>
</ul>


**Companies**:  
[ServiceNow](https://leetcode.com/company/servicenow), [Mathworks](https://leetcode.com/company/mathworks), [Google](https://leetcode.com/company/google), [Cisco](https://leetcode.com/company/cisco)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Minimum Path Sum (Medium)](https://leetcode.com/problems/minimum-path-sum/)
* [Dungeon Game (Hard)](https://leetcode.com/problems/dungeon-game/)
* [Maximum Path Quality of a Graph (Hard)](https://leetcode.com/problems/maximum-path-quality-of-a-graph/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/cherry-pickup/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^3)
// Ref: https://leetcode.com/problems/cherry-pickup/solution/
class Solution {
public:
    int cherryPickup(vector<vector<int>>& A) {
        int N = A.size(), memo[51][51][51] = {}; // INT_MIN = non-reachable, -1 = unvisited
        memset(memo, -1, sizeof(memo));
        function<int(int, int, int)> dp = [&](int r1, int c1, int c2) {
            int r2 = r1 + c1 - c2;
            if (r1 == N || r2 == N || c1 == N || c2 == N || A[r1][c1] == -1 || A[r2][c2] == -1) return INT_MIN; // If out-of-bound or non-reachable, return -Infinity
            if (r1 == N - 1 && c1 == N - 1) return A[r1][c1];
            if (memo[r1][c1][c2] != -1) return memo[r1][c1][c2];
            int ans = A[r1][c1];
            if (c1 != c2) ans += A[r2][c2];
            ans += max({ dp(r1, c1 + 1, c2 + 1), dp(r1, c1 + 1, c2), dp(r1 + 1, c1, c2 + 1), dp(r1 + 1, c1, c2) });
            return memo[r1][c1][c2] = ans;
        };
        return max(0, dp(0, 0, 0));
    }
};
```