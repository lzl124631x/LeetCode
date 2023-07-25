# [2531. Make Number of Distinct Characters Equal (Medium)](https://leetcode.com/problems/make-number-of-distinct-characters-equal)

<p>You are given two <strong>0-indexed</strong> strings <code>word1</code> and <code>word2</code>.</p>
<p>A <strong>move</strong> consists of choosing two indices <code>i</code> and <code>j</code> such that <code>0 &lt;= i &lt; word1.length</code> and <code>0 &lt;= j &lt; word2.length</code> and swapping <code>word1[i]</code> with <code>word2[j]</code>.</p>
<p>Return <code>true</code> <em>if it is possible to get the number of distinct characters in</em> <code>word1</code> <em>and</em> <code>word2</code> <em>to be equal with <strong>exactly one</strong> move. </em>Return <code>false</code> <em>otherwise</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> word1 = "ac", word2 = "b"
<strong>Output:</strong> false
<strong>Explanation:</strong> Any pair of swaps would yield two distinct characters in the first string, and one in the second string.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> word1 = "abcc", word2 = "aab"
<strong>Output:</strong> true
<strong>Explanation:</strong> We swap index 2 of the first string with index 0 of the second string. The resulting strings are word1 = "abac" and word2 = "cab", which both have 3 distinct characters.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> word1 = "abcde", word2 = "fghij"
<strong>Output:</strong> true
<strong>Explanation:</strong> Both resulting strings will have 5 distinct characters, regardless of which indices we swap.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= word1.length, word2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>word1</code> and <code>word2</code> consist of only lowercase English letters.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Counting](https://leetcode.com/tag/counting/)

**Similar Questions**:
* [Bulls and Cows (Medium)](https://leetcode.com/problems/bulls-and-cows/)
* [Buddy Strings (Easy)](https://leetcode.com/problems/buddy-strings/)
* [Minimum Swaps to Make Strings Equal (Medium)](https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/)
* [Check if One String Swap Can Make Strings Equal (Easy)](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/)
* [Check if All Characters Have Equal Number of Occurrences (Easy)](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/make-number-of-distinct-characters-equal
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    bool isItPossible(string s, string t) {
        int cs[26] = {}, us = 0, ct[26] = {}, ut = 0;
        for (char c : s) us += cs[c - 'a']++ == 0;
        for (char c : t) ut += ct[c - 'a']++ == 0;
        for (int i = 0; i < 26; ++i) {
            if (cs[i] == 0) continue;
            us -= cs[i]-- == 1;
            for (int j = 0; j < 26; ++j) {
                if (ct[j] == 0) continue;
                ut -= ct[j]-- == 1;
                us += cs[j]++ == 0;
                ut += ct[i]++ == 0;
                if (us == ut) return true;
                ut -= ct[i]-- == 1;
                us -= cs[j]-- == 1;
                ut += ct[j]++ == 0;
            }
            us += cs[i]++ == 0;
        }
        return false;
    }
};
```