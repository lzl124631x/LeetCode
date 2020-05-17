# [438. Find All Anagrams in a String (Medium)](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

<p>Given a string <b>s</b> and a <b>non-empty</b> string <b>p</b>, find all the start indices of <b>p</b>'s anagrams in <b>s</b>.</p>

<p>Strings consists of lowercase English letters only and the length of both strings <b>s</b> and <b>p</b> will not be larger than 20,100.</p>

<p>The order of output does not matter.</p>

<p><b>Example 1:</b>
</p><pre><b>Input:</b>
s: "cbaebabacd" p: "abc"

<b>Output:</b>
[0, 6]

<b>Explanation:</b>
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
</pre>
<p></p>

<p><b>Example 2:</b>
</p><pre><b>Input:</b>
s: "abab" p: "ab"

<b>Output:</b>
[0, 1, 2]

<b>Explanation:</b>
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
</pre>
<p></p>

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [Valid Anagram (Easy)](https://leetcode.com/problems/valid-anagram/)
* [Permutation in String (Medium)](https://leetcode.com/problems/permutation-in-string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int target[26] = {}, cnt[26] = {};
        for (char c : p) target[c - 'a']++;
        vector<int> ans;
        for (int i = 0; i < s.size(); ++i) {
            if (i >= p.size()) cnt[s[i - p.size()] - 'a']--;
            cnt[s[i] - 'a']++;
            int j = 0;
            for (; j < 26; ++j) {
                if (cnt[j] != target[j]) break;
            }
            if (j == 26) ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};
```