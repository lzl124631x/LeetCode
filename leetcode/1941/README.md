# [1941. Check if All Characters Have Equal Number of Occurrences (Easy)](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/)

<p>Given a string <code>s</code>, return <code>true</code><em> if </em><code>s</code><em> is a <strong>good</strong> string, or </em><code>false</code><em> otherwise</em>.</p>

<p>A string <code>s</code> is <strong>good</strong> if <strong>all</strong> the characters that appear in <code>s</code> have the <strong>same</strong> number of occurrences (i.e., the same frequency).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abacbc"
<strong>Output:</strong> true
<strong>Explanation:</strong> The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aaabb"
<strong>Output:</strong> false
<strong>Explanation:</strong> The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(C) where C is the range of the characters
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int cnt[26] = {}, mx = 0;
        for (char c : s) {
            mx = max(mx, ++cnt[c - 'a']);
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] && cnt[i] != mx) return false;
        }
        return true;
    }
};
```