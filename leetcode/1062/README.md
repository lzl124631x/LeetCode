# [1062. Longest Repeating Substring (Medium)](https://leetcode.com/problems/longest-repeating-substring/)

<p>Given a string <code>s</code>, return <em>the length of the longest repeating substrings</em>. If no repeating substring exists, return <code>0</code>.</p>

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

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


**Companies**:  
[VMware](https://leetcode.com/company/vmware)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Rolling Hash](https://leetcode.com/tag/rolling-hash/), [Suffix Array](https://leetcode.com/tag/suffix-array/), [Hash Function](https://leetcode.com/tag/hash-function/)

## Solution 1. Rabin Karp + Binary Search

```cpp
// OJ: https://leetcode.com/problems/longest-repeating-substring/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int L = 1, R = s.size();
        auto valid = [&](int len) {
            unordered_set<unsigned> seen;
            unsigned h = 0, N = s.size(), p = 1, d = 16777619;
            for (int i = 0; i < N; ++i) {
                h = h * d + s[i];
                if (i < len) p *= d;
                else h -= p * s[i - len];
                if (i >= len - 1) {
                    if (seen.count(h)) return true;
                    seen.insert(h);
                }
            }
            return false;
        };
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(M)) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};
```