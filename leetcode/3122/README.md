# [3122. Minimum Number of Operations to Satisfy Conditions (Medium)](https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions)

<p>You are given a 2D matrix <code>grid</code> of size <code>m x n</code>. In one <strong>operation</strong>, you can change the value of <strong>any</strong> cell to <strong>any</strong> non-negative number. You need to perform some <strong>operations</strong> such that each cell <code>grid[i][j]</code> is:</p>

<ul>
	<li>Equal to the cell below it, i.e. <code>grid[i][j] == grid[i + 1][j]</code> (if it exists).</li>
	<li>Different from the cell to its right, i.e. <code>grid[i][j] != grid[i][j + 1]</code> (if it exists).</li>
</ul>

<p>Return the <strong>minimum</strong> number of operations needed.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[1,0,2],[1,0,2]]</span></p>

<p><strong>Output:</strong> 0</p>

<p><strong>Explanation:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2024/04/15/examplechanged.png" style="width: 254px; height: 186px;padding: 10px; background: #fff; border-radius: .5rem;" /></strong></p>

<p>All the cells in the matrix already satisfy the properties.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[1,1,1],[0,0,0]]</span></p>

<p><strong>Output:</strong> 3</p>

<p><strong>Explanation:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2024/03/27/example21.png" style="width: 254px; height: 186px;padding: 10px; background: #fff; border-radius: .5rem;" /></strong></p>

<p>The matrix becomes <code>[[1,0,1],[1,0,1]]</code> which satisfies the properties, by doing these 3 operations:</p>

<ul>
	<li>Change <code>grid[1][0]</code> to 1.</li>
	<li>Change <code>grid[0][1]</code> to 0.</li>
	<li>Change <code>grid[1][2]</code> to 1.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[1],[2],[3]]</span></p>

<p><strong>Output:</strong> 2</p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/03/31/changed.png" style="width: 86px; height: 277px;padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<p>There is a single column. We can change the value to 1 in each cell using 2 operations.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 1000</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 9</code></li>
</ul>

**Similar Questions**:

- [Candy (Hard)](https://leetcode.com/problems/candy)
- [Distribute Candies (Easy)](https://leetcode.com/problems/distribute-candies)
- [Minimum Cost of Buying Candies With Discount (Easy)](https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount)

**Hints**:

- Use Hashing to store for each frequency of candies, how many times it occurs in each box.
- We can use dynamic programming.

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int minimumOperations(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), dp[1001][10] = {}, cnt[1001][10] = {};
        memset(dp, 0x3f, sizeof(dp));
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < M; ++i) {
                cnt[j][A[i][j]]++;
            }
        }
        for (int i = 0; i < 10; ++i) dp[N - 1][i] = M - cnt[N - 1][i];
        for (int j = N - 2; j >= 0; --j) {
            for (int k = 0; k <= 9; ++k) {
                for (int t = 0; t <= 9; ++t) {
                    if (k == t) continue;
                    dp[j][k] = min(dp[j][k], M - cnt[j][k] + dp[j + 1][t]);
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < 10; ++i) {
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
};
```
