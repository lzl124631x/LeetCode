# [2351. First Letter to Appear Twice (Easy)](https://leetcode.com/problems/first-letter-to-appear-twice)

<p>Given a string <code>s</code> consisting of lowercase English letters, return <em>the first letter to appear <strong>twice</strong></em>.</p>

<p><strong>Note</strong>:</p>

<ul>
	<li>A letter <code>a</code> appears twice before another letter <code>b</code> if the <strong>second</strong> occurrence of <code>a</code> is before the <strong>second</strong> occurrence of <code>b</code>.</li>
	<li><code>s</code> will contain at least one letter that appears twice.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abccbaacz"
<strong>Output:</strong> "c"
<strong>Explanation:</strong>
The letter 'a' appears on the indexes 0, 5 and 6.
The letter 'b' appears on the indexes 1 and 4.
The letter 'c' appears on the indexes 2, 3 and 7.
The letter 'z' appears on the index 8.
The letter 'c' is the first letter to appear twice, because out of all the letters the index of its second occurrence is the smallest.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abcdd"
<strong>Output:</strong> "d"
<strong>Explanation:</strong>
The only letter that appears twice is 'd' so we return 'd'.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
	<li><code>s</code> has at least one repeated letter.</li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Counting](https://leetcode.com/tag/counting/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [First Unique Character in a String (Easy)](https://leetcode.com/problems/first-unique-character-in-a-string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/first-letter-to-appear-twice
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    char repeatedCharacter(string s) {
        int cnt[26] = {};
        for (char c : s) {
            if (++cnt[c - 'a'] > 1) return c;
        }
        return 0;
    }
};
```