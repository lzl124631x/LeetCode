# [1297. Maximum Number of Occurrences of a Substring (Medium)](https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/)

<p>Given a string <code>s</code>, return the maximum number of ocurrences of <strong>any</strong> substring&nbsp;under the following rules:</p>

<ul>
	<li>The number of unique characters in the substring must be less than or equal to <code>maxLetters</code>.</li>
	<li>The substring size must be between <code>minSize</code> and <code>maxSize</code>&nbsp;inclusive.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> Substring "aab" has 2 ocurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> Substring "aaa" occur 2 times in the string. It can overlap.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
<strong>Output:</strong> 3
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= maxLetters &lt;= 26</code></li>
	<li><code>1 &lt;= minSize &lt;= maxSize &lt;= min(26, s.length)</code></li>
	<li><code>s</code> only contains lowercase English letters.</li>
</ul>

**Companies**:  
[Twitter](https://leetcode.com/company/twitter)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1. Rabin Karp

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unsigned h = 0, p = 1, d = 16777619, ans = 0;
        unordered_map<unsigned, unsigned> cnt, m;
        for (int i = 0; i < s.size(); ++i) {
            h = h * d + s[i] - 'a';
            m[s[i]]++;
            if (i < minSize) {
                p *= d;
            }
            if (i >= minSize) {
                h -= p * (s[i - minSize] - 'a');
                if (--m[s[i - minSize]] == 0) m.erase(s[i - minSize]);
            }
            if (i >= minSize - 1 && m.size() <= maxLetters) {
                ans = max(ans, ++cnt[h]);
            }
        }
        return ans;
    }
};
```