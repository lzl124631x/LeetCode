# [290. Word Pattern (Easy)](https://leetcode.com/problems/word-pattern/)

<p>Given a <code>pattern</code> and a string <code>str</code>, find if <code>str</code> follows the same pattern.</p>

<p>Here <b>follow</b> means a full match, such that there is a bijection between a letter in <code>pattern</code> and a <b>non-empty</b> word in <code>str</code>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> pattern = <code>"abba"</code>, str = <code>"dog cat cat dog"</code>
<strong>Output:</strong> true</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong>pattern = <code>"abba"</code>, str = <code>"dog cat cat fish"</code>
<strong>Output:</strong> false</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> pattern = <code>"aaaa"</code>, str = <code>"dog cat cat dog"</code>
<strong>Output:</strong> false</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> pattern = <code>"abba"</code>, str = <code>"dog dog dog dog"</code>
<strong>Output:</strong> false</pre>

<p><b>Notes:</b><br>
You may assume <code>pattern</code> contains only lowercase letters, and <code>str</code> contains lowercase letters that may be separated by a single space.</p>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [Isomorphic Strings (Easy)](https://leetcode.com/problems/isomorphic-strings/)
* [Word Pattern II (Hard)](https://leetcode.com/problems/word-pattern-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/word-pattern/
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(M + N)
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m;
        unordered_map<string, char> r;
        istringstream ss(str);
        string word;
        for (char c : pattern) {
            if (!(ss >> word)) return false;
            if ((m.count(c) && m[c] != word)
                || r.count(word) && r[word] != c) return false;
            m[c] = word;
            r[word] = c;
        }
        return ss.eof();
    }
};
```