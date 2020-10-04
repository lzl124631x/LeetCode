# [7. Reverse Integer (Easy)](https://leetcode.com/problems/reverse-integer/)

<p>Given a 32-bit signed integer, reverse digits of an integer.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 123
<strong>Output:</strong> 321
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> -123
<strong>Output:</strong> -321
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> 120
<strong>Output:</strong> 21
</pre>

<p><strong>Note:</strong><br>
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2<sup>31</sup>,&nbsp; 2<sup>31&nbsp;</sup>− 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.</p>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [String to Integer (atoi) (Medium)](https://leetcode.com/problems/string-to-integer-atoi/)
* [Reverse Bits (Easy)](https://leetcode.com/problems/reverse-bits/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reverse-integer/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        int r = 0, sign = x >= 0 ? 1 : -1, y = sign * x, p = 1;
        while (y) {
            y /= 10;
            if (y) p *= 10;
        }
        x = sign * x;
        while (x) {
            int d = x % 10;
            x /= 10;
            if ((INT_MAX - r) / p < d) return 0;
            r += p * d;
            p /= 10;
        }
        return sign * r;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/reverse-integer/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while (x) {
            int d = x % 10;
            x /= 10;
            if ((r >= 0 && (r > INT_MAX / 10 || INT_MAX - 10 * r < d))
                || (r < 0 && (r < INT_MIN / 10 || INT_MIN - 10 * r > d))) return 0;
            r = r * 10 + d;
        }
        return r;
    }
};
```