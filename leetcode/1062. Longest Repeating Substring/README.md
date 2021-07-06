# [1062. Longest Repeating Substring (Medium)](https://leetcode.com/problems/longest-repeating-substring/)

<p>Given a string <code>s</code>, find out the length of the longest repeating substring(s). Return <code>0</code> if no repeating substring exists.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcd"
<strong>Output:</strong> 0
<strong>Explanation: </strong>There is no repeating substring.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abbaba"
<strong>Output:</strong> 2
<strong>Explanation: </strong>The longest repeating substrings are "ab" and "ba", each of which occurs twice.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "aabcaabdaab"
<strong>Output:</strong> 3
<strong>Explanation: </strong>The longest repeating substring is "aab", which occurs <code>3</code> times.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "aaaaa"
<strong>Output:</strong> 4
<strong>Explanation: </strong>The longest repeating substring is "aaaa", which occurs twice.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The string <code>s</code> consists of only lowercase English letters from <code>'a'</code> - <code>'z'</code>.</li>
	<li><code>1 &lt;= s.length &lt;= 1500</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Rolling Hash](https://leetcode.com/tag/rolling-hash/), [Suffix Array](https://leetcode.com/tag/suffix-array/), [Hash Function](https://leetcode.com/tag/hash-function/)

## Solution 1. Rabin Karp + Binary Search

```cpp
// OJ: https://leetcode.com/problems/longest-repeating-substring/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
    bool valid(string &s, int len) {
        unsigned long long d = 16777619, h = 0, p = 1;
        unordered_set<unsigned long long> seen;
        for (int i = 0; i < s.size(); ++i) {
            h = h * d + s[i];
            if (i < len) p *= d;
            else h -= s[i - len] * p;
            if (i >= len - 1) {
                if (seen.count(h)) return true; 
                seen.insert(h);
            }
        }
        return false;
    }
public:
    int longestRepeatingSubstring(string s) {
        int L = 0, R = s.size() - 1;
        while (L < R) {
            int M = (L + R + 1) / 2;
            if (valid(s, M)) L = M;
            else R = M - 1;
        }
        return L;
    }
};
```