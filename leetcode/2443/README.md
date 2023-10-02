# [2443. Sum of Number and Its Reverse (Medium)](https://leetcode.com/problems/sum-of-number-and-its-reverse)

<p>Given a <strong>non-negative</strong> integer <code>num</code>, return <code>true</code><em> if </em><code>num</code><em> can be expressed as the sum of any <strong>non-negative</strong> integer and its reverse, or </em><code>false</code><em> otherwise.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> num = 443
<strong>Output:</strong> true
<strong>Explanation:</strong> 172 + 271 = 443 so we return true.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> num = 63
<strong>Output:</strong> false
<strong>Explanation:</strong> 63 cannot be expressed as the sum of a non-negative integer and its reverse so we return false.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> num = 181
<strong>Output:</strong> true
<strong>Explanation:</strong> 140 + 041 = 181 so we return true. Note that when a number is reversed, there may be leading zeros.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>0 &lt;= num &lt;= 10<sup>5</sup></code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Enumeration](https://leetcode.com/tag/enumeration/)

**Similar Questions**:
* [Sum of Numbers With Units Digit K (Medium)](https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sum-of-number-and-its-reverse
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int reverse(int n) {
        int ans = 0;
        while (n) {
            ans = ans * 10 + n % 10;
            n /= 10;
        }
        return ans;
    }
public:
    bool sumOfNumberAndReverse(int n) {
        for (int i = 0; i <= n; ++i) {
            if (i + reverse(i) == n) return true;
        }
        return false;
    }
};
```