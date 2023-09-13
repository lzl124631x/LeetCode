# [2427. Number of Common Factors (Easy)](https://leetcode.com/problems/number-of-common-factors)

<p>Given two positive integers <code>a</code> and <code>b</code>, return <em>the number of <strong>common</strong> factors of </em><code>a</code><em> and </em><code>b</code>.</p>
<p>An integer <code>x</code> is a <strong>common factor</strong> of <code>a</code> and <code>b</code> if <code>x</code> divides both <code>a</code> and <code>b</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> a = 12, b = 6
<strong>Output:</strong> 4
<strong>Explanation:</strong> The common factors of 12 and 6 are 1, 2, 3, 6.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> a = 25, b = 30
<strong>Output:</strong> 2
<strong>Explanation:</strong> The common factors of 25 and 30 are 1, 5.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= a, b &lt;= 1000</code></li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Enumeration](https://leetcode.com/tag/enumeration/), [Number Theory](https://leetcode.com/tag/number-theory/)

**Similar Questions**:
* [Count Primes (Medium)](https://leetcode.com/problems/count-primes/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-common-factors
// Author: github.com/lzl124631x
// Time: O(Sqrt(Gcd(a, b)))
// Space: O(1)
class Solution {
public:
    int commonFactors(int a, int b) {
        int n = gcd(a, b), ans = n == 1 ? 1 : 2;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i) continue;
            ++ans;
            if (i != n / i) ++ans;
        }
        return ans;
    }
};
```