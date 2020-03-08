# [1374. Generate a String With Characters That Have Odd Counts (Easy)](https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/)

<p>Given an&nbsp;integer <code>n</code>, <em>return a string with <code>n</code>&nbsp;characters such that each character in such string occurs <strong>an odd number of times</strong></em>.</p>

<p>The returned string must contain only lowercase English letters. If there are multiples valid strings, return <strong>any</strong> of them. &nbsp;</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 4
<strong>Output:</strong> "pppz"
<strong>Explanation:</strong> "pppz" is a valid string since the character 'p' occurs three times and the character 'z' occurs once. Note that there are many other valid strings such as "ohhh" and "love".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> "xy"
<strong>Explanation:</strong> "xy" is a valid string since the characters 'x' and 'y' occur once. Note that there are many other valid strings such as "ag" and "ur".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 7
<strong>Output:</strong> "holasss"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string generateTheString(int n) {
        return n % 2 ? string(n, 'a') : string(n - 1, 'a') + 'b';
    }
};
```