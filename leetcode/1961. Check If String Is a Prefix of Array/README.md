# [1961. Check If String Is a Prefix of Array (Easy)](https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/)

<p>Given a string <code>s</code> and an array of strings <code>words</code>, determine whether <code>s</code> is a <strong>prefix string</strong> of <code>words</code>.</p>

<p>A string <code>s</code> is a <strong>prefix string</strong> of <code>words</code> if <code>s</code> can be made by concatenating the first <code>k</code> strings in <code>words</code> for some <strong>positive</strong> <code>k</code> no larger than <code>words.length</code>.</p>

<p>Return <code>true</code><em> if </em><code>s</code><em> is a <strong>prefix string</strong> of </em><code>words</code><em>, or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "iloveleetcode", words = ["i","love","leetcode","apples"]
<strong>Output:</strong> true
<strong>Explanation:</strong>
s can be made by concatenating "i", "love", and "leetcode" together.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "iloveleetcode", words = ["apples","i","love","leetcode"]
<strong>Output:</strong> false
<strong>Explanation:</strong>
It is impossible to make s using a prefix of arr.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 20</code></li>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>words[i]</code> and <code>s</code> consist of only lowercase English letters.</li>
</ul>

# Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    bool isPrefixString(string s, vector<string>& A) {
        int j = 0, N = A.size();
        for (int i = 0; i < N && j < s.size(); ++i) {
            int k = 0;
            for (; j < s.size() && k < A[i].size() && s[j] == A[i][k]; ++k, ++j); // try matching `s` with `A[i]`.
            if (k != A[i].size()) return false; // If we can't match the entire `A[i]`, return false
        }
        return j == s.size(); // `s` must be matched entirely
    }
};
```