# [211. Design Add and Search Words Data Structure (Medium)](https://leetcode.com/problems/design-add-and-search-words-data-structure/)

<p>Design a data structure that supports adding new words and finding if a string matches any previously added string.</p>

<p>Implement the <code>WordDictionary</code> class:</p>

<ul>
	<li><code>WordDictionary()</code>&nbsp;Initializes the object.</li>
	<li><code>void addWord(word)</code> Adds <code>word</code> to the data structure, it can be matched later.</li>
	<li><code>bool search(word)</code>&nbsp;Returns <code>true</code> if there is any string in the data structure that matches <code>word</code>&nbsp;or <code>false</code> otherwise. <code>word</code> may contain dots <code>'.'</code> where dots can be matched with any letter.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example:</strong></p>

<pre><strong>Input</strong>
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
<strong>Output</strong>
[null,null,null,null,false,true,true,true]

<strong>Explanation</strong>
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 500</code></li>
	<li><code>word</code> in <code>addWord</code> consists lower-case English letters.</li>
	<li><code>word</code> in <code>search</code> consist of&nbsp; <code>'.'</code> or lower-case English letters.</li>
	<li>At most <code>50000</code>&nbsp;calls will be made to <code>addWord</code>&nbsp;and <code>search</code>.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Oracle](https://leetcode.com/company/oracle), [Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Design](https://leetcode.com/tag/design/), [Trie](https://leetcode.com/tag/trie/)

**Similar Questions**:
* [Implement Trie (Prefix Tree) (Medium)](https://leetcode.com/problems/implement-trie-prefix-tree/)
* [Prefix and Suffix Search (Hard)](https://leetcode.com/problems/prefix-and-suffix-search/)

## Solution 1. Trie

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
        return dfs(&root, word, 0);
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