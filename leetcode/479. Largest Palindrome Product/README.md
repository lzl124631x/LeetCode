# [479. Largest Palindrome Product (Hard)](https://leetcode.com/problems/largest-palindrome-product/)

<p>Given an integer n, return <em>the <strong>largest palindromic integer</strong> that can be represented as the product of two <code>n</code>-digits integers</em>. Since the answer can be very large, return it <strong>modulo</strong> <code>1337</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 987
Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 9
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 8</code></li>
</ul>


**Companies**:  
[Yahoo](https://leetcode.com/company/yahoo)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

Traverse from greatest to smallest palindromic numbers that might be products of two `n`-digit integers. We do so by enumerating the first half of the palindromic number. 

For example, if `n = 2`, we enumerate `half` as `99, 98, 97, ...` and the corresponding palindromic numbers are `9999, 9889, 9779, ...`.

The maximum value of `half` is `mx = 10^n - 1`.

Unproven: The minimum value of `half` we need to check is `mn = 10^(n-1)`. `n = 1` is the only exception and we should return `9` directly.

To check if a palindrome number `pal` is a product of two `n`-digit integers, a brute force way is to enumerate `mn <= x <= mx` and check if `pal` is divisible by `x` and `pal / x` is a `n`-digit integer. This takes `O(10^N * N)` time.

To improve the efficiency, we need to think of a tighter range. Say `x * y = pal`, and `x` is decreasing from `mx` to `mn`. The symmetric point for the `x` and `y` values is `sqrt(pal)`, so we only need to check `x <= sqrt(pal)` or `x >= sqrt(pal)`.

However, the `x <= sqrt(pal)` side might results in some invalid values. For example, `pal=9999` if `x = 11`, `pal / x = 909` is not an `n`-digit number.

On the other hand, `x >= sqrt(pal)` side guarantees that both `x` and `pal / x` are `n`-digit integers.

For example, for `n = 2, mx = 99`:

If `pal = 9999`, `x`'s range is `sqrt(9999) = 99.99 <= x <= 99`. Note that this range is empty. `pal / x`'s range is `101 <= pal/x <= 99.99`

If `pal = 1001`, `x`'s range is `sqrt(1001) = 31.64 <= x <= 99`. `pal / x`'s range is `1001 / 99 = 10.11 <= pal/x <= 31.64`. Both `x` and `pal / x` are `n`-digit integers.

A more efficient way is to enumerate `x` from `mx` to `sqrt(pal)` (so that we make sure `x >= pal / x` and don't need to do the unnecessary computations for numbers `< pal / x`) and only check if `pal` is divisible by `x`.

```cpp
// OJ: https://leetcode.com/problems/largest-palindrome-product/
// Author: github.com/lzl124631x
// Time: O(10^N)
// Space: O(1)
class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        int mod = 1337, mx = pow(10, n) - 1, mn = pow(10, n - 1);
        auto valid = [&](long pal) {
            for (long i = mx; i * i >= pal; --i) {
                if (pal % i == 0) return true;
            }
            return false;
        };
        for (int half = mx; half >= mn; --half) {
            long pal = half, tmp = half;
            for (; tmp; tmp /= 10) pal = pal * 10 + (tmp % 10);
            if (valid(pal)) return pal % mod;
        }
        return -1;
    }
};
```

## TODO

read https://leetcode.com/problems/largest-palindrome-product/discuss/96306/Java-solutions-with-two-different-approaches