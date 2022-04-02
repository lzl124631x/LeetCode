# [680. Valid Palindrome II (Easy)](https://leetcode.com/problems/valid-palindrome-ii/)

<p>Given a string <code>s</code>, return <code>true</code> <em>if the </em><code>s</code><em> can be palindrome after deleting <strong>at most one</strong> character from it</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aba"
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abca"
<strong>Output:</strong> true
<strong>Explanation:</strong> You could delete the character 'c'.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "abc"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Valid Palindrome (Easy)](https://leetcode.com/problems/valid-palindrome/)
* [Valid Palindrome III (Hard)](https://leetcode.com/problems/valid-palindrome-iii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/valid-palindrome-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j && s[i] == s[j]) ++i, --j;
        if (i >= j) return true;
        auto valid = [&](int i, int j) {
            while (i < j && s[i] == s[j]) ++i, --j;
            return i >= j;
        };
        return valid(i + 1, j) || valid(i, j - 1);
    }
};
```