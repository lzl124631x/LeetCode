# [1420. Build Array Where You Can Find The Maximum Exactly K Comparisons (Hard)](https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/)

<p>Given three integers <code>n</code>, <code>m</code> and <code>k</code>. Consider the following algorithm to find the maximum element of an array of positive integers:</p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/04/02/e.png" style="width: 424px; height: 372px;">
<p>You should build the array arr which has the following properties:</p>

<ul>
	<li><code>arr</code> has exactly <code>n</code> integers.</li>
	<li><code>1 &lt;= arr[i] &lt;= m</code> where <code>(0 &lt;= i &lt; n)</code>.</li>
	<li>After applying the mentioned algorithm to <code>arr</code>, the value <code>search_cost</code> is equal to <code>k</code>.</li>
</ul>

<p>Return <em>the number of ways</em> to build the array <code>arr</code> under the mentioned conditions.&nbsp;As the answer may grow large, the answer&nbsp;<strong>must be</strong>&nbsp;computed modulo&nbsp;<code>10^9 + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 2, m = 3, k = 1
<strong>Output:</strong> 6
<strong>Explanation:</strong> The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 5, m = 2, k = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no possible arrays that satisify the mentioned conditions.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 9, m = 1, k = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> n = 50, m = 100, k = 25
<strong>Output:</strong> 34549172
<strong>Explanation:</strong> Don't forget to compute the answer modulo 1000000007
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> n = 37, m = 17, k = 7
<strong>Output:</strong> 418930126
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= m &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= n</code></li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

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