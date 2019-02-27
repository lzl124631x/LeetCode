# [567. Permutation in String (Medium)](https://leetcode.com/problems/permutation-in-string/)

Given two strings <b>s1</b> and <b>s2</b>, write a function to return true if <b>s2</b> contains the permutation of <b>s1</b>. In other words, one of the first string's permutations is the <b>substring</b> of the second string.

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b>s1 = "ab" s2 = "eidbaooo"
<b>Output:</b>True
<b>Explanation:</b> s2 contains one permutation of s1 ("ba").
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b>s1= "ab" s2 = "eidboaoo"
<b>Output:</b> False
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The input strings only contain lower case letters.</li>
<li>The length of both given strings is in range [1, 10,000].</li>
</ol>
<p></p>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Minimum Window Substring (Hard)](https://leetcode.com/problems/minimum-window-substring/)
* [Find All Anagrams in a String (Easy)](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/permutation-in-string/
// Author: github.com/lzl124631x
// Time: O(S2)
// Space: O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int N = s1.size();
        int cnts[26] = {0};
        for (char c : s1) cnts[c - 'a']++;
        for (int i = 0; i < s2.size(); ++i) {
            cnts[s2[i] - 'a']--;
            if (i - N >= 0) cnts[s2[i - N] - 'a']++;
            bool match = true;
            for (int j = 0; j < 26 && match; ++j) {
                if (cnts[j]) match = false;
            }
            if (match) return true;
        }
        return false;
    }
};
```