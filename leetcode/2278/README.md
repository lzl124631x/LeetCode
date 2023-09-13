# [2278. Percentage of Letter in String (Easy)](https://leetcode.com/problems/percentage-of-letter-in-string)

<p>Given a string <code>s</code> and a character <code>letter</code>, return<em> the <strong>percentage</strong> of characters in </em><code>s</code><em> that equal </em><code>letter</code><em> <strong>rounded down</strong> to the nearest whole percent.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "foobar", letter = "o"
<strong>Output:</strong> 33
<strong>Explanation:</strong>
The percentage of characters in s that equal the letter 'o' is 2 / 6 * 100% = 33% when rounded down, so we return 33.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "jjjj", letter = "k"
<strong>Output:</strong> 0
<strong>Explanation:</strong>
The percentage of characters in s that equal the letter 'k' is 0%, so we return 0.</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
	<li><code>letter</code> is a lowercase English letter.</li>
</ul>

**Companies**:
[American Express](https://leetcode.com/company/american-express)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Sort Characters By Frequency (Medium)](https://leetcode.com/problems/sort-characters-by-frequency/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/percentage-of-letter-in-string
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt = 0;
        for (char c : s) cnt += c == letter;
        return cnt * 100 / s.size();
    }
};
```