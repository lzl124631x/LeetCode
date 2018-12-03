# [387. First Unique Character in a String (Easy)](https://leetcode.com/problems/first-unique-character-in-a-string/)

<p>
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
</p>
<p><b>Examples:</b>
</p><pre>s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
</pre>
<p></p>

<p>
<b>Note:</b> You may assume the string contain only lowercase letters.
</p>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg), [Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple), [Zillow](https://leetcode.com/company/zillow), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Yahoo](https://leetcode.com/company/yahoo)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Sort Characters By Frequency (Medium)](https://leetcode.com/problems/sort-characters-by-frequency/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/first-unique-character-in-a-string/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(1)
class Solution {
public:
    int firstUniqChar(string s) {
        int M[26] = {0};
        for (char c : s) {
            M[c - 'a']++;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (M[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
```