# [44. Wildcard Matching (Hard)](https://leetcode.com/problems/wildcard-matching/)

<p>Given an input string (<code>s</code>) and a pattern (<code>p</code>), implement wildcard pattern matching with support for <code>'?'</code> and <code>'*'</code>.</p>

<pre>'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
</pre>

<p>The matching should cover the <strong>entire</strong> input string (not partial).</p>

<p><strong>Note:</strong></p>

<ul>
	<li><code>s</code>&nbsp;could be empty and contains only lowercase letters <code>a-z</code>.</li>
	<li><code>p</code> could be empty and contains only lowercase letters <code>a-z</code>, and characters like <code><font face="monospace">?</font></code>&nbsp;or&nbsp;<code>*</code>.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong>
s = "aa"
p = "a"
<strong>Output:</strong> false
<strong>Explanation:</strong> "a" does not match the entire string "aa".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong>
s = "aa"
p = "*"
<strong>Output:</strong> true
<strong>Explanation:</strong>&nbsp;'*' matches any sequence.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong>
s = "cb"
p = "?a"
<strong>Output:</strong> false
<strong>Explanation:</strong>&nbsp;'?' matches 'c', but the second letter is 'a', which does not match 'b'.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong>
s = "adceb"
p = "*a*b"
<strong>Output:</strong> true
<strong>Explanation:</strong>&nbsp;The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong>
s = "acdcb"
p = "a*c?b"
<strong>Output:</strong> false
</pre>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Regular Expression Matching (Hard)](https://leetcode.com/problems/regular-expression-matching/)

## Solution 1. DP Top-down

```cpp
// OJ: https://leetcode.com/problems/wildcard-matching/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
    int M, N;
    vector<vector<int>> m;
    bool isMatch(string &s, string &p, int i, int j) {
        if (m[i][j] != -1) return m[i][j];
        int &ans = m[i][j];
        for (; j < N; ++j) {
            if (p[j] != '*' && i >= M) return ans = false;
            if (p[j] == '?') ++i;
            else if (p[j] == '*') {
                while (j + 1 < N && p[j + 1] == '*') ++j;
                for (int k = 0; i + k <= M; ++k) {
                    if (isMatch(s, p, i + k, j + 1)) return ans = true;
                }
            } else if (s[i++] != p[j]) return ans = false;
        }
        return ans = i >= M;
    }
public:
    bool isMatch(string s, string p) {
        M = s.size(), N = p.size();
        m.assign(M + 1, vector<int>(N + 1, -1));
        return isMatch(s, p, 0, 0);
    }
};
```