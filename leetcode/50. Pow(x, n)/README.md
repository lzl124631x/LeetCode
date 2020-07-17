# [50. Pow(x, n) (Medium)](https://leetcode.com/problems/powx-n/)

<p>Implement <a href="http://www.cplusplus.com/reference/valarray/pow/" target="_blank">pow(<em>x</em>, <em>n</em>)</a>, which calculates&nbsp;<em>x</em> raised to the power <em>n</em> (x<sup><span style="font-size:10.8333px">n</span></sup>).</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 2.00000, 10
<strong>Output:</strong> 1024.00000
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 2.10000, 3
<strong>Output:</strong> 9.26100
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> 2.00000, -2
<strong>Output:</strong> 0.25000
<strong>Explanation:</strong> 2<sup>-2</sup> = 1/2<sup>2</sup> = 1/4 = 0.25
</pre>

<p><strong>Note:</strong></p>

<ul>
	<li>-100.0 &lt; <em>x</em> &lt; 100.0</li>
	<li><em>n</em> is a 32-bit signed integer, within the range&nbsp;[−2<sup>31</sup>,&nbsp;2<sup>31&nbsp;</sup>− 1]</li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Sqrt(x) (Easy)](https://leetcode.com/problems/sqrtx/)
* [Super Pow (Medium)](https://leetcode.com/problems/super-pow/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/powx-n/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(logN)
class Solution {
    double myPow(double x, long n) {
        if (n < 0) return 1 / myPow(x, -n);
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == 2) return x * x;
        return myPow(myPow(x, n / 2), 2) * (n % 2 ? x : 1);
    }
public:
    double myPow(double x, int n) {
        return myPow(x, (long)n);
    }
};
```