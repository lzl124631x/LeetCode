# [2486. Append Characters to String to Make Subsequence (Medium)](https://leetcode.com/problems/append-characters-to-string-to-make-subsequence)

<p>You are given two strings <code>s</code> and <code>t</code> consisting of only lowercase English letters.</p>
<p>Return <em>the minimum number of characters that need to be appended to the end of </em><code>s</code><em> so that </em><code>t</code><em> becomes a <strong>subsequence</strong> of </em><code>s</code>.</p>
<p>A <strong>subsequence</strong> is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "coaching", t = "coding"
<strong>Output:</strong> 4
<strong>Explanation:</strong> Append the characters "ding" to the end of s so that s = "coachingding".
Now, t is a subsequence of s ("<u><strong>co</strong></u>aching<u><strong>ding</strong></u>").
It can be shown that appending any 3 characters to the end of s will never make t a subsequence.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "abcde", t = "a"
<strong>Output:</strong> 0
<strong>Explanation:</strong> t is already a subsequence of s ("<u><strong>a</strong></u>bcde").
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s = "z", t = "abcde"
<strong>Output:</strong> 5
<strong>Explanation:</strong> Append the characters "abcde" to the end of s so that s = "zabcde".
Now, t is a subsequence of s ("z<u><strong>abcde</strong></u>").
It can be shown that appending any 4 characters to the end of s will never make t a subsequence.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> and <code>t</code> consist only of lowercase English letters.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Is Subsequence (Easy)](https://leetcode.com/problems/is-subsequence/)
* [Minimum Operations to Make a Subsequence (Hard)](https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/)

## Solution 1. Two Pointers

```cpp
// OJ: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    int appendCharacters(string s, string t) {
        int M = s.size(), N = t.size(), i = 0, j = 0;
        while (i < M && j < N) {
            while (i < M && s[i] != t[j]) ++i;
            if (i < M) ++i, ++j;
        }
        return N - j;
    }
};
```