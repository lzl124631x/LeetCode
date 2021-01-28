# [1680. Concatenation of Consecutive Binary Numbers (Medium)](https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/)

<p>Given an integer <code>n</code>, return <em>the <strong>decimal value</strong> of the binary string formed by concatenating the binary representations of </em><code>1</code><em> to </em><code>n</code><em> in order, <strong>modulo </strong></em><code>10<sup>9 </sup>+ 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 1
<strong>Explanation: </strong>"1" in binary corresponds to the decimal value 1. 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> 27
<strong>Explanation: </strong>In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 12
<strong>Output:</strong> 505379714
<strong>Explanation</strong>: The concatenation results in "1101110010111011110001001101010111100".
The decimal value of that is 118505380540.
After modulo 10<sup>9</sup> + 7, the result is 505379714.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1. 

Let `f(n)` be the answer. `sum_len(a, b) = sum( len(i) | a <= i <= b)` and `len(i)` is the number of bits in `i`.

For example: `len(1) = 1`, `len(3) = 2`, `len(6) = 3`. `sum_len(1,4) = len(1) + len(2) + len(3) + len(4) = 1 + 2 + 2 + 3 = 8`.

So we have

```plaintext
f(n)   = (1 << sum_len(2, n))   + (2 << sum_len(3, n))   + ... + ((n - 1) << sum_len(n, n)) + (n << 0)

// Example: f(4) = 11011100 = (1 << (2+2+3)) + (2 << (2+3)) + (3 << 3) +(4 << 0)

f(n-1) = (1 << sum_len(2, n-1)) + (2 << sum_len(3, n-1)) + ... + ((n - 1) << 0)

f(n) = (f(n-1) << len(n)) + n
```

Since `f(0) = 0`, we can iteratively build `f(n)`.

```plaintext
f(0) = 0
f(1) = 1     = (f(0) << 1) + 1  // len(1) = 1
f(2) = 110   = (f(1) << 2) + 2  // len(2) = 2
f(3) = 11011 = (f(2) << 2) + 3  // len(3) = 2
...
```

```cpp
// OJ: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0, mod = 1e9+7;
        for (int i = 1; i <= n; ++i) {
            int len = 0;
            for (int j = i; j; j >>= 1, ++len);
            ans = ((ans << len) % mod + i) % mod;
        }
        return ans;
    }
};
```

## Solution 2.

We spent `O(logN)` time for calculating the `len`. We can reduce it to `O(1)` with the help of `__builtin_clz` which returns the number of leading zeros for a number, so `len = 32 - __builtin_clz(i)`.

```cpp
// OJ: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0, mod = 1e9+7;
        for (int i = 1; i <= n; ++i) ans = ((ans << (32 - __builtin_clz(i))) % mod + i) % mod;
        return ans;
    }
};
```

Or, with the observation that the `len` only increment when the `i` is a power of `2`, we can increment `len` only when `i` has a single bit `1`. We can check this via `(i & (i - 1)) == 0` or `__builtin_popcount(i) == 1`.

```cpp
// OJ: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0, mod = 1e9+7, len = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) ++len;
            ans = ((ans << len) % mod + i) % mod;
        }
        return ans;
    }
};
```