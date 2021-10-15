# [1081. Smallest Subsequence of Distinct Characters (Medium)](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/)

<p>Given a string <code>s</code>, return <em>the lexicographically smallest subsequence of</em> <code>s</code> <em>that contains all the distinct characters of</em> <code>s</code> <em>exactly once</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "bcabc"
<strong>Output:</strong> "abc"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "cbacdcbc"
<strong>Output:</strong> "acdb"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>

<p>&nbsp;</p>
<strong>Note:</strong> This question is the same as 316: <a href="https://leetcode.com/problems/remove-duplicate-letters/" target="_blank">https://leetcode.com/problems/remove-duplicate-letters/</a>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack/)

**Similar Questions**:
* [Find the Most Competitive Subsequence (Medium)](https://leetcode.com/problems/find-the-most-competitive-subsequence/)

## Solution 1. Mono-stack + Greedy

```cpp
// OJ: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
// Author: github.com/lzl124631x
// Time: O(N) where `N` is the length of `s`, and `C` is the range of the letters
// Space: O(C)
class Solution {
public:
    string smallestSubsequence(string text) {
        int cnts[26] = {0}, used[26] = {0};
        for (char c : text) ++cnts[c - 'a'];
        string ans;
        for (char c : text) {
            cnts[c - 'a']--;
            if (used[c - 'a']) continue;
            while (ans.size() && cnts[ans.back() - 'a'] && c < ans.back()) {
                used[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(c);
            used[c - 'a'] = 1;
        }
        return ans;
    }
};
```