# [1957. Delete Characters to Make Fancy String (Easy)](https://leetcode.com/problems/delete-characters-to-make-fancy-string/)

<p>A <strong>fancy string</strong> is a string where no <strong>three</strong> <strong>consecutive</strong> characters are equal.</p>

<p>Given a string <code>s</code>, delete the <strong>minimum</strong> possible number of characters from <code>s</code> to make it <strong>fancy</strong>.</p>

<p>Return <em>the final string after the deletion</em>. It can be shown that the answer will always be <strong>unique</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "le<u>e</u>etcode"
<strong>Output:</strong> "leetcode"
<strong>Explanation:</strong>
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "<u>a</u>aab<u>aa</u>aa"
<strong>Output:</strong> "aabaa"
<strong>Explanation:</strong>
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "aab"
<strong>Output:</strong> "aab"
<strong>Explanation:</strong> No three consecutive characters are equal, so return "aab".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>


**Companies**:  
[Wayfair](https://leetcode.com/company/wayfair)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/delete-characters-to-make-fancy-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string makeFancyString(string s) {
        int i = 0, j = 0, N = s.size();
        while (i < N) {
            int start = i;
            while (i < N && s[i] == s[start]) {
                if (i - start < 2) s[j++] = s[i];
                ++i;
            }
        }
        s.resize(j);
        return s;
    }
};
```