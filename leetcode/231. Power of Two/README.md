# [231. Power of Two (Easy)](https://leetcode.com/problems/power-of-two/)

<p>Given an integer, write a function to determine if it is a power of two.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 1
<strong>Output:</strong> true 
<strong>Explanation: </strong>2<sup>0</sup>&nbsp;= 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 16
<strong>Output:</strong> true
<strong>Explanation: </strong>2<sup>4</sup>&nbsp;= 16</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> 218
<strong>Output:</strong> false</pre>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Number of 1 Bits (Easy)](https://leetcode.com/problems/number-of-1-bits/)
* [Power of Three (Easy)](https://leetcode.com/problems/power-of-three/)
* [Power of Four (Easy)](https://leetcode.com/problems/power-of-four/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/power-of-two/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while ((n & 1) == 0) n >>= 1;
        return n == 1;
    }
};
```

## Solution 2.

`n & -n` gets the lowest bit of `n`. If `n - (n & -n)` is zero, then `n` is power of 2.

```cpp
// OJ: https://leetcode.com/problems/power-of-two/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n - (n & -n));
    }
};
```