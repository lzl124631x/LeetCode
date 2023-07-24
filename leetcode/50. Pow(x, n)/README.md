# [50. Pow(x, n) (Medium)](https://leetcode.com/problems/powx-n)

<p>Implement <a href="http://www.cplusplus.com/reference/valarray/pow/" target="_blank">pow(x, n)</a>, which calculates <code>x</code> raised to the power <code>n</code> (i.e., <code>x<sup>n</sup></code>).</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> x = 2.00000, n = 10
<strong>Output:</strong> 1024.00000
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> x = 2.10000, n = 3
<strong>Output:</strong> 9.26100
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> x = 2.00000, n = -2
<strong>Output:</strong> 0.25000
<strong>Explanation:</strong> 2<sup>-2</sup> = 1/2<sup>2</sup> = 1/4 = 0.25
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>-100.0 &lt; x &lt; 100.0</code></li>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup>-1</code></li>
	<li><code>n</code> is an integer.</li>
	<li>Either <code>x</code> is not zero or <code>n &gt; 0</code>.</li>
	<li><code>-10<sup>4</sup> &lt;= x<sup>n</sup> &lt;= 10<sup>4</sup></code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Sqrt(x) (Easy)](https://leetcode.com/problems/sqrtx/)
* [Super Pow (Medium)](https://leetcode.com/problems/super-pow/)
* [Count Collisions of Monkeys on a Polygon (Medium)](https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/)

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

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/powx-n
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    double myPow(double x, long n) {
        if (n < 0) return 1 / myPow(x, -n);
        double ans = 1;
        while (n) {
            if (n & 1) ans *= x;
            n >>= 1;
            x *= x;
        }
        return ans;
    }
};
```