# [1180. Count Substrings with Only One Distinct Letter (Easy)](https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/)

<p>Given a string <code>s</code>, return <em>the number of substrings that have only <strong>one distinct</strong> letter</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aaaba"
<strong>Output:</strong> 8
<strong>Explanation: </strong>The substrings with one distinct letter are "aaa", "aa", "a", "b".
"aaa" occurs 1 time.
"aa" occurs 2 times.
"a" occurs 4 times.
"b" occurs 1 time.
So the answer is 1 + 2 + 4 + 1 = 8.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aaaaaaaaaa"
<strong>Output:</strong> 55
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> consists of only lowercase English letters.</li>
</ul>


**Companies**:  
[Virtu Financial](https://leetcode.com/company/virtu), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countLetters(string s) {
        int i = 0, N = s.size(), ans = 0;
        while (i < N) {
            int start = i;
            while (i < N && s[i] == s[start]) ++i;
            int len = i - start;
            ans += (1 + len) * len / 2;
        }
        return ans;
    }
};
```