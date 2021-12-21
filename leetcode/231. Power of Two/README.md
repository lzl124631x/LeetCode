# [231. Power of Two (Easy)](https://leetcode.com/problems/power-of-two/)

<p>Given an integer <code>n</code>, return <em><code>true</code> if it is a power of two. Otherwise, return <code>false</code></em>.</p>

<p>An integer <code>n</code> is a power of two, if there exists an integer <code>x</code> such that <code>n == 2<sup>x</sup></code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> true
<strong>Explanation: </strong>2<sup>0</sup> = 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 16
<strong>Output:</strong> true
<strong>Explanation: </strong>2<sup>4</sup> = 16
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you solve it without loops/recursion?

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Snapchat](https://leetcode.com/company/snapchat), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Recursion](https://leetcode.com/tag/recursion/)

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

## Solution 3.

`n & (n - 1)` removes the lowest bit of `n`. If it's zero, then `n` is power of 2.

```cpp
// OJ: https://leetcode.com/problems/power-of-two/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n - 1));
    }
};
```