# [214. Shortest Palindrome (Hard)](https://leetcode.com/problems/shortest-palindrome/)

<p>Given a string <em><b>s</b></em>, you can convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> s = "aacecaaa"
<strong>Output:</strong> "aaacecaaa"
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> s = "abcd"
<strong>Output:</strong> "dcbabcd"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lowercase English letters only.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Longest Palindromic Substring (Medium)](https://leetcode.com/problems/longest-palindromic-substring/)
* [Implement strStr() (Easy)](https://leetcode.com/problems/implement-strstr/)
* [Palindrome Pairs (Hard)](https://leetcode.com/problems/palindrome-pairs/)

## Solution 1. Rolling Hash

Find the longest palindrome starting at index 0.

```cpp
// OJ: https://leetcode.com/problems/shortest-palindrome/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string shortestPalindrome(string s) {
        unsigned d = 16777619, h = 0, rh = 0, p = 1, maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            h = h * d + s[i] - 'a';
            rh += (s[i] - 'a') * p;
            p *= d;
            if (h == rh) maxLen = i + 1;
        }
        auto sub = s.substr(maxLen);
        reverse(begin(sub), end(sub));
        return sub + s;
    }
};
```