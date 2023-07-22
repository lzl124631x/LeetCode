# [2309. Greatest English Letter in Upper and Lower Case (Easy)](https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case)

<p>Given a string of English letters <code>s</code>, return <em>the <strong>greatest </strong>English letter which occurs as <strong>both</strong> a lowercase and uppercase letter in</em> <code>s</code>. The returned letter should be in <strong>uppercase</strong>. If no such letter exists, return <em>an empty string</em>.</p>
<p>An English letter <code>b</code> is <strong>greater</strong> than another letter <code>a</code> if <code>b</code> appears <strong>after</strong> <code>a</code> in the English alphabet.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "l<strong><u>Ee</u></strong>TcOd<u><strong>E</strong></u>"
<strong>Output:</strong> "E"
<strong>Explanation:</strong>
The letter 'E' is the only letter to appear in both lower and upper case.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "a<strong><u>rR</u></strong>AzFif"
<strong>Output:</strong> "R"
<strong>Explanation:</strong>
The letter 'R' is the greatest letter to appear in both lower and upper case.
Note that 'A' and 'F' also appear in both lower and upper case, but 'R' is greater than 'F' or 'A'.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s = "AbCdEfGhIjK"
<strong>Output:</strong> ""
<strong>Explanation:</strong>
There is no letter that appears in both lower and upper case.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of lowercase and uppercase English letters.</li>
</ul>

**Companies**:
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Enumeration](https://leetcode.com/tag/enumeration/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string greatestLetter(string s) {
        char ans = 0;
        int seen[26] = {};
        for (char c : s) {
            int lower = !!islower(c), i = lower ? c - 'a' : c - 'A';
            seen[i] |= 1 << lower;
            if (seen[i] == 3 && 'A' + i > ans) ans = 'A' + i;
        }
        return ans ? string(1, ans) : "";
    }
};
```