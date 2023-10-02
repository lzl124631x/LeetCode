# [201. Bitwise AND of Numbers Range (Medium)](https://leetcode.com/problems/bitwise-and-of-numbers-range/)

<p>Given two integers <code>left</code> and <code>right</code> that represent the range <code>[left, right]</code>, return <em>the bitwise AND of all numbers in this range, inclusive</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> left = 5, right = 7
<strong>Output:</strong> 4
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> left = 0, right = 0
<strong>Output:</strong> 0
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> left = 1, right = 2147483647
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= left &lt;= right &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1.

The answer is the common binary prefix between `m` and `n`.

```cpp
// OJ: https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Author: github.com/lzl124631x
// Time: O(C) where `C` is `log2(N)` (= 32 in this problem)
// Space: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++i;
        }
        return m << i;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Author: github.com/lzl124631x
// Time: O(C) where `C` is `log2(N)` (= 32 in this problem)
// Space: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) n = n & (n - 1); // Keep removing the lowest bit of `n` until `m >= n`
        return n;
    }
};
```