# [2478. Number of Beautiful Partitions (Hard)](https://leetcode.com/problems/number-of-beautiful-partitions)

<p>You are given a string <code>s</code> that consists of the digits <code>'1'</code> to <code>'9'</code> and two integers <code>k</code> and <code>minLength</code>.</p>
<p>A partition of <code>s</code> is called <strong>beautiful</strong> if:</p>
<ul>
	<li><code>s</code> is partitioned into <code>k</code> non-intersecting substrings.</li>
	<li>Each substring has a length of <strong>at least</strong> <code>minLength</code>.</li>
	<li>Each substring starts with a <strong>prime</strong> digit and ends with a <strong>non-prime</strong> digit. Prime digits are <code>'2'</code>, <code>'3'</code>, <code>'5'</code>, and <code>'7'</code>, and the rest of the digits are non-prime.</li>
</ul>
<p>Return<em> the number of <strong>beautiful</strong> partitions of </em><code>s</code>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>
<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "23542185131", k = 3, minLength = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> There exists three ways to create a beautiful partition:
"2354 | 218 | 5131"
"2354 | 21851 | 31"
"2354218 | 51 | 31"
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "23542185131", k = 3, minLength = 3
<strong>Output:</strong> 1
<strong>Explanation:</strong> There exists one way to create a beautiful partition: "2354 | 218 | 5131".
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s = "3312958", k = 3, minLength = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> There exists one way to create a beautiful partition: "331 | 29 | 58".
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= k, minLength &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of the digits <code>'1'</code> to <code>'9'</code>.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Restore The Array (Hard)](https://leetcode.com/problems/restore-the-array/)
* [Number of Ways to Separate Numbers (Hard)](https://leetcode.com/problems/number-of-ways-to-separate-numbers/)

## Solution 1. DP

Let `dp[k][i+1]` be the number of `k`-partitions using `A[0..i]` (`A[i]` must be non-prime).


```
dp[k][i+1] = sum( dp[k-1][j] | A[j] is prime, 0 <= j <= i - minLen + 1 )
dp[0][0] = 1
```

The answer is `dp[K][N]`.

Since `dp[k][i+1]` only depends on the values in the previous row, we can reduce the space complexity from `O(KN)` to `O(N)`.

```cpp
// OJ: https://leetcode.com/problems/number-of-beautiful-partitions
// Author: github.com/lzl124631x
// Time: O(KN)
// Space: O(N)
class Solution {
    bool isPrime(char c) {
        return c == '2' || c == '3' || c == '5' || c == '7';
    }
public:
    int beautifulPartitions(string s, int K, int minLen) {
        long N = s.size(), mod = 1e9 + 7;
        vector<long> dp(N + 1);
        dp[0] = 1;
        for (int k = 1; k <= K; ++k) {
            vector<long> next(N + 1);
            long sum = 0;
            for (int i = 0; i < N; ++i) {
                if (i - minLen + 1 >= 0 && isPrime(s[i - minLen + 1])) sum = (sum + dp[i - minLen + 1]) % mod;
                if (!isPrime(s[i])) {
                    next[i + 1] = (next[i + 1] + sum) % mod;
                }
            }
            swap(dp, next);
        }
        return dp[N];
    }
};
```