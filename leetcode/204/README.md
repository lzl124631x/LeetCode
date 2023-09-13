# [204. Count Primes (Easy)](https://leetcode.com/problems/count-primes/)

<p>Count the number of prime numbers less than a non-negative number, <code>n</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 10
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 0
<strong>Output:</strong> 0
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 5 * 10<sup>6</sup></code></li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Ugly Number (Easy)](https://leetcode.com/problems/ugly-number/)
* [Ugly Number II (Medium)](https://leetcode.com/problems/ugly-number-ii/)
* [Perfect Squares (Medium)](https://leetcode.com/problems/perfect-squares/)

## Solution 1. Sieve of Eratosthenes

```cpp
// OJ: https://leetcode.com/problems/count-primes/
// Author: github.com/lzl124631x
// Time: O(NloglogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/count-primes/solution/
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0;
        vector<bool> prime(n, true);
        int ans = 0, bound = sqrt(n);
        for (int i = 2; i < n; ++i) {
            if (!prime[i]) continue;
            ++ans;
            if (i > bound) continue; // If i > bound, then i * i must be greater than `n`, skip. This can prevent overflow caused by `i * i`.
            for (int j = i * i; j < n; j += i) prime[j] = false; // note that we start from `i * i` instead of `2` because all multiples of `2, 3, ..., (i-1)` must be marked already
        }
        return ans;
    }
};
```