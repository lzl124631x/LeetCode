# [320. Generalized Abbreviation (Medium)](https://leetcode.com/problems/generalized-abbreviation/)

<p>Write a function to generate the generalized abbreviations of a word.&nbsp;</p>

<p><strong>Note:&nbsp;</strong>The order of the output does not matter.</p>

<p><b>Example:</b></p>

<pre><strong>Input:</strong> <code>"word"</code>
<strong>Output:</strong>
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
</pre>

<p>&nbsp;</p>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Subsets (Medium)](https://leetcode.com/problems/subsets/)
* [Unique Word Abbreviation (Medium)](https://leetcode.com/problems/unique-word-abbreviation/)
* [Minimum Unique Word Abbreviation (Hard)](https://leetcode.com/problems/minimum-unique-word-abbreviation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/generalized-abbreviation/
// Author: github.com/lzl124631x
// Time: O(2^W * W)
// Space: O(W)
class Solution {
private:
    string encode(string word, int mask) {
        string ans;
        int cnt = 0;
        for (int i = 0; i < word.size(); ++i) {
            if (mask & (1 << i)) ++cnt;
            else {
                if (cnt) {
                    ans += to_string(cnt);
                    cnt = 0;
                }
                ans += word[i];
            }
        }
        if (cnt) ans += to_string(cnt);
        return ans;
    }
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        for (int i = 0; i < (1 << word.size()); ++i) ans.push_back(encode(word, i));
        return ans;
    }
};
```