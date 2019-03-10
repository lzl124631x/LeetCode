# [408. Valid Word Abbreviation (Easy)](https://leetcode.com/problems/valid-word-abbreviation/)

<p>
Given a <b>non-empty</b> string <code>s</code> and an abbreviation <code>abbr</code>, return whether the string matches with the given abbreviation.
</p>

<p>A string such as <code>"word"</code> contains only the following valid abbreviations:</p>

<pre>["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
</pre>

<p>Notice that only the above abbreviations are valid abbreviations of the string <code>"word"</code>. Any other string is not a valid abbreviation of <code>"word"</code>.</p>

<p><b>Note:</b><br>
Assume <code>s</code> contains only lowercase letters and <code>abbr</code> contains only lowercase letters and digits.
</p>

<p><b>Example 1:</b><br>
</p><pre>Given <b>s</b> = "internationalization", <b>abbr</b> = "i12iz4n":

Return true.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre>Given <b>s</b> = "apple", <b>abbr</b> = "a2e":

Return false.
</pre>
<p></p>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Minimum Unique Word Abbreviation (Hard)](https://leetcode.com/problems/minimum-unique-word-abbreviation/)
* [Word Abbreviation (Hard)](https://leetcode.com/problems/word-abbreviation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/valid-word-abbreviation/
// Author: github.com/lzl124631x
// Time: O(M+N)
// Space: O(1)
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0, M = word.size(), N = abbr.size();
        while (i < M && j < N) {
            if (isalpha(abbr[j])) {
                if (word[i] != abbr[j]) return false;
                ++i;
                ++j;
                continue;
            }
            int len = 0;
            while (j < N && isdigit(abbr[j])) {
                len = 10 * len + (abbr[j++] - '0');
                if (!len) return false;
            }
            i += len;
        }
        return i == M && j == N;
    }
};
```