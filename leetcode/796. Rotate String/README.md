# [796. Rotate String (Easy)](https://leetcode.com/problems/rotate-string/)

<p>We are given two strings, <code>A</code> and <code>B</code>.</p>

<p>A <em>shift on <code>A</code></em> consists of taking string <code>A</code> and moving the leftmost character to the rightmost position. For example, if <code>A = 'abcde'</code>, then it will be <code>'bcdea'</code> after one shift on <code>A</code>. Return <code>True</code> if and only if <code>A</code> can become <code>B</code> after some number of shifts on <code>A</code>.</p>

<pre><strong>Example 1:</strong>
<strong>Input:</strong> A = 'abcde', B = 'cdeab'
<strong>Output:</strong> true

<strong>Example 2:</strong>
<strong>Input:</strong> A = 'abcde', B = 'abced'
<strong>Output:</strong> false
</pre>

<p><strong>Note:</strong></p>

<ul>
	<li><code>A</code> and <code>B</code> will have length at most <code>100</code>.</li>
</ul>


**Companies**:  
[Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/rotate-string/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    bool rotateString(string A, string B) {
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }
};
```