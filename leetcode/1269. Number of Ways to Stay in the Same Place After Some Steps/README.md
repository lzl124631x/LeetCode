# [1269. Number of Ways to Stay in the Same Place After Some Steps (Hard)](https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/)

<p>You have a pointer at index <code>0</code> in an array of size <code><font face="monospace">arrLen</font></code>. At each step, you can move 1 position to the left, 1 position to the right&nbsp;in the array or stay in the same place&nbsp; (The pointer should not be placed outside the array at any time).</p>

<p>Given two integers&nbsp;<code>steps</code> and <code>arrLen</code>, return the number of&nbsp;ways such that your pointer still at index <code>0</code> after <strong>exactly </strong><code><font face="monospace">steps</font></code>&nbsp;steps.</p>

<p>Since the answer&nbsp;may be too large,&nbsp;return it <strong>modulo</strong>&nbsp;<code>10^9 + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> steps = 3, arrLen = 2
<strong>Output:</strong> 4
<strong>Explanation: </strong>There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> steps = 2, arrLen = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> steps = 4, arrLen = 2
<strong>Output:</strong> 8
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= steps &lt;= 500</code></li>
	<li><code>1 &lt;= arrLen&nbsp;&lt;= 10^6</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Let `dp[i][j]` be the number of ways to reach `0` from index `j` when there are `i` steps left.

```
dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]
dp[0][0] = 1
```

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
// Author: github.com/lzl124631x
// Time: O(SL)
// Space: O(1)
class Solution {
    typedef long long LL;
public:
    int numWays(int steps, int arrLen) {
        LL dp[2][251] = {0}, diff[3] = {-1, 0, 1}, mod = 1e9+7;
        dp[0][0] = 1;
        arrLen = min(251, arrLen);
        for (int i = 1; i <= steps; ++i) {
            for (int j = 0; j < arrLen; ++j) {
                dp[i % 2][j] = 0;
                for (int d : diff) {
                    int t = j + d;
                    if (t < 0 || t >= arrLen) continue;
                    dp[i % 2][j] = (dp[i % 2][j] + dp[(i - 1) % 2][t]) % mod;
                }
            }
        }
        return dp[steps % 2][0];
    }
};
```

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
// Author: github.com/lzl124631x
// Time: O(S * min(S, L))
// Space: O(min(S, L))
// Ref: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/discuss/436392/C%2B%2B-Bottom-Up-DP
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int N = min(steps / 2 + 1, arrLen);
        vector<int> a(N + 2), b(N + 2);
        a[1] = 1;
        while (steps--) {
            for (int i = 1; i <= N; ++i) b[i] = ((long)a[i - 1] + a[i] + a[i + 1]) % ((int)1e9+7);
            swap(a, b);
        }
        return a[1];
    }
};
```