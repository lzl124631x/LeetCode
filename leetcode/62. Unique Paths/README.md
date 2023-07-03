# [62. Unique Paths (Medium)](https://leetcode.com/problems/unique-paths)

<p>There is a robot on an <code>m x n</code> grid. The robot is initially located at the <strong>top-left corner</strong> (i.e., <code>grid[0][0]</code>). The robot tries to move to the <strong>bottom-right corner</strong> (i.e., <code>grid[m - 1][n - 1]</code>). The robot can only move either down or right at any point in time.</p>

<p>Given the two integers <code>m</code> and <code>n</code>, return <em>the number of possible unique paths that the robot can take to reach the bottom-right corner</em>.</p>

<p>The test cases are generated so that the answer will be less than or equal to <code>2 * 10<sup>9</sup></code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png" style="width: 400px; height: 183px;">
<pre><strong>Input:</strong> m = 3, n = 7
<strong>Output:</strong> 28
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> m = 3, n = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -&gt; Down -&gt; Down
2. Down -&gt; Down -&gt; Right
3. Down -&gt; Right -&gt; Down
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Combinatorics](https://leetcode.com/tag/combinatorics/)

**Similar Questions**:
* [Unique Paths II (Medium)](https://leetcode.com/problems/unique-paths-ii/)
* [Minimum Path Sum (Medium)](https://leetcode.com/problems/minimum-path-sum/)
* [Dungeon Game (Medium)](https://leetcode.com/problems/dungeon-game/)
* [Minimum Path Cost in a Grid (Medium)](https://leetcode.com/problems/minimum-path-cost-in-a-grid/)
* [Minimum Cost Homecoming of a Robot in a Grid (Medium)](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/)
* [Number of Ways to Reach a Position After Exactly k Steps (Medium)](https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/)
* [Paths in Matrix Whose Sum Is Divisible by K (Medium)](https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/)

## Solution 1. DP

Let `dp[i][j]` be the number of unique paths to reach `(i,j)`. The answer is `dp[m-1][n-1]`.

```
dp[i][j] = dp[i][j-1] + dp[i-1][j]   where i >= 1 and j >= 1
dp[0][j] = dp[i][0] = 1
```

```cpp
// OJ: https://leetcode.com/problems/unique-paths
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
```

## Solution 2. DP + Space Optimization

```cpp
// OJ: https://leetcode.com/problems/unique-paths
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
```

## Solution 3. Math (Combination)

We have `m - 1` right operations and `n - 1` down operations, `m + n - 2` operations in total. The result is the number of different combinations of these operations -- pick `m - 1` slots for right operations from `m + n - 2` slots.

$$
C(m + n - 2, m - 1) = \dfrac{(m+n-2)!}{(m-1)!\cdot (n-1)!} = \dfrac{m\cdot(m+1)\cdots(m+n-2)}{1\cdot2\cdots(n-1)}
$$

```cpp
// OJ: https://leetcode.com/problems/unique-paths
// Author: github.com/lzl124631x
// Time: O(min(M,N))
// Space: O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n > m) swap(n, m);
        long ans = 1;
        for (int i = 1; i <= n - 1; ++i) {
            ans = ans * (m - 1 + i) / i;
        }
        return ans;
    }
};
```

## Solution 4. Math (Combination)

We can use the `combination` function to compute $C_n^k$

```cpp
// OJ: https://leetcode.com/problems/unique-paths/
// Author: github.com/lzl124631x
// Time: O(min(M,N))
// Space: O(1)
class Solution {
    int combination(int n, int k) {
        k = min(k, n - k); // Since we loop in range [1, k], we make sure `k` is smaller than `n - k`
        long ans = 1;
        for (int i = 1; i <= k; ++i) ans = ans * (n - k + i) / i;
        return ans;
    }
public:
    int uniquePaths(int m, int n) {
        return combination(m + n - 2, m - 1);
    }
};
```