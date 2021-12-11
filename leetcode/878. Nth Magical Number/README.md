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


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Binary Search + Inclusion-exclusion Principle

`L <= R` template.

```cpp
// OJ: https://leetcode.com/problems/nth-magical-number/
// Author: github.com/lzl124631x
// Time: O(log(N * min(A, B)))
// Space: O(1)
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long L = 2, R = (long)n * min(a, b), mod = 1e9 + 7;
        auto valid = [&](long M) { // returns `true` is the number of divisible numbers <= M is greater than or equal to n
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

Or `L < R` template

```cpp
// OJ: https://leetcode.com/problems/nth-magical-number/
// Author: github.com/lzl124631x
// Time: O(log(N * min(A, B)))
// Space: O(1)
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long L = 2, R = (long)n * min(a, b), mod = 1e9 + 7;
        auto valid = [&](long M) { // returns `true` is the number of divisible numbers <= M is greater than or equal to n
            return M / a + M / b - M / (a * b / gcd(a, b)) >= n;
        };
        while (L < R) {
            long M = L + (R - L) / 2;
            if (valid(M)) R = M;
            else L = M + 1;
        }
        return L % mod;
    }
};
```

## Solution 2. Math

The pattern of magical numbers repeats.

Let `L` be the least common multiple of `a` and `b`. If `x < L` is magical, then `x + L` is magical. Because, say `x = k * a`, `L = a * b / gcd(a, b)`, then `x + L = [k + b / gcd(a,b)] * a`. Example: `a = 3, b = 11, L = 33, x = 6, x + L = 39`.

There are `M = L/a + L/b - 1` magical numbers `<= L`:
* `L/a` of them are divisible by `a`
* `L/b` of them are divisible by `b`
* `1` of them are divisible by both `a` and `b`.

So, for the first `L` numbers `[1, L]`, there are `M` of them are magical. Adding `L` to each of them, we know that for the second `L` numbers `[L+1, 2L]`, there are also `M` magical numbers. And so on.

Suppose `n = M * q + r` and `r < M`. The first `L * q` numbers contain `M * q` magical numbers.

For the remainder `r` magical numbers, we enumerate the smallest `r` numbers among `a, 2a, 3a, ...` and `b, 2b, 3b, ...`.

Time complexity: The calculation of the `r`th magical number after `q * M` is `O(M) = O(A + B)`.

```cpp
// OJ: https://leetcode.com/problems/nth-magical-number/
// Author: github.com/lzl124631x
// Time: O(A + B)
// Space: O(1)
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long mod = 1e9 + 7, L = a * b / gcd(a, b), M = L / a + L / b - 1, q = n / M, r = n % M, ans = (long)q * L % mod;
        int val[2] = {0, 0};
        for (int i = 0; i < r; ++i) {
            auto [x, y] = val;
            if (x <= y) val[0] += a;
            if (y <= x) val[1] += b;
        }
        ans += min(val[0], val[1]);
        return ans % mod;
    }
};
```