# [383. Ransom Note (Easy)](https://leetcode.com/problems/ransom-note/)

<p>
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom 
note can be constructed from the magazines ; otherwise, it will return false. 
</p>
<p>
Each letter in the magazine string can only be used once in your ransom note.
</p>

<p><b>Note:</b><br>
You may assume that both strings contain only lowercase letters.
</p>

<pre>canConstruct("a", "b") -&gt; false
canConstruct("aa", "ab") -&gt; false
canConstruct("aa", "aab") -&gt; true
</pre>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Stickers to Spell Word (Hard)](https://leetcode.com/problems/stickers-to-spell-word/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/ransom-note/
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = {0};
        for (char c : magazine) cnt[c - 'a']++;
        for (char c : ransomNote) {
            if (--cnt[c - 'a'] < 0) return false;
        }
        return true;
    }
};
```