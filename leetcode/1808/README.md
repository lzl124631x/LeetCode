# [1808. Maximize Number of Nice Divisors (Hard)](https://leetcode.com/problems/maximize-number-of-nice-divisors/)

<p>You are given a positive integer <code>primeFactors</code>. You are asked to construct a positive integer <code>n</code> that satisfies the following conditions:</p>

<ul>
  <li>The number of prime factors of <code>n</code> (not necessarily distinct) is <strong>at most</strong> <code>primeFactors</code>.</li>
  <li>The number of nice divisors of <code>n</code> is maximized. Note that a divisor of <code>n</code> is <strong>nice</strong> if it is divisible by every prime factor of <code>n</code>. For example, if <code>n = 12</code>, then its prime factors are <code>[2,2,3]</code>, then <code>6</code> and <code>12</code> are nice divisors, while <code>3</code> and <code>4</code> are not.</li>
</ul>

<p>Return <em>the number of nice divisors of</em> <code>n</code>. Since that number can be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>Note that a prime number is a natural number greater than <code>1</code> that is not a product of two smaller natural numbers. The prime factors of a number <code>n</code> is a list of prime numbers such that their product equals <code>n</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> primeFactors = 5
<strong>Output:</strong> 6
<strong>Explanation:</strong> 200 is a valid value of n.
It has 5 prime factors: [2,2,2,5,5], and it has 6 nice divisors: [10,20,40,50,100,200].
There is not other value of n that has at most 5 prime factors and more nice divisors.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> primeFactors = 8
<strong>Output:</strong> 18
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= primeFactors &lt;= 10<sup>9</sup></code></li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Integer Break (Medium)](https://leetcode.com/problems/integer-break/)

# Solution 1.

Consider the example case where `F = 5`, `200` is a valid value of `n`, `[2,2,2,5,5]` are the prime factors.

To construct nice divisors, we can get them by multiplying `1~3` number `2`s and `1~2` number `5`s. So there are `3 * 2 = 6` nice divisors.

So this question is equivalent to: Given a number `F`, find an optimal way of breaking `F = a + b + c + d + ...`, such that `a * b * c * d ...` is maximized. (In this problem, `a, b, c, d...` are the counts of different primes)

We can reuse the solution to [Breaking an Integer to get Maximum Product](https://www.geeksforgeeks.org/breaking-integer-to-get-maximum-product/) or [343. Integer Break (Medium)](https://leetcode.com/problems/integer-break/)

```cpp
// OJ: https://leetcode.com/problems/maximize-number-of-nice-divisors/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
    long mod = 1e9+7;
public:
    long modpow(long base, long exp) {
        long ans = 1;
        while (exp > 0) {
            if (exp & 1) ans = (ans * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return ans;
    }
    int maxNiceDivisors(int N) {
        if (N <= 3) return N;
        long ans;
        switch (N % 3) {
            case 0: ans = modpow(3, N / 3); break;
            case 1: ans = 2 * 2 * modpow(3, N / 3 - 1); break;
            case 2: ans = 2 * modpow(3, N / 3); break;
        }
        return ans % mod;
    }
};
```