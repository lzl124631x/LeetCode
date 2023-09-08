# [2828. Check if a String Is an Acronym of Words (Easy)](https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words)

<p>Given an array of strings <code>words</code> and a string <code>s</code>, determine if <code>s</code> is an <strong>acronym</strong> of words.</p>
<p>The string <code>s</code> is considered an acronym of <code>words</code> if it can be formed by concatenating the <strong>first</strong> character of each string in <code>words</code> <strong>in order</strong>. For example, <code>"ab"</code> can be formed from <code>["apple", "banana"]</code>, but it can't be formed from <code>["bear", "aardvark"]</code>.</p>
<p>Return <code>true</code><em> if </em><code>s</code><em> is an acronym of </em><code>words</code><em>, and </em><code>false</code><em> otherwise. </em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> words = ["alice","bob","charlie"], s = "abc"
<strong>Output:</strong> true
<strong>Explanation:</strong> The first character in the words "alice", "bob", and "charlie" are 'a', 'b', and 'c', respectively. Hence, s = "abc" is the acronym. 
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> words = ["an","apple"], s = "a"
<strong>Output:</strong> false
<strong>Explanation:</strong> The first character in the words "an" and "apple" are 'a' and 'a', respectively. 
The acronym formed by concatenating these characters is "aa". 
Hence, s = "a" is not the acronym.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> words = ["never","gonna","give","up","on","you"], s = "ngguoy"
<strong>Output:</strong> true
<strong>Explanation: </strong>By concatenating the first character of the words in the array, we get the string "ngguoy". 
Hence, s = "ngguoy" is the acronym.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>words[i]</code> and <code>s</code> consist of lowercase English letters.</li>
</ul>

**Companies**:
[Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Word Abbreviation (Hard)](https://leetcode.com/problems/word-abbreviation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isAcronym(vector<string>& A, string s) {
        if (A.size() != s.size()) return false;
        for (int i = 0, N = A.size(); i < N; ++i) {
            if (A[i][0] != s[i]) return false;
        }
        return true;
    }
};
```