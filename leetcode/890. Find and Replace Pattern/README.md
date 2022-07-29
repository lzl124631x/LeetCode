# [890. Find and Replace Pattern (Medium)](https://leetcode.com/problems/find-and-replace-pattern/)

<p>Given a list of strings <code>words</code> and a string <code>pattern</code>, return <em>a list of</em> <code>words[i]</code> <em>that match</em> <code>pattern</code>. You may return the answer in <strong>any order</strong>.</p>

<p>A word matches the pattern if there exists a permutation of letters <code>p</code> so that after replacing every letter <code>x</code> in the pattern with <code>p(x)</code>, we get the desired word.</p>

<p>Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
<strong>Output:</strong> ["mee","aqq"]
<strong>Explanation:</strong> "mee" matches the pattern because there is a permutation {a -&gt; m, b -&gt; e, ...}. 
"ccc" does not match the pattern because {a -&gt; c, b -&gt; c, ...} is not a permutation, since a and b map to the same letter.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["a","b","c"], pattern = "a"
<strong>Output:</strong> ["a","b","c"]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= pattern.length &lt;= 20</code></li>
	<li><code>1 &lt;= words.length &lt;= 50</code></li>
	<li><code>words[i].length == pattern.length</code></li>
	<li><code>pattern</code> and <code>words[i]</code> are lowercase English letters.</li>
</ul>

**Companies**:  
[Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-and-replace-pattern/
// Author: github.com/lzl124631x
// Time: O(NW) where N is the length of `A` and `W` is word length
// Space: O(1)
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& A, string p) {
        vector<string> ans;
        for (auto &s : A) {
            int m[26] = {[0 ... 25] = -1}, r[26] = {[0 ... 25] = -1}, i = 0;
            for (; i < p.size(); ++i) {
                int from = s[i] - 'a', to = p[i] - 'a';
                if ((m[from] != -1 && m[from] != to) || (r[to] != -1 && r[to] != from)) break;
                m[from] = to;
                r[to] = from;
            }
            if (i == p.size()) ans.push_back(s);
        }
        return ans;
    }
};
```