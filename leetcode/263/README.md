# [263. Ugly Number (Easy)](https://leetcode.com/problems/ugly-number)

<p>An <strong>ugly number</strong> is a positive integer whose prime factors are limited to <code>2</code>, <code>3</code>, and <code>5</code>.</p>

<p>Given an integer <code>n</code>, return <code>true</code> <em>if</em> <code>n</code> <em>is an <strong>ugly number</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 6
<strong>Output:</strong> true
<strong>Explanation:</strong> 6 = 2 &times; 3
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> true
<strong>Explanation:</strong> 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 14
<strong>Output:</strong> false
<strong>Explanation:</strong> 14 is not ugly since it includes the prime factor 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Math](https://leetcode.com/tag/math)

**Similar Questions**:
* [Happy Number (Easy)](https://leetcode.com/problems/happy-number)
* [Count Primes (Medium)](https://leetcode.com/problems/count-primes)
* [Ugly Number II (Medium)](https://leetcode.com/problems/ugly-number-ii)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/ugly-number
// Author: github.com/lzl124631x
// Time: O(log2(N) + log3(N) + log5(N))
// Space: O(1)
class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        int ds[3] = {2,3,5};
        for (int d : ds) {
            while (n % d == 0) n /= d;
        }
        return n == 1;
    }
};
```