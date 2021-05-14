# [1750. Minimum Length of String After Deleting Similar Ends (Medium)](https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/)

<p>Given a string <code>s</code> consisting only of characters <code>'a'</code>, <code>'b'</code>, and <code>'c'</code>. You are asked to apply the following algorithm on the string any number of times:</p>

<ol>
	<li>Pick a <strong>non-empty</strong> prefix from the string <code>s</code> where all the characters in the prefix are equal.</li>
	<li>Pick a <strong>non-empty</strong> suffix from the string <code>s</code> where all the characters in this suffix are equal.</li>
	<li>The prefix and the suffix should not intersect at any index.</li>
	<li>The characters from the prefix and suffix must be the same.</li>
	<li>Delete both the prefix and the suffix.</li>
</ol>

<p>Return <em>the <strong>minimum length</strong> of </em><code>s</code> <em>after performing the above operation any number of times (possibly zero times)</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "ca"
<strong>Output:</strong> 2
<strong>Explanation: </strong>You can't remove any characters, so the string stays as is.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "cabaabac"
<strong>Output:</strong> 0
<strong>Explanation:</strong> An optimal sequence of operations is:
- Take prefix = "c" and suffix = "c" and remove them, s = "abaaba".
- Take prefix = "a" and suffix = "a" and remove them, s = "baab".
- Take prefix = "b" and suffix = "b" and remove them, s = "aa".
- Take prefix = "a" and suffix = "a" and remove them, s = "".</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "aabccabba"
<strong>Output:</strong> 3
<strong>Explanation:</strong> An optimal sequence of operations is:
- Take prefix = "aa" and suffix = "a" and remove them, s = "bccabb".
- Take prefix = "b" and suffix = "bb" and remove them, s = "cca".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> only consists of characters <code>'a'</code>, <code>'b'</code>, and <code>'c'</code>.</li>
</ul>


**Companies**:  
[Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minimumLength(string s) {
        int L = 0, R = s.size() - 1;
        while (L < R && s[L] == s[R]) {
            char ch = s[L];
            while (L <= R && s[L] == ch) ++L;
            while (L <= R && s[R] == ch) --R;
        }
        return R - L + 1;
    }
};
```