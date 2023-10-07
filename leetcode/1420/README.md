# [1420. Build Array Where You Can Find The Maximum Exactly K Comparisons (Hard)](https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons)

<p>You are given three integers <code>n</code>, <code>m</code> and <code>k</code>. Consider the following algorithm to find the maximum element of an array of positive integers:</p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/04/02/e.png" style="width: 424px; height: 372px;" />
<p>You should build the array arr which has the following properties:</p>

<ul>
	<li><code>arr</code> has exactly <code>n</code> integers.</li>
	<li><code>1 &lt;= arr[i] &lt;= m</code> where <code>(0 &lt;= i &lt; n)</code>.</li>
	<li>After applying the mentioned algorithm to <code>arr</code>, the value <code>search_cost</code> is equal to <code>k</code>.</li>
</ul>

<p>Return <em>the number of ways</em> to build the array <code>arr</code> under the mentioned conditions. As the answer may grow large, the answer <strong>must be</strong> computed modulo <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 2, m = 3, k = 1
<strong>Output:</strong> 6
<strong>Explanation:</strong> The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 5, m = 2, k = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no possible arrays that satisify the mentioned conditions.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 9, m = 1, k = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= m &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= n</code></li>
</ul>


**Companies**:
[Dunzo](https://leetcode.com/company/dunzo)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Prefix Sum](https://leetcode.com/tag/prefix-sum)

**Hints**:
* Use dynamic programming approach. Build dp table where dp[a][b][c] is the number of ways you can start building the array starting from index a where the search_cost = c and the maximum used integer was b.
* Recursively, solve the small sub-problems first. Optimize your answer by stopping the search if you exceeded k changes.

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/
// Author: github.com/lzl124631x
// Time: O(M^2 * NK)
// Space: O(MNK)
// Ref: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/discuss/586576/C%2B%2B-Bottom-Up-Dynamic-Programming-with-Explanation
class Solution {
    typedef long long LL;
    LL dp[51][101][51] = {};
public:
    int numOfArrays(int n, int m, int k) {
        int mod = 1e9+7;
        for (int i = 0; i <= m; ++i) dp[1][i][1] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int t = 1; t <= k; ++t) {
                    LL s = 0;
                    s = (s + j * dp[i - 1][j][t]) % mod;
                    for (int x = 1; x < j; ++x) s = (s + dp[i - 1][x][t - 1]) %mod;
                    dp[i][j][t] = (dp[i][j][t] + s) % mod;
                }
            }
        }
        LL ans = 0;
        for (int i = 1; i <= m; ++i) ans = (ans + dp[n][i][k]) % mod;
        return ans;
    }
};
```

## Solution 2. Top-down DP

Let `dp[n][m][k]` be the number of ways to build arrays with `n` elements left to fill, `m` being the previously filled maximum element, and `k` being the search_cost left to achieve. The answer is `dp[N][0][K]`.

```
dp[0][m][k] = 1 if k == 0
            = 0 otherwise
```

For `dp[n][m][k]`, we have two options
* If the elements left after filling the current element `n - 1` is greater than or equal to the remaining search cost `k`, we can fill `[1,m]` to the current element. So we add `dp[n-1][m][k] * m` to `dp[n][m][k]`.
* If `k >= 1`, we can fill `[m+1, M]` to the current element, So, we add `SUM( dp[n-1, i, k-1] | m+1 <= i <= M )` to `dp[n][m][k]`.

```cpp
// OJ: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons
// Author: github.com/lzl124631x
// Time: O(M^2 * NK)
// Space: O(MNK)
class Solution {
public:
    int numOfArrays(int N, int M, int K) {
        if (K == 0) return 0;
        int memo[51][101][51] = {}, ans = 0, mod = 1e9 + 7;
        memset(memo, -1, sizeof(memo));
        function<int(int, int, int)> dp = [&](int n, int m, int k) -> int {
            if (n == 0) return k == 0;
            if (memo[n][m][k] != -1) return memo[n][m][k];
            int ans = 0;
            if (n - 1 >= k) ans = (ans + (long)dp(n - 1, m, k) * m % mod) % mod;
            if (k >= 1) {
                for (int i = m + 1; i <= M; ++i) {
                    ans = (ans + dp(n - 1, i, k - 1)) % mod;
                }
            }
            return memo[n][m][k] = ans;
        };
        return dp(N, 0, K);
    }
};
```