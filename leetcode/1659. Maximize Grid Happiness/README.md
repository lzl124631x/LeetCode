# [1659. Maximize Grid Happiness (Hard)](https://leetcode.com/problems/maximize-grid-happiness/)

<p>You are given four integers, <code>m</code>, <code>n</code>, <code>introvertsCount</code>, and <code>extrovertsCount</code>. You have an <code>m x n</code> grid, and there are two types of people: introverts and extroverts. There are <code>introvertsCount</code> introverts and <code>extrovertsCount</code> extroverts.</p>

<p>You should decide how many people you want to live in the grid and assign each of them one grid cell. Note that you <strong>do not</strong> have to have all the people living in the grid.</p>

<p>The <strong>happiness</strong> of each person is calculated as follows:</p>

<ul>
	<li>Introverts <strong>start</strong> with <code>120</code> happiness and <strong>lose</strong> <code>30</code> happiness for each neighbor (introvert or extrovert).</li>
	<li>Extroverts <strong>start</strong> with <code>40</code> happiness and <strong>gain</strong> <code>20</code> happiness for each neighbor (introvert or extrovert).</li>
</ul>

<p>Neighbors live in the directly adjacent cells north, east, south, and west of a person's cell.</p>

<p>The <strong>grid happiness</strong> is the <strong>sum</strong> of each person's happiness. Return<em> the <strong>maximum possible grid happiness</strong>.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/grid_happiness.png" style="width: 261px; height: 121px;">
<pre><strong>Input:</strong> m = 2, n = 3, introvertsCount = 1, extrovertsCount = 2
<strong>Output:</strong> 240
<strong>Explanation:</strong> Assume the grid is 1-indexed with coordinates (row, column).
We can put the introvert in cell (1,1) and put the extroverts in cells (1,3) and (2,3).
- Introvert at (1,1) happiness: 120 (starting happiness) - (0 * 30) (0 neighbors) = 120
- Extrovert at (1,3) happiness: 40 (starting happiness) + (1 * 20) (1 neighbor) = 60
- Extrovert at (2,3) happiness: 40 (starting happiness) + (1 * 20) (1 neighbor) = 60
The grid happiness is 120 + 60 + 60 = 240.
The above figure shows the grid in this example with each person's happiness. The introvert stays in the light green cell while the extroverts live on the light purple cells.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> m = 3, n = 1, introvertsCount = 2, extrovertsCount = 1
<strong>Output:</strong> 260
<strong>Explanation:</strong> Place the two introverts in (1,1) and (3,1) and the extrovert at (2,1).
- Introvert at (1,1) happiness: 120 (starting happiness) - (1 * 30) (1 neighbor) = 90
- Extrovert at (2,1) happiness: 40 (starting happiness) + (2 * 20) (2 neighbors) = 80
- Introvert at (3,1) happiness: 120 (starting happiness) - (1 * 30) (1 neighbor) = 90
The grid happiness is 90 + 80 + 90 = 260.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> m = 2, n = 2, introvertsCount = 4, extrovertsCount = 0
<strong>Output:</strong> 240
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 5</code></li>
	<li><code>0 &lt;= introvertsCount, extrovertsCount &lt;= min(m * n, 6)</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximize-grid-happiness/
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
// Ref: https://leetcode.com/problems/maximize-grid-happiness/discuss/936081/C%2B%2B-5D-DP
class Solution {
    int dp[25][7][7][64][64] = {};
    int nCost(int m, int n, int i, int j, int mask_in, int mask_ex, int d) {
        int diff = 0, up = (1 << (n - 1));
        if (j > 0 && (mask_in & 1))
            diff += d - 30;
        if (i > 0 && (mask_in & up))
            diff += d - 30;
        if (j > 0 && (mask_ex & 1))
            diff += d + 20;
        if (i > 0 && (mask_ex & up))
            diff += d + 20;
        return diff;
    }
    int dfs(int m, int n, int p, int in, int ex, int mask_in, int mask_ex) {
        int i = p / n, j = p % n;
        if (i >= m)
            return 0;
        if (dp[p][in][ex][mask_in][mask_ex])
            return dp[p][in][ex][mask_in][mask_ex] - 1;
        int n_mask_in = (mask_in << 1) & 63, n_mask_ex = (mask_ex << 1) & 63;
        int res = dfs(m, n, p + 1, in, ex, n_mask_in, n_mask_ex);
        if (in > 0) {
            int diff = 120 + nCost(m, n, i, j, mask_in, mask_ex, -30);
            res = max(res, diff + dfs(m, n, p + 1, in - 1, ex, n_mask_in + 1, n_mask_ex));
        }
        if (ex > 0) {
            int diff = 40 + nCost(m, n, i, j, mask_in, mask_ex, 20);
            res = max(res, diff + dfs(m, n, p + 1, in, ex - 1, n_mask_in, n_mask_ex + 1));
        }
        dp[p][in][ex][mask_in][mask_ex] = res + 1;
        return res;
    }
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        return dfs(m, n, 0, introvertsCount, extrovertsCount, 0, 0);
    }
};
```