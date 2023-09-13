# [1780. Check if Number is a Sum of Powers of Three (Medium)](https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/)

<p>Given an integer <code>n</code>, return <code>true</code> <em>if it is possible to represent </em><code>n</code><em> as the sum of distinct powers of three.</em> Otherwise, return <code>false</code>.</p>

<p>An integer <code>y</code> is a power of three if there exists an integer <code>x</code> such that <code>y == 3<sup>x</sup></code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 12
<strong>Output:</strong> true
<strong>Explanation:</strong> 12 = 3<sup>1</sup> + 3<sup>2</sup>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 91
<strong>Output:</strong> true
<strong>Explanation:</strong> 91 = 3<sup>0</sup> + 3<sup>2</sup> + 3<sup>4</sup>
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 21
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>7</sup></code></li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Backtracking](https://leetcode.com/tag/backtracking/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Power of Three (Easy)](https://leetcode.com/problems/power-of-three/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
// Author: github.com/lzl124631x
// Time: O(log_3^N)
// Space: O(1)
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n % 3 == 0 || (n % 3 == 1 && n != 1)) {
            if (n % 3 == 1) n -= 1;
            n /= 3;
        }
        return n == 1;
    }
};
```