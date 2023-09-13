# [854. K-Similar Strings (Hard)](https://leetcode.com/problems/k-similar-strings/)

<p>Strings <code>s1</code> and <code>s2</code> are <code>k</code><strong>-similar</strong> (for some non-negative integer <code>k</code>) if we can swap the positions of two letters in <code>s1</code> exactly <code>k</code> times so that the resulting string equals <code>s2</code>.</p>

<p>Given two anagrams <code>s1</code> and <code>s2</code>, return the smallest <code>k</code> for which <code>s1</code> and <code>s2</code> are <code>k</code><strong>-similar</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> s1 = "ab", s2 = "ba"
<strong>Output:</strong> 1
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> s1 = "abc", s2 = "bca"
<strong>Output:</strong> 2
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> s1 = "abac", s2 = "baca"
<strong>Output:</strong> 2
</pre><p><strong>Example 4:</strong></p>
<pre><strong>Input:</strong> s1 = "aabc", s2 = "abca"
<strong>Output:</strong> 2
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s1.length &lt;= 20</code></li>
	<li><code>s2.length == s1.length</code></li>
	<li><code>s1</code> and <code>s2</code> contain only lowercase letters from the set <code>{'a', 'b', 'c', 'd', 'e', 'f'}</code>.</li>
	<li><code>s2</code> is an anagram of <code>s1</code>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Couples Holding Hands (Hard)](https://leetcode.com/problems/couples-holding-hands/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/k-similar-strings/
// Author: github.com/lzl124631x
// Time: O(?)
// Space: O(?)
// Ref: https://leetcode.com/problems/k-similar-strings/discuss/151500/Logical-Thinking-with-Clear-Java-Code
class Solution {
public:
    int kSimilarity(string s, string t) {
        queue<string> q{{s}};
        unordered_set<string> seen{{s}};
        int step = 0;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto u = q.front();
                q.pop();
                if (u == t) return step;
                int i = 0; // Get all possible neighbor strings
                while (i < s.size() && u[i] == t[i]) ++i; // find the first index that u[i] != t[i]
                for (int j = i + 1; j < s.size(); ++j) { // find a good swap index j such that u[j] == t[i]
                    if (u[j] == t[i]) {
                        swap(u[i], u[j]);
                        if (seen.count(u) == 0) {
                            seen.insert(u);
                            q.push(u);
                        }
                        swap(u[i], u[j]);
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};
```