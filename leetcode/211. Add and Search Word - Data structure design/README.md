# [211. Add and Search Word - Data structure design (Medium)](https://leetcode.com/problems/add-and-search-word-data-structure-design/)

<p>Design a data structure that supports the following two operations:</p>

<pre>void addWord(word)
bool search(word)
</pre>

<p>search(word) can search a literal word or a regular expression string containing only letters <code>a-z</code> or <code>.</code>. A <code>.</code> means it can represent any one letter.</p>

<p><strong>Example:</strong></p>

<pre>addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -&gt; false
search("bad") -&gt; true
search(".ad") -&gt; true
search("b..") -&gt; true
</pre>

<p><b>Note:</b><br>
You may assume that all words are consist of lowercase letters <code>a-z</code>.</p>


**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/), [Design](https://leetcode.com/tag/design/), [Trie](https://leetcode.com/tag/trie/)

**Similar Questions**:
* [Implement Trie (Prefix Tree) (Medium)](https://leetcode.com/problems/implement-trie-prefix-tree/)
* [Prefix and Suffix Search (Hard)](https://leetcode.com/problems/prefix-and-suffix-search/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/add-and-search-word-data-structure-design/
// Author: github.com/lzl124631x
// Time:
//      WordDictionary: O(1)
//      addWord: O(W)
//      search: O(26^W)
// Space: O(NW)
struct TrieNode {
    TrieNode *next[26] = {};
    bool end = false;
};
class WordDictionary {
    TrieNode root;
    bool dfs(TrieNode *node, string &word, int i) {
        if (!node) return false;
        if (i == word.size()) return node->end;
        if (word[i] != '.') return dfs(node->next[word[i] - 'a'], word, i + 1);
        for (int j = 0; j < 26; ++j) {
            if (dfs(node->next[j], word, i + 1)) return true;
        }
        return false;
    }
public:
    void addWord(string word) {
        auto node = &root;
        for (char c : word) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->end = true;
    }
    bool search(string word) {
        auto node = &root;
        return dfs(node, word, 0);
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/add-and-search-word-data-structure-design/
// Author: github.com/lzl124631x
// Time:
//      WordDictionary: O(1)
//      addWord: O(1)
//      search: O(NW)
// Space: O(NW)
class WordDictionary {
    unordered_map<int, vector<string>> m;
public:
    void addWord(string word) {
        m[word.size()].push_back(word);
    }
    bool search(string word) {
        if (m.count(word.size()) == 0) return false;
        for (auto s : m[word.size()]) {
            int i = 0;
            for (; i < word.size(); ++i) {
                if (word[i] != '.' && word[i] != s[i]) break;
            }
            if (i == word.size()) return true;
        }
        return false;
    }
};
```