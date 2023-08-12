# [63. Unique Paths II (Medium)](https://leetcode.com/problems/unique-paths-ii)

<p>You are given an <code>m x n</code> integer array <code>grid</code>. There is a robot initially located at the <b>top-left corner</b> (i.e., <code>grid[0][0]</code>). The robot tries to move to the <strong>bottom-right corner</strong> (i.e., <code>grid[m - 1][n - 1]</code>). The robot can only move either down or right at any point in time.</p>
<p>An obstacle and space are marked as <code>1</code> or <code>0</code> respectively in <code>grid</code>. A path that the robot takes cannot include <strong>any</strong> square that is an obstacle.</p>
<p>Return <em>the number of possible unique paths that the robot can take to reach the bottom-right corner</em>.</p>
<p>The testcases are generated so that the answer will be less than or equal to <code>2 * 10<sup>9</sup></code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg" style="width: 242px; height: 242px;">
<pre><strong>Input:</strong> obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -&gt; Right -&gt; Down -&gt; Down
2. Down -&gt; Down -&gt; Right -&gt; Right
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg" style="width: 162px; height: 162px;">
<pre><strong>Input:</strong> obstacleGrid = [[0,1],[0,0]]
<strong>Output:</strong> 1
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>m == obstacleGrid.length</code></li>
	<li><code>n == obstacleGrid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>obstacleGrid[i][j]</code> is <code>0</code> or <code>1</code>.</li>
</ul>

**Companies**:
[Atlassian](https://leetcode.com/company/atlassian), [Cruise Automation](https://leetcode.com/company/cruise-automation), [athenahealth](https://leetcode.com/company/athenahealth)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Unique Paths (Medium)](https://leetcode.com/problems/unique-paths/)
* [Unique Paths III (Hard)](https://leetcode.com/problems/unique-paths-iii/)
* [Minimum Path Cost in a Grid (Medium)](https://leetcode.com/problems/minimum-path-cost-in-a-grid/)
* [Paths in Matrix Whose Sum Is Divisible by K (Hard)](https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/)

## Solution 1. DP

Let `dp[i+1][j+1]` be the number of ways to reach `A[i][j]`. The answer is `dp[M][N]`.

```
dp[1][1] = 1

dp[i+1][j+1] = 0                         // if A[i][j] == 1
               dp[i][j+1] + dp[i+1][j]   // if A[i][j] == 0
```

Since `dp[i+1][j+1]` only depends on `dp[i][j+1]` and `dp[i+1][j]`, we can reduce the space complexity from `O(MN)` to `O(N)`.

```cpp
// OJ: https://leetcode.com/problems/unique-paths-ii/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        vector<int> dp(N + 1);
        dp[1] = 1;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j]) dp[j + 1] = 0;
                else dp[j + 1] += dp[j];
            }
        }
        return dp[N];
    }
};
```