# [29. Divide Two Integers (Medium)](https://leetcode.com/problems/divide-two-integers/)

<p>Given two integers <code>dividend</code> and <code>divisor</code>, divide two integers without using multiplication, division and mod operator.</p>

<p>Return the quotient after dividing <code>dividend</code> by <code>divisor</code>.</p>

<p>The integer division should truncate toward zero.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> dividend = 10, divisor = 3
<strong>Output:</strong> 3</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> dividend = 7, divisor = -3
<strong>Output:</strong> -2</pre>

<p><strong>Note:</strong></p>

<ul>
	<li>Both dividend and divisor&nbsp;will be&nbsp;32-bit&nbsp;signed integers.</li>
	<li>The divisor will never be 0.</li>
	<li>Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2<sup>31</sup>, &nbsp;2<sup>31</sup> − 1]. For the purpose of this problem, assume that your function returns 2<sup>31</sup> − 1 when the division result&nbsp;overflows.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Oracle](https://leetcode.com/company/oracle)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/divide-two-integers/
// Author: github.com/lzl124631x
// Time: O(logD) where D is |dividend|
// Space: O(1)
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor) return 0;  // divide-by-zero error
        bool pos1 = dividend > 0, pos2 = divisor > 0, pos = !(pos1^pos2);
        if (pos1) dividend = -dividend;
        if (pos2) divisor = -divisor;
        int q = 0, d = divisor, t = 1;
        while (t > 0 && dividend < 0) {
            if (dividend - d <= 0) {
                dividend -= d;
                q -= t;
                if ((INT_MIN >> 1) < d) {
                    t <<= 1;
                    d <<= 1;  
                }           
            } else {
                d >>= 1;
                t >>= 1;
            }
        }
        return pos? -q : q;
    }
};
```