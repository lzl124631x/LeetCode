# [69. Sqrt(x) (Easy)](https://leetcode.com/problems/sqrtx/)

<p>Given a non-negative integer <code>x</code>,&nbsp;compute and return <em>the square root of</em> <code>x</code>.</p>

<p>Since the return type&nbsp;is an integer, the decimal digits are <strong>truncated</strong>, and only <strong>the integer part</strong> of the result&nbsp;is returned.</p>

<p><strong>Note:&nbsp;</strong>You are not allowed to use any built-in exponent function or operator, such as <code>pow(x, 0.5)</code> or&nbsp;<code>x ** 0.5</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> x = 4
<strong>Output:</strong> 2
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> x = 8
<strong>Output:</strong> 2
<strong>Explanation:</strong> The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= x &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


**Companies**:  
[LinkedIn](https://leetcode.com/company/linkedin), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple), [Uber](https://leetcode.com/company/uber), [tiktok](https://leetcode.com/company/tiktok)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Pow(x, n) (Medium)](https://leetcode.com/problems/powx-n/)
* [Valid Perfect Square (Easy)](https://leetcode.com/problems/valid-perfect-square/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sqrtx/
// Author: github.com/lzl124631x
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    int mySqrt(int x) {
        long i = 0;
        while (i * i <= x) ++i;
        return i - 1;
    }
};
```

## Solution 2. Binary Search

`L <= R` template.

```cpp
// OJ: https://leetcode.com/problems/sqrtx/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int mySqrt(int x) {
        long L = 0, R = x;
        while (L <= R) {
            long M = (L + R) / 2;
            if (M * M <= x) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};
```

Or use `L < R` template

```cpp
// OJ: https://leetcode.com/problems/sqrtx/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int mySqrt(int x) {
        long L = 0, R = x;
        while (L < R) {
            long M = (L + R + 1) / 2;
            if (M * M <= x) L = M;
            else R = M - 1;
        }
        return L;
    }
};
```

## Solution 3. Newton's method

Reference: https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division

```cpp
// OJ: https://leetcode.com/problems/sqrtx/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int mySqrt(int x) {
        long r = x;
        while (r * r > x) r = (r + x / r) / 2;
        return r;
    }
};
```