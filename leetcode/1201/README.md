# [1201. Ugly Number III (Medium)](https://leetcode.com/problems/ugly-number-iii/)

<p>An <strong>ugly number</strong> is a positive integer that is divisible by <code>a</code>, <code>b</code>, or <code>c</code>.</p>

<p>Given four integers <code>n</code>, <code>a</code>, <code>b</code>, and <code>c</code>, return the <code>n<sup>th</sup></code> <strong>ugly number</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 3, a = 2, b = 3, c = 5
<strong>Output:</strong> 4
<strong>Explanation:</strong> The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 4, a = 2, b = 3, c = 4
<strong>Output:</strong> 6
<strong>Explanation:</strong> The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 5, a = 2, b = 11, c = 13
<strong>Output:</strong> 10
<strong>Explanation:</strong> The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> n = 1000000000, a = 2, b = 217983653, c = 336916467
<strong>Output:</strong> 1999999984
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n, a, b, c &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= a * b * c &lt;= 10<sup>18</sup></code></li>
	<li>It is guaranteed that the result will be in range <code>[1, 2 * 10<sup>9</sup>]</code>.</li>
</ul>


**Companies**:  
[American Express](https://leetcode.com/company/american-express)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Binary Search](https://leetcode.com/tag/binary-search/), [Number Theory](https://leetcode.com/tag/number-theory/)

**Similar Questions**:
* [Ugly Number II (Medium)](https://leetcode.com/problems/ugly-number-ii/)

## Solution 1. Binary Answer + Inclusion-exclusion Principle

```cpp
// OJ: https://leetcode.com/problems/ugly-number-iii/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
    long lcm(long a, long b) { // least common multiple
        return a * b / gcd(a, b);
    }
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long L = 1, R = 2e9;
        auto le = [&](long M) {
            return M / a + M / b + M / c - M / lcm(a, b) - M / lcm(b, c) - M / lcm(a, c) + M / lcm(lcm(a, b), c);
        };
        while (L <= R) {
            long M = (L + R) / 2, cnt = le(M);
            if (cnt < n) L = M + 1;
            else R = M - 1;
        }
        return L;
    }
};
```