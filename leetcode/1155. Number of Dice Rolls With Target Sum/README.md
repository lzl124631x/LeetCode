# [1155. Number of Dice Rolls With Target Sum (Medium)](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/)

<p>You have <code>d</code> dice, and each die has <code>f</code> faces numbered <code>1, 2, ..., f</code>.</p>

<p>Return the number of possible ways (out of <code>f<sup>d</sup></code>&nbsp;total ways) <strong>modulo <code>10^9 + 7</code></strong> to roll the dice so the sum of the face up numbers equals <code>target</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> d = 1, f = 6, target = 3
<strong>Output:</strong> 1
<strong>Explanation: </strong>
You throw one die with 6 faces.  There is only one way to get a sum of 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> d = 2, f = 6, target = 7
<strong>Output:</strong> 6
<strong>Explanation: </strong>
You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> d = 2, f = 5, target = 10
<strong>Output:</strong> 1
<strong>Explanation: </strong>
You throw two dice, each with 5 faces.  There is only one way to get a sum of 10: 5+5.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> d = 1, f = 2, target = 3
<strong>Output:</strong> 0
<strong>Explanation: </strong>
You throw one die with 2 faces.  There is no way to get a sum of 3.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> d = 30, f = 30, target = 500
<strong>Output:</strong> 222616187
<strong>Explanation: </strong>
The answer must be returned modulo 10^9 + 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= d, f &lt;= 30</code></li>
	<li><code>1 &lt;= target &lt;= 1000</code></li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP Top-down

Let `dp[i][t]` be the number of dice rolls with `i` dices and `t` target sum.

```
dp[i][t] = sum( dp[i-1][t-j] | 1 <= j <= f )

dp[i][t] = 0 if t < d || t > d * f

dp[1][t] = 1 if 1 <= t <= f
```

```cpp
// OJ: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// Author: github.com/lzl124631x
// Time: O(DFT)
// Space: O(DT)
class Solution {
    vector<unordered_map<int, int>> m;
    long mod = 1e9+7;
    int dfs(int d, int f, int target) {
        if (target < d || target > d * f) return 0;
        if (d == 1) return 1; 
        if (m[d].count(target)) return m[d][target];
        long cnt = 0;
        for (int j = 1; j <= f && j <= target; ++j) {
            int c = dfs(d - 1, f, target - j);
            cnt = (cnt + c) % mod;
        }
        return m[d][target] = cnt;
    }
public:
    int numRollsToTarget(int d, int f, int target) {
        m.assign(d + 1, {});
        return dfs(d, f, target);
    }
};
```

## Solution 2. DP Top-down with Optimization

```
dp[i][t] = sum( dp[i-1][t-j] | 1 <= j <= f )

dp[i][t] = dp[i-1][t-1] + dp[i-1][t-2] + ... + dp[i-1][t-f]
dp[i][t-1] =              dp[i-1][t-2] + ... + dp[i-1][t-f] + dp[i-1][t-f-1]

dp[i][t] = dp[i][t-1] + dp[i-1][t-1] - dp[i-1][t-f-1]
```

```cpp
// OJ: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// Author: github.com/lzl124631x
// Time: O(DT)
// Space: O(DT)
class Solution {
    vector<unordered_map<int, int>> m;
    long mod = 1e9+7, f;
    int dfs(int d, int target) {
        if (target < d || target > d * f) return 0;
        if (d == 1) return 1; 
        if (m[d].count(target)) return m[d][target];
        return m[d][target] = (((long)dfs(d, target - 1) + dfs(d - 1, target - 1)) % mod - dfs(d - 1, target - f - 1) + mod) % mod;
    }
public:
    int numRollsToTarget(int d, int f, int target) {
        m.assign(d + 1, {});
        this->f = f;
        return dfs(d, target);
    }
};
```

Using array is always more time efficient.

```cpp
// OJ: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// Author: github.com/lzl124631x
// Time: O(DT)
// Space: O(DT)
class Solution {
    int m[31][1001] = {};
    long mod = 1e9+7, f;
    int dfs(int d, int target) {
        if (target < d || target > d * f) return 0;
        if (d == 1) return 1; 
        if (m[d][target] != -1) return m[d][target];
        return m[d][target] = (((long)dfs(d, target - 1) + dfs(d - 1, target - 1)) % mod - dfs(d - 1, target - f - 1) + mod) % mod;
    }
public:
    int numRollsToTarget(int d, int f, int target) {
        memset(m, -1, sizeof(m));
        this->f = f;
        return dfs(d, target);
    }
};
```

## Solution 3. DP Bottom-up

```cpp
// OJ: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// Author: github.com/lzl124631x
// Time: O(DTF)
// Space: O(DT)
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        long dp[31][1001] = {}, mod = 1e9+7;
        for (int j = 1; j <= f; ++j) dp[1][j] = 1;
        for (int i = 2; i <= d; ++i) {
            for (int t = i; t <= target && t <= i * f; ++t) {
                for (int j = 1; j <= f && j < t; ++j) {
                    dp[i][t] = (dp[i][t] + dp[i - 1][t - j]) % mod;
                }
            }
        }
        return dp[d][target];
    }
};
```

## Solution 4. DP Bottom-up with Optimization

```cpp
// OJ: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// Author: github.com/lzl124631x
// Time: O(DT)
// Space: O(DT)
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        long dp[31][1001] = {}, mod = 1e9+7;
        for (int j = 1; j <= f; ++j) dp[1][j] = 1;
        for (int i = 2; i <= d; ++i) {
            for (int t = i; t <= target && t <= i * f; ++t) {
                dp[i][t] = (dp[i][t - 1] + dp[i - 1][t - 1]) % mod;
                if (t - f - 1 > 0) dp[i][t] = (dp[i][t] - dp[i - 1][t - f - 1] + mod) % mod;
            }
        }
        return dp[d][target];
    }
};
```