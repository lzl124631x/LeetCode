# [1593. Split a String Into the Max Number of Unique Substrings (Medium)](https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/)

<p>Given a string&nbsp;<code>s</code><var>,</var>&nbsp;return <em>the maximum&nbsp;number of unique substrings that the given string can be split into</em>.</p>

<p>You can split string&nbsp;<code>s</code> into any list of&nbsp;<strong>non-empty substrings</strong>, where the concatenation of the substrings forms the original string.&nbsp;However, you must split the substrings such that all of them are <strong>unique</strong>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "ababccc"
<strong>Output:</strong> 5
<strong>Explanation</strong>: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aba"
<strong>Output:</strong> 2
<strong>Explanation</strong>: One way to split maximally is ['a', 'ba'].
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "aa"
<strong>Output:</strong> 1
<strong>Explanation</strong>: It is impossible to split the string any further.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>
	<p><code>1 &lt;= s.length&nbsp;&lt;= 16</code></p>
	</li>
	<li>
	<p><code>s</code> contains&nbsp;only lower case English letters.</p>
	</li>
</ul>


**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/)

## Solution 1. Backtrack

```cpp
// OJ: https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
    unordered_set<string> m;
    int ans = 0;
    void dfs(string &s, int i) {
        if (i == s.size()) {
            ans = max(ans, (int)m.size());
            return;
        }
        for (int j = i; j < s.size(); ++j) {
            string sub = s.substr(i, j - i + 1);
            if (m.count(sub)) continue;
            m.insert(sub);
            dfs(s, j + 1);
            m.erase(sub);
        }
    }
public:
    int maxUniqueSplit(string s) {
        dfs(s, 0);
        return ans;
    }
};
```