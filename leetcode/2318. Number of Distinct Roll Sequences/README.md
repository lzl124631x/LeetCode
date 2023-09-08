# [2318. Number of Distinct Roll Sequences (Hard)](https://leetcode.com/problems/number-of-distinct-roll-sequences)

<p>You are given an integer <code>n</code>. You roll a fair 6-sided dice <code>n</code> times. Determine the total number of <strong>distinct</strong> sequences of rolls possible such that the following conditions are satisfied:</p>
<ol>
	<li>The <strong>greatest common divisor</strong> of any <strong>adjacent</strong> values in the sequence is equal to <code>1</code>.</li>
	<li>There is <strong>at least</strong> a gap of <code>2</code> rolls between <strong>equal</strong> valued rolls. More formally, if the value of the <code>i<sup>th</sup></code> roll is <strong>equal</strong> to the value of the <code>j<sup>th</sup></code> roll, then <code>abs(i - j) &gt; 2</code>.</li>
</ol>
<p>Return <em>the<strong> total number</strong> of distinct sequences possible</em>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>
<p>Two sequences are considered distinct if at least one element is different.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 4
<strong>Output:</strong> 184
<strong>Explanation:</strong> Some of the possible sequences are (1, 2, 3, 4), (6, 1, 2, 3), (1, 2, 3, 1), etc.
Some invalid sequences are (1, 2, 1, 3), (1, 2, 3, 6).
(1, 2, 1, 3) is invalid since the first and third roll have an equal value and abs(1 - 3) = 2 (i and j are 1-indexed).
(1, 2, 3, 6) is invalid since the greatest common divisor of 3 and 6 = 3.
There are a total of 184 distinct sequences possible, so we return 184.</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 22
<strong>Explanation:</strong> Some of the possible sequences are (1, 2), (2, 1), (3, 2).
Some invalid sequences are (3, 6), (2, 4) since the greatest common divisor is not equal to 1.
There are a total of 22 distinct sequences possible, so we return 22.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>

**Companies**:
[ServiceNow](https://leetcode.com/company/servicenow)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Memoization](https://leetcode.com/tag/memoization/)

**Similar Questions**:
* [Dice Roll Simulation (Hard)](https://leetcode.com/problems/dice-roll-simulation/)
* [Paint House III (Hard)](https://leetcode.com/problems/paint-house-iii/)

## Solution 1. DP

Let `dp[i][a][b]` be the number of distinct sequences with `i` rolls and last two numbers being `a` and `b`.

```
dp[i][a][b] = SUM( dp[i-1][x][a] | x != a and x != b and gcd(x,a) == 1 )
dp[2][a][b] = 1 if a != b and gcd(a, b) == 1
```

The answer is `SUM( dp[n][a][b] | a != b and gcd(a,b) == 1 )

```cpp
// OJ: https://leetcode.com/problems/number-of-distinct-roll-sequences
// Author: github.com/lzl124631x
// Time: O(N * D^3) where D is the number of sides on the dice. D=6 in this problem.
// Space: O(N * D^2)
class Solution {
public:
    int distinctSequences(int n) {
        if (n == 1) return 6;
        int mod = 1e9 + 7, dp[10001][7][7] = {}, ans = 0;
        for (int i = 2; i <= n; ++i) {
            for (int a = 1; a <= 6; ++a) {
                for (int b = 1; b <= 6; ++b) {
                    if (a == b || gcd(a, b) != 1) continue;
                    if (i == 2) dp[i][a][b] = 1;
                    else {
                        for (int x = 1; x <= 6; ++x) {
                            if (x != a && x != b && gcd(x, a) == 1) dp[i][a][b] = (dp[i][a][b] + dp[i - 1][x][a]) % mod;
                        }
                    }
                    if (i == n) ans = (ans + dp[i][a][b]) % mod;
                }
            }
        }
        return ans;
    }
};
```

## Solution 2. DP with Space Optimization

```cpp
// OJ: https://leetcode.com/problems/number-of-distinct-roll-sequences
// Author: github.com/lzl124631x
// Time: O(N * D^3)
// Space: O(1)
class Solution {
public:
    int distinctSequences(int n) {
        if (n == 1) return 6;
        int mod = 1e9 + 7, dp[7][7] = {}, ans = 0;
        for (int i = 2; i <= n; ++i) {
            int next[7][7] = {};
            for (int a = 1; a <= 6; ++a) {
                for (int b = 1; b <= 6; ++b) {
                    if (a == b || gcd(a, b) != 1) continue;
                    if (i == 2) next[a][b] = 1;
                    else {
                        for (int x = 1; x <= 6; ++x) {
                            if (x != a && x != b && gcd(x, a) == 1) next[a][b] = (next[a][b] + dp[x][a]) % mod;
                        }
                    }
                    if (i == n) ans = (ans + next[a][b]) % mod;
                }
            }
            swap(dp, next);
        }
        return ans;
    }
};
```