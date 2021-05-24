# [1866. Number of Ways to Rearrange Sticks With K Sticks Visible (Hard)](https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/)

<p>There are <code>n</code> uniquely-sized sticks whose lengths are integers from <code>1</code> to <code>n</code>. You want to arrange the sticks such that <strong>exactly</strong> <code>k</code>&nbsp;sticks are <strong>visible</strong> from the left. A stick&nbsp;is <strong>visible</strong> from the left if there are no <strong>longer</strong>&nbsp;sticks to the <strong>left</strong> of it.</p>

<ul>
	<li>For example, if the sticks are arranged <code>[<u>1</u>,<u>3</u>,2,<u>5</u>,4]</code>, then the sticks with lengths <code>1</code>, <code>3</code>, and <code>5</code> are visible from the left.</li>
</ul>

<p>Given <code>n</code> and <code>k</code>, return <em>the <strong>number</strong> of such arrangements</em>. Since the answer may be large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 3, k = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> [<u>1</u>,<u>3</u>,2], [<u>2</u>,<u>3</u>,1], and [<u>2</u>,1,<u>3</u>] are the only arrangements such that exactly 2 sticks are visible.
The visible sticks are underlined.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 5, k = 5
<strong>Output:</strong> 1
<strong>Explanation:</strong> [<u>1</u>,<u>2</u>,<u>3</u>,<u>4</u>,<u>5</u>] is the only arrangement such that all 5 sticks are visible.
The visible sticks are underlined.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 20, k = 11
<strong>Output:</strong> 647427950
<strong>Explanation:</strong> There are 647427950 (mod 10<sup>9 </sup>+ 7) ways to rearrange the sticks such that exactly 11 sticks are visible.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

**Intuition**: A DP problem. For `dp(n, k)`, we have two options, use `1` as the first number or not to use it.

**Algorithm**:

For `dp(n, k)`:
* If we pick `1` as the first number, we need to use the rest `n-1` numbers to get `k-1` visible numbers. So this will add `dp(n-1, k-1)` to the answer
* If we don't pick `1` as the first number, we need to use the rest `n-1` numbers to get `k` visible numbers, i.e. `dp(n-1, k)` cases. We can put `1` after one of the `n-1` numbers so we need to multiply it by `n-1`. This in total will add `dp(n-1, k) * (n-1)` cases.

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(NK)
class Solution {
    long dp[1001][1001] = {}, mod = 1e9 + 7;
    long dfs(int n, int k) {
        if (n < k || k == 0) return 0;
        if (k == n) return 1;
        if (dp[n][k]) return dp[n][k];
        long ans = 0;
        ans = (ans + dfs(n - 1, k - 1)) % mod; // if we pick `1` as the first number, there will be `dp(n - 1, k - 1)` cases
        ans = (ans + dfs(n - 1, k) * (n - 1) % mod) % mod; // if we don't pick `1` as the first number, there will be `dp(n - 1, k) * (n-1)` cases
        return dp[n][k] = ans;
    }
public:
    int rearrangeSticks(int n, int k) {
        memset(dp, 0, sizeof(dp));
        return dfs(n, k);
    }
};
```

When `k == 1`, there will be `(n-1)!` cases. So we can precompute the factorials to save time.

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(Nk)
long dp[1001][1001] = {}, fact[1001] = {}, mod = 1e9 + 7;
class Solution {
    long dfs(int n, int k) {
        if (n < k) return 0;
        if (k == n) return 1;
        if (k == 1) return fact[n - 1];
        if (dp[n][k]) return dp[n][k];
        long ans = 0;
        ans = (ans + dfs(n - 1, k) * (n - 1) % mod) % mod;
        ans = (ans + dfs(n - 1, k - 1)) % mod;
        return dp[n][k] = ans;
    }
public:
    int rearrangeSticks(int n, int k) {
        memset(dp, 0, sizeof(dp));
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fact[i] = (fact[i - 1] * i) % mod; // fact(n) = n!
        }
        return dfs(n, k);
    }
};
```

## Solution 2. Bottom-up DP

```
dp[i][j] = dp[i-1][j-1]  // if we pick 1 as the first number
            + dp[i-1][j] * (i-1) // if we don't pick 1 as the first number
            where i >= j
dp[0][0] = 1
dp[i][j] = 0 if i < j
```

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(NK)
class Solution {
public:
    int rearrangeSticks(int n, int k) {
        long mod = 1e9 + 7;
        vector<vector<long>> dp(n + 1, vector<long>(k + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * (i - 1) % mod) % mod;
            }
        }
        return dp[n][k];
    }
};
```

Since `dp[i][j]` is only dependent on `dp[i-1][j-1]` and `dp[i-1][j]`, we can reduce the space complexity from `O(NK)` to `O(K)`.

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(K)
class Solution {
public:
    int rearrangeSticks(int n, int k) {
        long mod = 1e9 + 7;
        vector<long> dp(k + 1);
        for (int i = 1; i <= n; ++i) {
            dp[0] = i == 1; // Note that dp[i][0] = 1 only if i == 0; otherwise dp[i][0] = 0.
            for (int j = min(i, k); j >= 1; --j) {
                dp[j] = (dp[j - 1] + dp[j] * (i - 1) % mod) % mod;
            }
        }
        return dp[k];
    }
};
```