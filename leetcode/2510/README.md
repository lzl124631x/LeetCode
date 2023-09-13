# [2510. Check if There is a Path With Equal Number of 0's And 1's (Medium)](https://leetcode.com/problems/check-if-there-is-a-path-with-equal-number-of-0s-and-1s)

<p>You are given a <strong>0-indexed</strong> <code>m x n</code> <strong>binary</strong> matrix <code>grid</code>. You can move from a cell <code>(row, col)</code> to any of the cells <code>(row + 1, col)</code> or <code>(row, col + 1)</code>.</p>
<p>Return <code>true</code><em> if there is a path from </em><code>(0, 0)</code><em> to </em><code>(m - 1, n - 1)</code><em> that visits an <strong>equal</strong> number of </em><code>0</code><em>'s and </em><code>1</code><em>'s</em>. Otherwise return <code>false</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/12/20/yetgriddrawio-4.png">
<pre><strong>Input:</strong> grid = [[0,1,0,0],[0,1,0,0],[1,0,1,0]]
<strong>Output:</strong> true
<strong>Explanation:</strong> The path colored in blue in the above diagram is a valid path because we have 3 cells with a value of 1 and 3 with a value of 0. Since there is a valid path, we return true.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/12/20/yetgrid2drawio-1.png" style="width: 151px; height: 151px;">
<pre><strong>Input:</strong> grid = [[1,1,0],[0,0,1],[1,0,0]]
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no path in this grid with an equal number of 0's and 1's.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 100</code></li>
	<li><code>grid[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Minimum Path Sum (Medium)](https://leetcode.com/problems/minimum-path-sum/)
* [Dungeon Game (Hard)](https://leetcode.com/problems/dungeon-game/)
* [Minimum Cost Homecoming of a Robot in a Grid (Medium)](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/)
* [Paths in Matrix Whose Sum Is Divisible by K (Hard)](https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-if-there-is-a-path-with-equal-number-of-0s-and-1s
// Author: github.com/lzl124631x
// Time: O(MN * (M + N))
// Space: O(N * (M + N))
class Solution {
public:
    bool isThereAPath(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        vector<bitset<200>> dp(N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == 0 && j == 0) dp[j].set(A[i][j] ? 101 : 99);
                else if (i == 0) dp[j] = A[i][j] ? (dp[j - 1] << 1) : (dp[j - 1] >> 1);
                else if (j == 0) dp[j] = A[i][j] ? (dp[j] << 1) : (dp[j] >> 1);
                else dp[j] = A[i][j] ? ((dp[j] << 1) | (dp[j - 1] << 1)) : ((dp[j] >> 1) 
| (dp[j - 1] >> 1));
            }
        }
        return dp[N - 1].test(100);
    }
};
```

## Solution 2. DP

**Intuition**: There exists a discretely continuous transformation between any pair of paths. Namely, given two paths `p1` and `p2` with sums `s1 <= s2` respectively, there existsthere exists a path `p` with sum `s` for every `s1 <= s <= s2`.

For the simpliest case of `2x2` cells, `A[0][0]` and `A[1][1]` are shared between `p1` and `p2`. The only difference is `A[1][0]` and `A[0][1]`, and their difference is at most `1`.

Now consider a `2x3` grid, `p1 = (0,0) - (0,1) - (0,2) - (1,2)`, `p2 = (0,0) - (0,1) - (1,1) - (1,2)`, and `p3 = (0,0) - (1,0) - (1,1) - (1,2)`. We can see that the difference between `p1` and `p2` is at most `1`, and the same for `p2` and `p3`. So, the difference between `p1` and `p3` is at most `2`, in which case `p1, p2, p3` are continous.

We can generalize this to `MxN` grid, and see that the above intuition is true.

```cpp
// OJ: https://leetcode.com/problems/check-if-there-is-a-path-with-equal-number-of-0s-and-1s
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    bool isThereAPath(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        if ((M + N) % 2 == 0) return false;
        vector<vector<int>> mn(M, vector<int>(N)), mx(M, vector<int>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == 0 && j == 0) mn[i][j] = mx[i][j] = A[i][j];
                else if (i == 0) mn[i][j] = mx[i][j] = mn[i][j - 1] + A[i][j];
                else if (j == 0) mn[i][j] = mx[i][j] = mn[i - 1][j] + A[i][j];
                else {
                    mn[i][j] = min(mn[i - 1][j], mn[i][j - 1]) + A[i][j];
                    mx[i][j] = max(mx[i - 1][j], mx[i][j - 1]) + A[i][j];
                }
            }
        }
        return mn[M - 1][N - 1] <= (M + N - 1) / 2 && (M + N - 1) / 2 <= mx[M - 1][N - 1];
    }
};
```

Since `mx[i][j]` only depends on `mx[i][j - 1]`and `mx[i - 1][j]`, we can reduce the complexity from `O(MN)` to `O(N)`.

```cpp
// OJ: https://leetcode.com/problems/check-if-there-is-a-path-with-equal-number-of-0s-and-1s
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    bool isThereAPath(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        if ((M + N) % 2 == 0) return false;
        vector<int> mn(N), mx(N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == 0 && j == 0) mn[j] = mx[j] = A[i][j];
                else if (i == 0) mn[j] = mx[j] = mn[j - 1] + A[i][j];
                else if (j == 0) mn[j] = mx[j] = mn[j] + A[i][j];
                else {
                    int prevMin = min(mn[j], mn[j - 1]), prevMax = max(mx[j], mx[j - 1]);
                    mn[j] = prevMin + A[i][j];
                    mx[j] = prevMax + A[i][j];
                }
            }
        }
        return mn[N - 1] <= (M + N - 1) / 2 && (M + N - 1) / 2 <= mx[N - 1];
    }
};
```