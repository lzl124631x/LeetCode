# [1768. Merge Strings Alternately (Easy)](https://leetcode.com/problems/merge-strings-alternately/)

<p>You are given two strings <code>word1</code> and <code>word2</code>. Merge the strings by adding letters in alternating order, starting with <code>word1</code>. If a string is longer than the other, append the additional letters onto the end of the merged string.</p>

<p>Return <em>the merged string.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> word1 = "abc", word2 = "pqr"
<strong>Output:</strong> "apbqcr"
<strong>Explanation:</strong>&nbsp;The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> word1 = "ab", word2 = "pqrs"
<strong>Output:</strong> "apbqrs"
<strong>Explanation:</strong>&nbsp;Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> word1 = "abcd", word2 = "pq"
<strong>Output:</strong> "apbqcd"
<strong>Explanation:</strong>&nbsp;Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word1.length, word2.length &lt;= 100</code></li>
	<li><code>word1</code> and <code>word2</code> consist of lowercase English letters.</li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Zigzag Iterator (Medium)](https://leetcode.com/problems/zigzag-iterator/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/merge-strings-alternately/
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    string mergeAlternately(string a, string b) {
        int i = 0, j = 0, M = a.size(), N = b.size();
        string ans;
        while (i < M || j < N) {
            if (i < M) ans += a[i++];
            if (j < N) ans += b[j++];
        }
        return ans;
    }
};
```