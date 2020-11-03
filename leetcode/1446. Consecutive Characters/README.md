# [1446. Consecutive Characters (Easy)](https://leetcode.com/problems/consecutive-characters/)

<p>Given a string <code>s</code>, the power of the string is the maximum length of a non-empty substring that&nbsp;contains only one unique character.</p>

<p>Return <em>the power</em>&nbsp;of the string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "leetcode"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The substring "ee" is of length 2 with the character 'e' only.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abbcccddddeeeeedcba"
<strong>Output:</strong> 5
<strong>Explanation:</strong> The substring "eeeee" is of length 5 with the character 'e' only.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "triplepillooooow"
<strong>Output:</strong> 5
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "hooraaaaaaaaaaay"
<strong>Output:</strong> 11
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> s = "tourist"
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> contains only lowercase English letters.</li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Max Consecutive Ones (Easy)](https://leetcode.com/problems/max-consecutive-ones/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/consecutive-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxPower(string s) {
        int ans = 1, cnt = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) ans = max(ans, ++cnt);
            else cnt = 1;
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/consecutive-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxPower(string s) {
        int start = 0, ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == s[start]) ans = max(ans, i - start + 1);
            else start = i;
        }
        return ans;
    }
};
```