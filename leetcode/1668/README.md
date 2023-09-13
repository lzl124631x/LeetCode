# [1668. Maximum Repeating Substring (Easy)](https://leetcode.com/problems/maximum-repeating-substring/)

<p>For a string <code>sequence</code>, a string <code>word</code> is <strong><code>k</code>-repeating</strong> if <code>word</code> concatenated <code>k</code> times is a substring of <code>sequence</code>. The <code>word</code>'s <strong>maximum <code>k</code>-repeating value</strong> is the highest value <code>k</code> where <code>word</code> is <code>k</code>-repeating in <code>sequence</code>. If <code>word</code> is not a substring of <code>sequence</code>, <code>word</code>'s maximum <code>k</code>-repeating value is <code>0</code>.</p>

<p>Given strings <code>sequence</code> and <code>word</code>, return <em>the <strong>maximum <code>k</code>-repeating value</strong> of <code>word</code> in <code>sequence</code></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> sequence = "ababc", word = "ab"
<strong>Output:</strong> 2
<strong>Explanation: </strong>"abab" is a substring in "<u>abab</u>c".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> sequence = "ababc", word = "ba"
<strong>Output:</strong> 1
<strong>Explanation: </strong>"ba" is a substring in "a<u>ba</u>bc". "baba" is not a substring in "ababc".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> sequence = "ababc", word = "ac"
<strong>Output:</strong> 0
<strong>Explanation: </strong>"ac" is not a substring in "ababc". 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= sequence.length &lt;= 100</code></li>
	<li><code>1 &lt;= word.length &lt;= 100</code></li>
	<li><code>sequence</code> and <code>word</code>&nbsp;contains only lowercase English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Detect Pattern of Length M Repeated K or More Times (Easy)](https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/)

## Solution 1. Brute force

Note that `find` takes `O(N^2)` instead of `O(N)`.

```cpp
// OJ: https://leetcode.com/problems/maximum-repeating-substring/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N)
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string f = word;
        int k = 1;
        for (; sequence.find(f) != string::npos; ++k, f += word);
        return k - 1;
    }
};
```