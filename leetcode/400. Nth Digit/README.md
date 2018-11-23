# [400. Nth Digit (Easy)](https://leetcode.com/problems/nth-digit/)

<p>Find the <i>n</i><sup>th</sup> digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... </p>

<p><b>Note:</b><br>
<i>n</i> is positive and will fit within the range of a 32-bit signed integer (<i>n</i> &lt; 2<sup>31</sup>).
</p>

<p><b>Example 1:</b>
</p><pre><b>Input:</b>
3

<b>Output:</b>
3
</pre>
<p></p>

<p><b>Example 2:</b>
</p><pre><b>Input:</b>
11

<b>Output:</b>
0

<b>Explanation:</b>
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
</pre>
<p></p>

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/nth-digit/
// Author: github.com/lzl124631x
// Time: O(lgN)
// Space: O(1)
class Solution {
public:
    int findNthDigit(int n) {
        int k, r, len = 1;
        long long total = 0, p = 1;
        while (n > total + p * 9 * len) {
            total += p * 9 * len;
            p *= 10;
            len++;
        }
        k = p + (n - total - 1) / len;
        r = (n - total - 1) % len;
        r = len - r - 1;
        while (r--) {
            k /= 10;
        }
        return k % 10;
    }
};
```