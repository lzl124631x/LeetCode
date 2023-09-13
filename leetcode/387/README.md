# [387. First Unique Character in a String (Easy)](https://leetcode.com/problems/first-unique-character-in-a-string/)

<p>Given a string <code>s</code>, <em>find the first non-repeating character in it and return its index</em>. If it does not exist, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> s = "leetcode"
<strong>Output:</strong> 0
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> s = "loveleetcode"
<strong>Output:</strong> 2
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> s = "aabb"
<strong>Output:</strong> -1
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
</ul>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg), [Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple), [Zillow](https://leetcode.com/company/zillow), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Yahoo](https://leetcode.com/company/yahoo)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Queue](https://leetcode.com/tag/queue/), [Counting](https://leetcode.com/tag/counting/)

**Similar Questions**:
* [Sort Characters By Frequency (Medium)](https://leetcode.com/problems/sort-characters-by-frequency/)
* [First Letter to Appear Twice (Easy)](https://leetcode.com/problems/first-letter-to-appear-twice/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/first-unique-character-in-a-string/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(1)
class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        for (int i = 0; i < s.size(); ++i) {
            if (cnt[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
```