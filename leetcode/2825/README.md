# [2825. Make String a Subsequence Using Cyclic Increments (Medium)](https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments)

<p>You are given two <strong>0-indexed</strong> strings <code>str1</code> and <code>str2</code>.</p>

<p>In an operation, you select a <strong>set</strong> of indices in <code>str1</code>, and for each index <code>i</code> in the set, increment <code>str1[i]</code> to the next character <strong>cyclically</strong>. That is <code>&#39;a&#39;</code> becomes <code>&#39;b&#39;</code>, <code>&#39;b&#39;</code> becomes <code>&#39;c&#39;</code>, and so on, and <code>&#39;z&#39;</code> becomes <code>&#39;a&#39;</code>.</p>

<p>Return <code>true</code> <em>if it is possible to make </em><code>str2</code> <em>a subsequence of </em><code>str1</code> <em>by performing the operation <strong>at most once</strong></em>, <em>and</em> <code>false</code> <em>otherwise</em>.</p>

<p><strong>Note:</strong> A subsequence of a string is a new string that is formed from the original string by deleting some (possibly none) of the characters without disturbing the relative positions of the remaining characters.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> str1 = &quot;abc&quot;, str2 = &quot;ad&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> Select index 2 in str1.
Increment str1[2] to become &#39;d&#39;. 
Hence, str1 becomes &quot;abd&quot; and str2 is now a subsequence. Therefore, true is returned.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> str1 = &quot;zc&quot;, str2 = &quot;ad&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> Select indices 0 and 1 in str1. 
Increment str1[0] to become &#39;a&#39;. 
Increment str1[1] to become &#39;d&#39;. 
Hence, str1 becomes &quot;ad&quot; and str2 is now a subsequence. Therefore, true is returned.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> str1 = &quot;ab&quot;, str2 = &quot;d&quot;
<strong>Output:</strong> false
<strong>Explanation:</strong> In this example, it can be shown that it is impossible to make str2 a subsequence of str1 using the operation at most once. 
Therefore, false is returned.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= str1.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= str2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>str1</code> and <code>str2</code> consist of only lowercase English letters.</li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers), [String](https://leetcode.com/tag/string)

**Similar Questions**:
* [Is Subsequence (Easy)](https://leetcode.com/problems/is-subsequence)

**Hints**:
* <div class="_1l1MA">Consider the indices we will increment separately.</div>
* <div class="_1l1MA">We can maintain two pointers: pointer <code>i</code> for <code>str1</code> and pointer <code>j</code> for <code>str2</code>, while ensuring they remain within the bounds of the strings.</div>
* <div class="_1l1MA">If both <code>str1[i]</code> and <code>str2[j]</code> match, or if incrementing <code>str1[i]</code> matches <code>str2[j]</code>, we increase both pointers; otherwise, we increment only pointer <code>i</code>.</div>
* <div class="_1l1MA">It is possible to make <code>str2</code> a subsequence of <code>str1</code> if <code>j</code> is at the end of <code>str2</code>, after we can no longer find a match.</div>

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int i = 0, j = 0, M = s.size(), N = t.size();
        for (; i < M && j < N; ++i) {
            if (s[i] == t[j] || ('a' + (s[i] - 'a' + 1) % 26) == t[j]) ++j;
        }
        return j == N;
    }
};
```