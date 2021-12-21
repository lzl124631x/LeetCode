# [291. Word Pattern II (Medium)](https://leetcode.com/problems/word-pattern-ii/)

<p>Given a <code>pattern</code> and a string <code>s</code>, return <code>true</code><em> if </em><code>s</code><em> <strong>matches</strong> the </em><code>pattern</code><em>.</em></p>

<p>A string <code>s</code> <b>matches</b> a <code>pattern</code> if there is some <strong>bijective mapping</strong> of single characters to strings such that if each character in <code>pattern</code> is replaced by the string it maps to, then the resulting string is <code>s</code>. A <strong>bijective mapping</strong> means that no two characters map to the same string, and no character maps to two different strings.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> pattern = "abab", s = "redblueredblue"
<strong>Output:</strong> true
<strong>Explanation:</strong> One possible mapping is as follows:
'a' -&gt; "red"
'b' -&gt; "blue"</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> pattern = "aaaa", s = "asdasdasdasd"
<strong>Output:</strong> true
<strong>Explanation:</strong> One possible mapping is as follows:
'a' -&gt; "asd"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> pattern = "abab", s = "asdasdasdasd"
<strong>Output:</strong> true
<strong>Explanation:</strong> One possible mapping is as follows:
'a' -&gt; "a"
'b' -&gt; "sdasd"
Note that 'a' and 'b' cannot both map to "asd" since the mapping is a bijection.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> pattern = "aabb", s = "xyzabcxzyabc"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= pattern.length, s.length &lt;= 20</code></li>
	<li><code>pattern</code> and <code>s</code> consist of only lower-case English letters.</li>
</ul>


**Companies**:  
[Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Word Pattern (Easy)](https://leetcode.com/problems/word-pattern/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/word-pattern-ii/
// Author: github.com/lzl124631x
// Time: O(PS)
// Space: O(S)
class Solution {
public:
    bool wordPatternMatch(string p, string s) {
        unordered_map<char, string> m;
        unordered_set<string> seen;
        function<bool(int,int)> dfs = [&](int i, int j) {
            if (i == p.size()) return j == s.size();
            if (m.count(p[i])) {
                auto t = m[p[i]];
                return s.substr(j, t.size()) == t && dfs(i + 1, j + t.size());
            } else {
                string t;
                for (int k = j; k < s.size(); ++k) {
                    t += s[k];
                    if (seen.count(t)) continue;
                    seen.insert(t);
                    m[p[i]] = t;
                    if (dfs(i + 1, k + 1)) return true;
                    seen.erase(t);
                    m.erase(p[i]);
                }
            }
            return false;
        };
        return dfs(0, 0);
    }
};
```