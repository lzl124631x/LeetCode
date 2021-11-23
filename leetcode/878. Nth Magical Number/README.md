# [878. Nth Magical Number (Hard)](https://leetcode.com/problems/nth-magical-number/)

<p>A positive integer is <em>magical</em> if it is divisible by either <code>a</code> or <code>b</code>.</p>

<p>Given the three integers <code>n</code>, <code>a</code>, and <code>b</code>, return the <code>n<sup>th</sup></code> magical number. Since the answer may be very large, <strong>return it modulo </strong><code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> n = 1, a = 2, b = 3
<strong>Output:</strong> 2
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> n = 4, a = 2, b = 3
<strong>Output:</strong> 6
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> n = 5, a = 2, b = 4
<strong>Output:</strong> 10
</pre><p><strong>Example 4:</strong></p>
<pre><strong>Input:</strong> n = 3, a = 6, b = 4
<strong>Output:</strong> 8
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>2 &lt;= a, b &lt;= 4 * 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Binary Search + Inclusion-exclusion Principle

```cpp
// OJ: https://leetcode.com/problems/nth-magical-number/
// Author: github.com/lzl124631x
// Time: O(log(N * min(A, B)))
// Space: O(1)
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long L = 2, R = (long long)n * min(a, b), mod = 1e9 + 7;
        auto valid = [&](long long M) { // returns `true` is the number of divisible numbers <= M is greater than or equal to n
            return M / a + M / b - M / (a * b / gcd(a, b)) >= n;
        };
        while (L <= R) {
            long M = L + (R - L) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L % mod;
    }
};
```