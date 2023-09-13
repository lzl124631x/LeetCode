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

## Solution 1. Generating palindromic products

**Intuition**: Generate palindromic numbers of length `2n` in descending order. For each number, test if it can be divided into two integers of length `n`.

**Algorithm**: 

Traverse from greatest to smallest palindromic numbers that might be products of two `n`-digit integers. We do so by enumerating the first half of the palindromic number. 

For example, if `n = 2`, we enumerate `half` as `99, 98, 97, ...` and the corresponding palindromic numbers are `9999, 9889, 9779, ...`.

The maximum value of `half` is `mx = 10^n - 1`.

For `n >= 2`, we can always find the greatest palindromic product of length `2n`. So, the minimum value of `half` we need to check is `mn = 10^(n-1)`. `n = 1` is the only exception and we should return `9` directly.

To check if a palindrome number `pal` is a product of two `n`-digit integers, a brute force way is to enumerate `mn <= x <= mx` and check if `pal` is divisible by `x` and `pal / x` is a `n`-digit integer. This takes `O(10^N * N)` time.

To improve the efficiency, we need to think of a tighter range. Say `x * y = pal`, and `x` is decreasing from `mx` to `mn`. The symmetric point for the `x` and `y` values is `sqrt(pal)`, so we only need to check `x <= sqrt(pal)` or `x >= sqrt(pal)`.

However, the `x <= sqrt(pal)` side might results in some invalid values. For example, `pal=9999` if `x = 11`, `pal / x = 909` is not an `n`-digit number.

On the other hand, `x >= sqrt(pal)` side guarantees that both `x` and `pal / x` are `n`-digit integers.

For example, for `n = 2, mx = 99`:

If `pal = 9999`, `x`'s range `sqrt(9999) = 99.99 <= x <= 99` is empty. The first `pal` whose `x`'s range is not empty is `pal / x`'s range is `9779`. The corresponding `x`'s range is `sqrt(9779) = 98.89 <= x <= 99`, and `9779/99 = 98.78 <= pal/x <= 98.89`.

If `pal = 1001`, `x`'s range is `sqrt(1001) = 31.64 <= x <= 99`. `pal / x`'s range is `1001 / 99 = 10.11 <= pal/x <= 31.64`. Both `x` and `pal / x` are `n`-digit integers.

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
            for (long div = mx; div * div >= pal; --div) {
                if (pal % div == 0) return true;
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

## Solution 2. Start from two multipliers

Use a max heap of `(a * b, a, b)` where `a, b` starts from `9..9` and `a >= b`. Each time a new item popped from the heap, we test if `a * b` is a palindrome. If not, we extend `((a-1) * b, a-1, b)` if `a-1 >= b`, and `(a * (b-1), a, b-1)` if `a == 9..9`. This turns to get TLE. We need to further prune the entries in the heap.

Since the product starts and ends with digit `9`, the two numbers must end with digits `1, 3, 7, 9`. 

```cpp
// OJ: https://leetcode.com/problems/largest-palindrome-product/
// Author: github.com/lzl124631x
// Time: O(?)
// Space: O(?)
class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        auto cmp = [](auto &a, auto &b) {
            return a[0] * a[1] < b[0] * b[1];
        };
        priority_queue<array<long, 2>, vector<array<long, 2>>, decltype(cmp)> pq(cmp);
        long mod = 1337, mx = pow(10L, n) - 1, mn = pow(10L, n - 1);
        pq.push({mx, mx - 8}); // 9 x 1
        pq.push({mx - 2, mx - 2}); // 7 x 7 
        pq.push({mx - 6, mx - 6}); // 3 x 3
        pq.push({mx - 8, mx - 11}); // 1 x 9
        auto isPalindrome = [](long prod) {
            long r = 0, tmp = prod;
            for (; tmp; tmp /= 10) r = 10 * r + tmp % 10;
            return r == prod;
        };
        while (pq.size()) {
            auto [a, b] = pq.top();
            pq.pop();
            if (isPalindrome(a * b)) return a * b % mod;
            if (a - 10 >= b) pq.push({a - 10, b});
            if (a == mx || a == mx - 2 || a == mx - 6 || a == mx - 8) pq.push({a, b - 10});
        }
        return 0;
    }
};
```

## Solution 3.

pow10|maxPal|mx|t
---|---|---|---
2|100|9009|90|9
3|1000|968407|968|89
4|10000|99000099|9900|909
5|100000|9968377538|99683|9089
6|1000000|999000000999|999000|90909
7|10000000|99968377226559|9996837|909089
8|100000000|9999000000010000|99990000|9090909

TODO: add explanation

```cpp
// OJ: https://leetcode.com/problems/largest-palindrome-product/
// Author: github.com/lzl124631x
// Time: O(?)
// Space: O(?)
class Solution {
    long getPalindrome(long half) {
        long ans = half;
        for (; half; half /= 10) ans = 10 * ans + half % 10;
        return ans;
    }
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        long pow10 = pow(10L, n);
        long maxPal = (pow10 - 1) * (pow10 - sqrt(pow10) + 1); // maximum possible palindrome
        long mx = maxPal / pow10, t = pow10 / 11; // `mx` is the maximum possible first half. `t` is the maximum divisor.
        t -= ~t & 1; // if `t` is even, decrement `t`.
        for (long half = mx; half > 0; --half) {
            for (long div = t, pal = getPalindrome(half); div >= half / 11; div -= 2) {
                if (pal %  div == 0) return pal % 1337;
            }
        }
        return 0;
    }
};
```

## Solution 4.

TODO: add explanation

```cpp
// OJ: https://leetcode.com/problems/largest-palindrome-product/
// Author: github.com/lzl124631x
// Time: O(?)
// Space: O(?)
// Ref: https://leetcode-cn.com/problems/largest-palindrome-product/solution/mei-ju-shu-xue-by-megurine-p1bn/
typedef long long ll;
class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        ll m = (int) pow(10, n);
        for (ll x = 2; x < m; ++x) {
            ll upper = m - x;
            string s = to_string(upper);
            reverse(s.begin(), s.end());
            ll lower = stoi(s);
            ll tmp = x * x - 4 * lower;
            if (tmp < 0) continue;
            ll sq = (ll) sqrt(tmp);
            if (sq * sq == tmp) {
                return (int) ((upper * m + lower) % 1337);
            }
        }
        return -1;
    }
};
```

## NOTE

Good article: https://leetcode.com/problems/largest-palindrome-product/discuss/96306/Java-solutions-with-two-different-approaches