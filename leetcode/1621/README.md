# [1621. Number of Sets of K Non-Overlapping Line Segments (Medium)](https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/)

<p>Given <code>n</code> points on a 1-D plane, where the <code>i<sup>th</sup></code> point (from <code>0</code> to <code>n-1</code>) is at <code>x = i</code>, find the number of ways we can draw <strong>exactly</strong> <code>k</code> <strong>non-overlapping</strong> line segments such that each segment covers two or more points. The endpoints of each segment must have <strong>integral coordinates</strong>. The <code>k</code> line segments <strong>do not</strong> have to cover all <code>n</code> points, and they are <strong>allowed</strong> to share endpoints.</p>

<p>Return <em>the number of ways we can draw </em><code>k</code><em> non-overlapping line segments</em><em>.</em>&nbsp;Since this number can be huge, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/07/ex1.png" style="width: 179px; height: 222px;">
<pre><strong>Input:</strong> n = 4, k = 2
<strong>Output:</strong> 5
<strong>Explanation: 
</strong>The two line segments are shown in red and blue.
The image above shows the 5 different ways {(0,2),(2,3)}, {(0,1),(1,3)}, {(0,1),(2,3)}, {(1,2),(2,3)}, {(0,1),(1,2)}.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 3, k = 1
<strong>Output:</strong> 3
<strong>Explanation: </strong>The 3 ways are {(0,1)}, {(0,2)}, {(1,2)}.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 30, k = 7
<strong>Output:</strong> 796297179
<strong>Explanation: </strong>The total number of possible ways to draw 7 line segments is 3796297200. Taking this number modulo 10<sup>9</sup> + 7 gives us 796297179.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> n = 5, k = 3
<strong>Output:</strong> 7
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> n = 3, k = 2
<strong>Output:</strong> 1</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= n-1</code></li>
</ul>


