# [1175. Prime Arrangements (Easy)](https://leetcode.com/problems/prime-arrangements/)

<p>Return the number of permutations of 1 to <code>n</code> so that prime numbers are at prime indices (1-indexed.)</p>

<p><em>(Recall that an integer&nbsp;is prime if and only if it is greater than 1, and cannot be written as a product of two positive integers&nbsp;both smaller than it.)</em></p>

<p>Since the answer may be large, return the answer <strong>modulo <code>10^9 + 7</code></strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 5
<strong>Output:</strong> 12
<strong>Explanation:</strong> For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1] is not because the prime number 5 is at index 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 100
<strong>Output:</strong> 682289015
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1. Sieve of Eratosthenes

```cpp
// OJ: https://leetcode.com/problems/prime-arrangements/
// Author: github.com/lzl124631x
// Time: O(NloglogN)
// Space: O(N)
class Solution {
    int countPrimes(int n) {
        if (n <= 1) return 0;
        vector<int> prime(n + 1, true);
        int ans = 0, bound = sqrt(n);
        for (int i = 2; i <= n; ++i) {
            if (!prime[i]) continue;
            ++ans;
            if (i > bound) continue;
            for (int j = i * i; j <= n; j += i) prime[j] = false;
        }
        return ans;
    }
public:
    int numPrimeArrangements(int n) {
        int cnt = countPrimes(n), ans = 1, mod = 1e9 + 7;
        for (int i = 1; i <= cnt; ++i) ans = ((long)ans * i) % mod;
        for (int i = 1; i <= n - cnt; ++i) ans = ((long)ans * i) % mod;
        return ans;
    }
};
```