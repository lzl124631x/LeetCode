# [507. Perfect Number (Easy)](https://leetcode.com/problems/perfect-number/)

<p>A <a href="https://en.wikipedia.org/wiki/Perfect_number" target="_blank"><strong>perfect number</strong></a> is a <strong>positive integer</strong> that is equal to the sum of its <strong>positive divisors</strong>, excluding the number itself. A <strong>divisor</strong> of an integer <code>x</code> is an integer that can divide <code>x</code> evenly.</p>

<p>Given an integer <code>n</code>, return <code>true</code><em> if </em><code>n</code><em> is a perfect number, otherwise return </em><code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num = 28
<strong>Output:</strong> true
<strong>Explanation:</strong> 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = 7
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10<sup>8</sup></code></li>
</ul>


**Companies**:  
[Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Self Dividing Numbers (Easy)](https://leetcode.com/problems/self-dividing-numbers/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/perfect-number/
// Author: github.com/lzl124631x
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    bool checkPerfectNumber(int n) {
        if (n == 1) return false;
        int sum = 0;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i) continue;
            sum += i;
            if (i != 1 && n / i != i) sum += n / i;
            if (sum > n) return false;
        }
        return sum == n;
    }
};
```