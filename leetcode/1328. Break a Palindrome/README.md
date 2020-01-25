# [1328. Break a Palindrome (Medium)](https://leetcode.com/problems/break-a-palindrome/)

<p>Given a palindromic string <code>palindrome</code>, replace <strong>exactly one</strong> character by any lowercase English letter so that the string becomes the lexicographically smallest possible string that <strong>isn't</strong> a palindrome.</p>

<p>After doing so, return the final string.&nbsp; If there is no way to do so, return the empty string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> palindrome = "abccba"
<strong>Output:</strong> "aaccba"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> palindrome = "a"
<strong>Output:</strong> ""
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= palindrome.length &lt;= 1000</code></li>
	<li><code>palindrome</code>&nbsp;consists of only lowercase English letters.</li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/break-a-palindrome/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int N = palindrome.size(), end = N / 2;
        for (int i = 0; i < end; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        if (N > 1) {
            palindrome[N - 1] = 'b';
            return palindrome;
        }
        return "";
    }
};
```