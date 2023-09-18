# [172. Factorial Trailing Zeroes (Medium)](https://leetcode.com/problems/factorial-trailing-zeroes)

<p>Given an integer <code>n</code>, return <em>the number of trailing zeroes in </em><code>n!</code>.</p>

<p>Note that <code>n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> 3! = 6, no trailing zero.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 5
<strong>Output:</strong> 1
<strong>Explanation:</strong> 5! = 120, one trailing zero.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 0
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you write a solution that works in logarithmic time complexity?</p>


**Companies**:
[Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Math](https://leetcode.com/tag/math)

**Similar Questions**:
* [Number of Digit One (Hard)](https://leetcode.com/problems/number-of-digit-one)
* [Preimage Size of Factorial Zeroes Function (Hard)](https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function)
* [Abbreviating the Product of a Range (Hard)](https://leetcode.com/problems/abbreviating-the-product-of-a-range)
* [Maximum Trailing Zeros in a Cornered Path (Medium)](https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path)

## Solution 1. Count Factors of 5

```cpp
// OJ: https://leetcode.com/problems/factorial-trailing-zeroes
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int trailingZeroes(int n) {
        if (n == 0) return 0;
        int ans = 0;
        while (n >= 5) {
            ans += n / 5;
            n /= 5;
        }
        return ans;
    }
};
```