# [2781. Length of the Longest Valid Substring (Hard)](https://leetcode.com/problems/length-of-the-longest-valid-substring)

<p>You are given a string <code>word</code> and an array of strings <code>forbidden</code>.</p>
<p>A string is called <strong>valid</strong> if none of its substrings are present in <code>forbidden</code>.</p>
<p>Return <em>the length of the <strong>longest valid substring</strong> of the string </em><code>word</code>.</p>
<p>A <strong>substring</strong> is a contiguous sequence of characters in a string, possibly empty.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> word = "cbaaaabc", forbidden = ["aaa","cb"]
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 11 valid substrings in word: "c", "b", "a", "ba", "aa", "bc", "baa", "aab", "ab", "abc" and "aabc". The length of the longest valid substring is 4. 
It can be shown that all other substrings contain either "aaa" or "cb" as a substring. </pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> word = "leetcode", forbidden = ["de","le","e"]
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 11 valid substrings in word: "l", "t", "c", "o", "d", "tc", "co", "od", "tco", "cod", and "tcod". The length of the longest valid substring is 4.
It can be shown that all other substrings contain either "de", "le", or "e" as a substring. 
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= word.length &lt;= 10<sup>5</sup></code></li>
	<li><code>word</code> consists only of lowercase English letters.</li>
	<li><code>1 &lt;= forbidden.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= forbidden[i].length &lt;= 10</code></li>
	<li><code>forbidden[i]</code> consists only of lowercase English letters.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

## Solution 1. Trie

```cpp
// OJ: https://leetcode.com/problems/length-of-the-longest-valid-substring
// Author: github.com/lzl124631x
// Time: O(F + NK) where K is the maximum length of F[i]
// Space: O(F)
struct TrieNode {
    TrieNode *next[26] = {};
    bool end = false;
};
class Solution {
    void addWord(TrieNode *node, string &s) {
        for (int i = s.size() - 1; i >= 0; --i) {
            if (!node->next[s[i] - 'a']) node->next[s[i] - 'a'] = new TrieNode();
            node = node->next[s[i] - 'a'];
        }
        node->end = true;
    }
public:
    int longestValidSubstring(string s, vector<string>& F) {
        TrieNode root;
        for (auto &f : F) addWord(&root, f);
        int left = 0, ans = 0, N = s.size();
        for (int i = 0; i < N; ++i) {
            int j = i;
            bool found = false;
            auto node = &root;
            for (; j >= 0 && node->next[s[j] - 'a']; --j) { // find if there is some banned words ending at s[i]
                node = node->next[s[j] - 'a'];
                if (found = node->end) break;
            }
            if (found) left = max(left, j + 1); // If found, update the left bound
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
```

## Solution 2.

We use `unordered_set` instead of `Trie` to check forbidden words.

```cpp
// OJ: https://leetcode.com/problems/length-of-the-longest-valid-substring
// Author: github.com/lzl124631x
// Time: O(F + NK)
// Space: O(F)
class Solution {
public:
    int longestValidSubstring(string s, vector<string>& forbidden) {
        unordered_set<string> F(begin(forbidden), end(forbidden));
        int left = 0, ans = 0, N = s.size();
        for (int i = 0; i < N; ++i) {
            int j = 0;
            for (; j < 10 && i - j >= 0; ++j) {
                if (F.count(s.substr(i - j, j + 1))) break;
            }
            if (j < 10) left = max(left, i - j + 1);
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
```