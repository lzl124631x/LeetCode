# [326. Power of Three (Easy)](https://leetcode.com/problems/power-of-three/)

<p>Given an integer <code>n</code>, return <em><code>true</code> if it is a power of three. Otherwise, return <code>false</code></em>.</p>

<p>An integer <code>n</code> is a power of three, if there exists an integer <code>x</code> such that <code>n == 3<sup>x</sup></code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> n = 27
<strong>Output:</strong> true
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> n = 0
<strong>Output:</strong> false
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> n = 9
<strong>Output:</strong> true
</pre><p><strong>Example 4:</strong></p>
<pre><strong>Input:</strong> n = 45
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you solve it without loops/recursion?

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Power of Two (Easy)](https://leetcode.com/problems/power-of-two/)
* [Power of Four (Easy)](https://leetcode.com/problems/power-of-four/)
* [Check if Number is a Sum of Powers of Three (Medium)](https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/power-of-three/
// Author: github.com/lzl124631x
// Time: O(log3(N))
// Space: O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        while (n % 3 == 0) n /= 3;
        return n == 1;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/power-of-three/
// Author: github.com/lzl124631x
// Time: O(log10(N))
// Space: O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n < 1 ? false : fmod(log10(abs(n))/log10(3), 1) == 0;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/power-of-three/solution/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
```