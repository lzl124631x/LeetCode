# [242. Valid Anagram (Easy)](https://leetcode.com/problems/valid-anagram/)

<p>Given two strings <em>s</em> and <em>t&nbsp;</em>, write a function to determine if <em>t</em> is an anagram of <em>s</em>.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> <em>s</em> = "anagram", <em>t</em> = "nagaram"
<b>Output:</b> true
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> <em>s</em> = "rat", <em>t</em> = "car"
<b>Output: </b>false
</pre>

<p><strong>Note:</strong><br>
You may assume the string contains only lowercase alphabets.</p>

<p><strong>Follow up:</strong><br>
What if the inputs contain unicode characters? How would you adapt your solution to such case?</p>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Sort](https://leetcode.com/tag/sort/)

**Similar Questions**:
* [Group Anagrams (Medium)](https://leetcode.com/problems/group-anagrams/)
* [Palindrome Permutation (Easy)](https://leetcode.com/problems/palindrome-permutation/)
* [Find All Anagrams in a String (Medium)](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/valid-anagram/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(C)
class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;
        for (char c : t) cnt[c - 'a']--;
        for (int n : cnt) {
            if (n) return false;
        }
        return true;
    }
};
```