**Related Topics**:  
[Recursion](https://leetcode.com/tag/recursion/)

## Solution 1. DP Bottom-up

Let `dp[i][j]` be the number of ways we can draw `j` segments using the first `i` points (`0`th to `i-1`th).

For `dp[i][j]`, we have two options:

1. The last segment doesn't end with `i`th point. This provides `dp[i-1][j]` cases.
1. The last segment ends with `i`th point. Then:
  * If the last segment covers 2 points, there are `dp[i-1][j-1]` cases.
  * If the last segment covers 3 points, there are `dp[i-2][j-1]` cases.
  * ...
  * If the last segment covers `i` points, there are `dp[1][j-1]` cases.

So the 2nd case provides `sum( dp[t][j-1] | 1 <= t <= i-1  )` cases in total.

Note that `i` points can only have `i-1` segments. So to get `j-1` segments, we at least need `j` points. So we can tighten the range of `t` to `j <= t <= i-1`. 

So the 2nd case provides `sum( dp[t][j-1] | j <= t <= i-1 )` cases in total.

Now we have the transition formula:

```
dp[i][j] = dp[i-1][j] + sum( dp[t][j-1] | j <= t <= i-1 )

```

Now condier the edge cases:

When `i == 1`, we only have a single point and can't form any segment, so `dp[1][j] = 0`.

When `j == 0`, we don't need to form any segment, so `dp[i][0] = 1`.

So in sum:

```
dp[i][j] = dp[i-1][j] + sum( dp[t][j-1] | j <= t <= i-1, 1 <= i <= N, 1 <= j <= K )
dp[1][j] = 0
dp[i][0] = 1
```

If we directly use this formula, the solution is as follows. However, this will get TLE.

```cpp
// OJ: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
// Author: github.com/lzl124631x
// Time: O(N^2 * K)
// Space: O(NK)
// NOTE: this solution will get TLE
class Solution {
public:
    int numberOfSets(int n, int k) {
        long mod = 1e9+7;
        vector<vector<long>> dp(n + 1, vector<long>(k + 1));
        for (int i = 0; i < n; ++i) dp[i + 1][0] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = dp[i - 1][j];
                for (int t = j; t <= i - 1; ++t) dp[i][j] = (dp[i][j] + dp[t][j - 1]) % mod;
            }
        }
        return dp[n][k];
    }
};
``` 

It's inefficient because we recompute the `sum` part over and over again.

To avoid repetitive computation, we can use prefix sum:

```
dp[i][j] = dp[i-1][j] + presum(i-1, j-1)
           where presum(i-1, j-1) = sum( dp[t][j-1] | 1 <= t <= i-1 )
```

```cpp
// OJ: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(NK)
class Solution {
public:
    int numberOfSets(int n, int k) {
        long mod = 1e9+7;
        vector<long> presum(k + 1);
        vector<vector<long>> dp(n + 1, vector<long>(k + 1));
        for (int i = 0; i < n; ++i) dp[i + 1][0] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                presum[j - 1] = (presum[j - 1] + dp[i - 1][j - 1]) % mod;
                dp[i][j] = (dp[i - 1][j] + presum[j - 1]) % mod;
            }
        }
        return dp[n][k];
    }
};
```

Since in each iteration we only need `dp[i-1][j-1]` and `dp[i][j-1]`, we can reduce the `dp` array from `N * K` to `1 * K`.

```cpp
// OJ: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(K)
class Solution {
public:
    int numberOfSets(int n, int k) {
        long mod = 1e9+7;
        vector<long> presum(k + 1);
        vector<long> dp(k + 1);
        dp[0] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = k; j >= 1; --j) {
                presum[j - 1] = (presum[j - 1] + dp[j - 1]) % mod;
                dp[j] = (dp[j] + presum[j - 1]) % mod;
            }
        }
        return dp[k];
    }
};
```

## Solution 2. DP Bottom-up

Instead of using prefix sum, we can update the formula.
 

```
dp[i][j] = dp[i-1][j]   + ( dp[1][j-1] + dp[2][j-1] + ... + dp[i-2][j-1] + dp[i-1][j-1] )
dp[i-1][j] = dp[i-2][j] + ( dp[1][j-1] + dp[2][j-1] + ... + dp[i-2][j-1] )
// So
dp[i][j] = 2 * dp[i-1][j] - dp[i-2][j] + dp[i-1][j-1] where 2 <= i <= N
```

```cpp
// OJ: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(NK)
class Solution {
public:
    int numberOfSets(int n, int k) {
        long mod = 1e9+7;
        vector<vector<long>> dp(n + 1, vector<long>(k + 1));
        for (int i = 1; i <= n; ++i) dp[i][0] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = (((dp[i - 1][j] * 2) % mod - dp[i - 2][j] + mod) % mod + dp[i - 1][j - 1]) % mod;
            }
        }
        return dp[n][k];
    }
};
```

## Solution 3. Math

This problem is equivalent to "given `n + k - 1` points, get `k` segments that don't share endpoints.

```cpp
// OJ: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O()
// Ref: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/discuss/898727/C%2B%2B-O(n)-solution-explained-in-detail-using-Stars-and-Bars
const int mod = 1e9 + 7, mx = 2e3 + 10;
int fact[mx], inv[mx], invfact[mx];
int mult(int a, int b) { return (1LL * a * b) % mod; }
int comb(int n, int r) {
    if (r > n) return 0;
    return (1LL * fact[n] * invfact[n - r] % mod) * invfact[r] % mod;
}
class Solution {
    void initInv() {
        fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
        for (int i = 2; i < mx; ++i) {
            fact[i] = mult(fact[i - 1], i);
            inv[i] = mult(inv[mod % i], mod - mod / i);
            invfact[i] = mult(invfact[i - 1], inv[i]);
        }
    }
public:
    int numberOfSets(int n, int k) {
        initInv();
        return comb(n + k - 1, 2 * k);
    }
};
```