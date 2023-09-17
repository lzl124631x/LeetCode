# [313. Super Ugly Number (Medium)](https://leetcode.com/problems/super-ugly-number)

<p>A <strong>super ugly number</strong> is a positive integer whose prime factors are in the array <code>primes</code>.</p>

<p>Given an integer <code>n</code> and an array of integers <code>primes</code>, return <em>the</em> <code>n<sup>th</sup></code> <em><strong>super ugly number</strong></em>.</p>

<p>The <code>n<sup>th</sup></code> <strong>super ugly number</strong> is <strong>guaranteed</strong> to fit in a <strong>32-bit</strong> signed integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 12, primes = [2,7,13,19]
<strong>Output:</strong> 32
<strong>Explanation:</strong> [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1, primes = [2,3,5]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 1 has no prime factors, therefore all of its prime factors are in the array primes = [2,3,5].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= primes.length &lt;= 100</code></li>
	<li><code>2 &lt;= primes[i] &lt;= 1000</code></li>
	<li><code>primes[i]</code> is <strong>guaranteed</strong> to be a prime number.</li>
	<li>All the values of <code>primes</code> are <strong>unique</strong> and sorted in <strong>ascending order</strong>.</li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Math](https://leetcode.com/tag/math), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming)

**Similar Questions**:
* [Ugly Number II (Medium)](https://leetcode.com/problems/ugly-number-ii)

## Solution 1.

`v[i]` is the `i`-th super ugly number. `v[0] = 1`.

Assume we've already computed `v[0..i]`. The next `v[i+1]` must be some `v[j] (0 <= j <= i)` multiplied by a prime number in `primes`.

Let `p[i]` be the index to the next extensible number corresponding to `primes[i]`. That is, `v[p[i]] * primes[i]` is the next number extended using `primes[i]`.

```
2/7/13
v
1

// 1 * 2 is the smallest next extension

7/13  2
v     v
1     2

// 2 * 2 is the smallest next extension

7/13    2
v       v
1     2 4

// 1 * 7 is the smallest next extension

13    7 2 
v     v v 
1     2 4 7

// 4 * 2 is the smallest next extension

13    7   2
v     v   v 
1     2 4 7 8

// 1 * 13 is the smallest next extension

      7/13 2  
      v    v 
1     2 4  7 8 13

// 2 * 7 and 7 * 2 are the smallest next extensions

      13 7   2
      v  v   v
1     2  4 7 8 13 14
```

```cpp
// OJ: https://leetcode.com/problems/super-ugly-number
// Author: github.com/lzl124631x
// Time: O(NP)
// Space: O(max(N, P))
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long> v(n, LONG_MAX), p(primes.size(), 0);
        v[0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < primes.size(); ++j) v[i] = min(v[i], primes[j] * v[p[j]]);
            for (int j = 0; j < primes.size(); ++j) p[j] += (v[i] == primes[j] * v[p[j]]);
        }
        return v.back();
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/super-ugly-number
// Author: github.com/lzl124631x
// Time: O(NP)
// Space: O(max(N, P))
// Ref: https://discuss.leetcode.com/topic/34841/java-three-methods-23ms-36-ms-58ms-with-heap-performance-explained
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> v(n, INT_MAX), p(primes.size(), 0), val(primes.size(), 1);
        v[0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < primes.size(); ++j) {
                if (v[i - 1] == val[j]) val[j] = v[p[j]++] * primes[j];
                v[i] = min(v[i], val[j]);
            }
        }
        return v[n - 1];
    }
};
```