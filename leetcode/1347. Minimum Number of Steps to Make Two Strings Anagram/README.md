# [1347. Minimum Number of Steps to Make Two Strings Anagram (Medium)](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/)

<p>Given two equal-size strings <code>s</code> and <code>t</code>. In one step you can choose <strong>any character</strong> of <code>t</code> and replace it with <strong>another character</strong>.</p>

<p>Return <em>the minimum number of steps</em> to make <code>t</code>&nbsp;an anagram of <code>s</code>.</p>

<p>An&nbsp;<strong>Anagram</strong>&nbsp;of a&nbsp;string&nbsp;is a string that contains the same characters with a different (or the same) ordering.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "bab", t = "aba"
<strong>Output:</strong> 1
<strong>Explanation:</strong> Replace the first 'a' in t with b, t = "bba" which is anagram of s.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "leetcode", t = "practice"
<strong>Output:</strong> 5
<strong>Explanation:</strong> Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "anagram", t = "mangaar"
<strong>Output:</strong> 0
<strong>Explanation:</strong> "anagram" and "mangaar" are anagrams. 
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "xxyyzz", t = "xxyyzz"
<strong>Output:</strong> 0
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> s = "friend", t = "family"
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50000</code></li>
	<li><code>s.length == t.length</code></li>
	<li><code>s</code> and <code>t</code> contain lower-case English letters only.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26] = {0}, ans = 0;
        for (char c : s) cnt[c - 'a']++;
        for (char c : t) cnt[c - 'a']--;
        for (int n : cnt) {
            if (n > 0) ans += n;
        }
        return ans;
    }
};
```