# [1078. Occurrences After Bigram (Easy)](https://leetcode.com/problems/occurrences-after-bigram/)

<p>Given two strings <code>first</code> and <code>second</code>, consider occurrences in some text of the form <code>"first second third"</code>, where <code>second</code> comes immediately after <code>first</code>, and <code>third</code> comes immediately after <code>second</code>.</p>

<p>Return <em>an array of all the words</em> <code>third</code> <em>for each occurrence of</em> <code>"first second third"</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> text = "alice is a good girl she is a good student", first = "a", second = "good"
<strong>Output:</strong> ["girl","student"]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> text = "we will we will rock you", first = "we", second = "will"
<strong>Output:</strong> ["we","rock"]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 1000</code></li>
	<li><code>text</code> consists of lowercase English letters and spaces.</li>
	<li>All the words in <code>text</code> a separated by <strong>a single space</strong>.</li>
	<li><code>1 &lt;= first.length, second.length &lt;= 10</code></li>
	<li><code>first</code> and <code>second</code> consist of lowercase English letters.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/occurrences-after-bigram/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        istringstream ss(text);
        string prev2, prev, word;
        while (ss >> word) {
            if (prev2 == first && prev == second) ans.push_back(word);
            prev2 = prev;
            prev = word;
        }
        return ans;
    }
};
```