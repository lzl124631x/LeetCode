# [1119. Remove Vowels from a String (Easy)](https://leetcode.com/problems/remove-vowels-from-a-string/)

<p>Given a string <code>s</code>, remove the vowels <code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, and <code>'u'</code> from it, and return the new string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "leetcodeisacommunityforcoders"
<strong>Output:</strong> "ltcdscmmntyfrcdrs"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aeiou"
<strong>Output:</strong> ""
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Reverse Vowels of a String (Easy)](https://leetcode.com/problems/reverse-vowels-of-a-string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/remove-vowels-from-a-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) extra space
class Solution {
public:
    string removeVowels(string s) {
        string ans;
        for (char c : s) {
            if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') ans += c;
        }
        return ans;
    }
};
```