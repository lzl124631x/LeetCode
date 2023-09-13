# [1832. Check if the Sentence Is Pangram (Easy)](https://leetcode.com/problems/check-if-the-sentence-is-pangram/)

<p>A <strong>pangram</strong> is a sentence where every letter of the English alphabet appears at least once.</p>

<p>Given a string <code>sentence</code> containing only lowercase English letters, return<em> </em><code>true</code><em> if </em><code>sentence</code><em> is a <strong>pangram</strong>, or </em><code>false</code><em> otherwise.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> sentence = "thequickbrownfoxjumpsoverthelazydog"
<strong>Output:</strong> true
<strong>Explanation:</strong> sentence contains at least one of every letter of the English alphabet.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> sentence = "leetcode"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 1000</code></li>
	<li><code>sentence</code> consists of lowercase English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/check-if-the-sentence-is-pangram/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(C) where C is the length of the character set
class Solution {
public:
    bool checkIfPangram(string s) {
        unordered_set<char> ss(begin(s), end(s));
        return ss.size() == 26;
    }
};
```