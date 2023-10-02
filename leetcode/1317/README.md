# [1317. Convert Integer to the Sum of Two No-Zero Integers (Easy)](https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/submissions/)

<p>Given an integer <code>n</code>. No-Zero integer is a positive integer which <strong>doesn't contain any 0</strong> in its decimal representation.</p>

<p>Return <em>a list of two integers</em> <code>[A, B]</code> where:</p>

<ul>
	<li><code>A</code> and <code>B</code> are No-Zero integers.</li>
	<li><code>A + B = n</code></li>
</ul>

<p>It's guarateed that there is at least one valid solution. If there are many valid solutions you can return any of them.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> [1,1]
<strong>Explanation:</strong> A = 1, B = 1. A + B = n and both A and B don't contain any 0 in their decimal representation.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 11
<strong>Output:</strong> [2,9]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 10000
<strong>Output:</strong> [1,9999]
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> n = 69
<strong>Output:</strong> [1,68]
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> n = 1010
<strong>Output:</strong> [11,999]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10^4</code></li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
    bool hasZero(int n) {
        for (; n; n /= 10) {
            if (n % 10 == 0) return true;
        }
        return false;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 1;
        for (; hasZero(a) || hasZero(n - a); ++a);
        return { a, n - a };
    }
};
```