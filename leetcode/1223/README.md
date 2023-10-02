# [1223. Dice Roll Simulation (Medium)](https://leetcode.com/problems/dice-roll-simulation/)

<p>A die simulator generates a random number from 1 to 6 for each roll.&nbsp;You introduced a constraint to the generator such that it cannot roll the number <code>i</code> more than <code>rollMax[i]</code> (1-indexed) <strong>consecutive</strong> times.&nbsp;</p>

<p>Given an array of integers&nbsp;<code>rollMax</code>&nbsp;and an integer&nbsp;<code>n</code>, return the number of distinct sequences that can be obtained with exact <code>n</code> rolls.</p>

<p>Two sequences are considered different if at least one element differs from each other. Since the answer&nbsp;may be too large,&nbsp;return it modulo <code>10^9 + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 2, rollMax = [1,1,2,2,2,3]
<strong>Output:</strong> 34
<strong>Explanation:</strong> There will be 2 rolls of die, if there are no constraints on the die, there are 6 * 6 = 36 possible combinations. In this case, looking at rollMax array, the numbers 1 and 2 appear at most once consecutively, therefore sequences (1,1) and (2,2) cannot occur, so the final answer is 36-2 = 34.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2, rollMax = [1,1,1,1,1,1]
<strong>Output:</strong> 30
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 3, rollMax = [1,1,1,2,2,3]
<strong>Output:</strong> 181
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
	<li><code>rollMax.length == 6</code></li>
	<li><code>1 &lt;= rollMax[i] &lt;= 15</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Let `dp[i][j]` be the number of distinct sequences ending with `j` obtained using `i` rolles.

```
dp[1][j] = 1       1 <= j <= 6
```

Ignoring the `rollMax`, we have `dp[i][j] = sum( dp[i-1][k] | 1 <= k <= 6 )`.

If we pick `j` at `i` roll, we need to exclude the cases where there are already `rollMax[j]` `j` numbers right in front of `i`th roll.

The number of such cases is `dp[i-rollMax[j]-1][k]` where `1 <= k <= 6` and `k != j`.

```cpp
// OJ: https://leetcode.com/problems/dice-roll-simulation/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/dice-roll-simulation/discuss/403756/Java-Share-my-DP-solution
class Solution {
public:
    int dieSimulator(int n, vector<int>& A) {
        long mod = 1e9+7;
        vector<vector<long>> dp(n, vector<long>(7));
        for (int i = 0; i < 6; ++i) dp[0][i] = 1;
        dp[0][6] = 6;
        for (int i = 1; i < n; ++i) {
            long sum = 0;
            for (int j = 0; j < 6; ++j) {
                dp[i][j] = dp[i - 1][6];
                if (i < A[j]) sum = (sum + dp[i][j]) % mod;
                else {
                    if (i - A[j] - 1 >= 0) dp[i][j] = (dp[i][j] - (dp[i - A[j] - 1][6] - dp[i - A[j] - 1][j]) + mod) % mod;
                    else dp[i][j] = (dp[i][j] - 1) % mod;
                    sum = (sum + dp[i][j]) % mod;
                }
            }
            dp[i][6] = sum;
        }
        return dp[n - 1][6];
    }
};
```