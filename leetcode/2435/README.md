# [2435. Paths in Matrix Whose Sum Is Divisible by K (Hard)](https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k)

<p>You are given a <strong>0-indexed</strong> <code>m x n</code> integer matrix <code>grid</code> and an integer <code>k</code>. You are currently at position <code>(0, 0)</code> and you want to reach position <code>(m - 1, n - 1)</code> moving only <strong>down</strong> or <strong>right</strong>.</p>
<p>Return<em> the number of paths where the sum of the elements on the path is divisible by </em><code>k</code>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/08/13/image-20220813183124-1.png" style="width: 437px; height: 200px;">
<pre><strong>Input:</strong> grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two paths where the sum of the elements on the path is divisible by k.
The first path highlighted in red has a sum of 5 + 2 + 4 + 5 + 2 = 18 which is divisible by 3.
The second path highlighted in blue has a sum of 5 + 3 + 0 + 5 + 2 = 15 which is divisible by 3.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/08/17/image-20220817112930-3.png" style="height: 85px; width: 132px;">
<pre><strong>Input:</strong> grid = [[0,0]], k = 5
<strong>Output:</strong> 1
<strong>Explanation:</strong> The path highlighted in red has a sum of 0 + 0 = 0 which is divisible by 5.
</pre>
<p><strong class="example">Example 3:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/08/12/image-20220812224605-3.png" style="width: 257px; height: 200px;">
<pre><strong>Input:</strong> grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
<strong>Output:</strong> 10
<strong>Explanation:</strong> Every integer is divisible by 1 so the sum of the elements on every possible path is divisible by k.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 50</code></li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Unique Paths (Medium)](https://leetcode.com/problems/unique-paths/)
* [Unique Paths II (Medium)](https://leetcode.com/problems/unique-paths-ii/)
* [Minimum Path Sum (Medium)](https://leetcode.com/problems/minimum-path-sum/)
* [Dungeon Game (Hard)](https://leetcode.com/problems/dungeon-game/)
* [Cherry Pickup (Hard)](https://leetcode.com/problems/cherry-pickup/)
* [Shortest Path in Binary Matrix (Medium)](https://leetcode.com/problems/shortest-path-in-binary-matrix/)
* [Minimum Cost Homecoming of a Robot in a Grid (Medium)](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/)
* [Check if There is a Path With Equal Number of 0's And 1's (Medium)](https://leetcode.com/problems/check-if-there-is-a-path-with-equal-number-of-0s-and-1s/)

## Solution 1. DP

Let `dp[i][j]` be all the sums of paths from `(0,0)` to `(i,j)`.

```
dp[i][j] = { x + A[i][j] | x is in dp[i-1][j] and dp[i][j-1] }

dp[0][0] = { A[0][0] }
```

Instead of keeping track of the set of sum numbers, we just need to keep track of the count of `sum % K`.

So, we let each `dp[i][j]` be an array, where `dp[i][j][k]` is the count of the count of paths from `(0,0)` to `(i,j)` that have `sum % K == k`.

```
dp[0][0][k] = 1 if k == A[i][j] % K
              0 otherwise

dp[i][j][k] = dp[i-1][j][k - A[i][j]] + dp[i][j-1][k - A[i][j]]
```

Since `dp[i][j]` only depends on `dp[i-1][j]` and `dp[i][j-1]`, we can reduce the space complexity from `O(MNK)` to `O(NK)`.


```cpp
// OJ: https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k
// Author: github.com/lzl124631x
// Time: O(MNK)
// Space: O(NK)
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& A, int K) {
        long M = A.size(), N = A[0].size(), mod = 1e9 + 7;
        vector<vector<long>> dp(N, vector<long>(K));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == 0 && j == 0) dp[j][A[i][j] % K]++;
                else {
                    vector<long> next(K);
                    for (int k = 0; k < K; ++k) next[k] = dp[j][(K + k - A[i][j] % K) % K];
                    if (j > 0) {
                        for (int k = 0; k < K; ++k) next[k] = (next[k] + dp[j - 1][(K + k - A[i][j] % K) % K]) % mod;
                    }
                    swap(next, dp[j]);
                }
            }
        }
        return dp[N - 1][0];
    }
};
```