# [720. Longest Word in Dictionary (Easy)](https://leetcode.com/problems/longest-word-in-dictionary/)

<p>Given a list of strings <code>words</code> representing an English Dictionary, find the longest word in <code>words</code> that can be built one character at a time by other words in <code>words</code>.  If there is more than one possible answer, return the longest word with the smallest lexicographical order.</p>  If there is no answer, return the empty string.

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> 
words = ["w","wo","wor","worl", "world"]
<b>Output:</b> "world"
<b>Explanation:</b> 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
<b>Output:</b> "apple"
<b>Explanation:</b> 
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
</pre>
<p></p>

<p><b>Note:</b>
</p><li>All the strings in the input will only contain lowercase letters.</li>
<li>The length of <code>words</code> will be in the range <code>[1, 1000]</code>.</li>
<li>The length of <code>words[i]</code> will be in the range <code>[1, 30]</code>.</li>
<p></p>

**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Trie](https://leetcode.com/tag/trie/)

**Similar Questions**:
* [Longest Word in Dictionary through Deleting (Medium)](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/)
* [Implement Magic Dictionary (Medium)](https://leetcode.com/problems/implement-magic-dictionary/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/longest-word-in-dictionary/
// Author: github.com/lzl124631x
// Time: O(NW)
// Space: O(Nw)
class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> s;
        for (auto &w : words) s.insert(w);
        string ans;
        for (auto &w : words) {
            if (w.size() < ans.size()) continue;
            auto x = w;
            do {
                x.pop_back();
            } while (x.size() && s.find(x) != s.end());
            if (x.size()) continue;
            if (w.size() > ans.size()
               || (w.size() == ans.size() && w < ans)) ans = w;
        }
        return ans;
    }
};
```