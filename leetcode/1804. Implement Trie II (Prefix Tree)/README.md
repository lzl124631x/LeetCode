# [1804. Implement Trie II (Prefix Tree) (Medium)](https://leetcode.com/problems/implement-trie-ii-prefix-tree/)

<p>A <a href="https://en.wikipedia.org/wiki/Trie" target="_blank"><strong>trie</strong></a> (pronounced as "try") or <strong>prefix tree</strong> is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.</p>

<p>Implement the Trie class:</p>

<ul>
	<li><code>Trie()</code> Initializes the trie object.</li>
	<li><code>void insert(String word)</code> Inserts the string <code>word</code> into the trie.</li>
	<li><code>int countWordsEqualTo(String word)</code> Returns the number of instances of the string <code>word</code> in the trie.</li>
	<li><code>int countWordsStartingWith(String prefix)</code> Returns the number of strings in the trie that have the string <code>prefix</code> as a prefix.</li>
	<li><code>void erase(String word)</code> Erases the string <code>word</code> from the trie.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["Trie", "insert", "insert", "countWordsEqualTo", "countWordsStartingWith", "erase", "countWordsEqualTo", "countWordsStartingWith", "erase", "countWordsStartingWith"]
[[], ["apple"], ["apple"], ["apple"], ["app"], ["apple"], ["apple"], ["app"], ["apple"], ["app"]]
<strong>Output</strong>
[null, null, null, 2, 2, null, 1, 1, null, 0]

<strong>Explanation</strong>
Trie trie = new Trie();
trie.insert("apple");               // Inserts "apple".
trie.insert("apple");               // Inserts another "apple".
trie.countWordsEqualTo("apple");    // There are two instances of "apple" so return 2.
trie.countWordsStartingWith("app"); // "app" is a prefix of "apple" so return 2.
trie.erase("apple");                // Erases one "apple".
trie.countWordsEqualTo("apple");    // Now there is only one instance of "apple" so return 1.
trie.countWordsStartingWith("app"); // return 1
trie.erase("apple");                // Erases "apple". Now the trie is empty.
trie.countWordsStartingWith("app"); // return 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length, prefix.length &lt;= 2000</code></li>
	<li><code>word</code> and <code>prefix</code> consist only of lowercase English letters.</li>
	<li>At most <code>3 * 10<sup>4</sup></code> calls <strong>in total</strong> will be made to <code>insert</code>, <code>countWordsEqualTo</code>, <code>countWordsStartingWith</code>, and <code>erase</code>.</li>
	<li>It is guaranteed that for any function call to <code>erase</code>, the string <code>word</code> will exist in the trie.</li>
</ul>


**Companies**:  
[Docusign](https://leetcode.com/company/docusign)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Design](https://leetcode.com/tag/design/), [Trie](https://leetcode.com/tag/trie/)

**Similar Questions**:
* [Implement Trie (Prefix Tree) (Medium)](https://leetcode.com/problems/implement-trie-prefix-tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/implement-trie-ii-prefix-tree/
// Author: github.com/lzl124631x
// Time:
//      Trie: O(1)
//      insert, countWordsEqualTo, countWordsStartingWith, erase: O(W)
// Space: O(1) extra space for all
struct TrieNode {
    TrieNode *next[26] = {};
    int cnt = 0, end = 0;
};
class Trie {
    TrieNode root;
    TrieNode *findNode(string &s) {
        auto node = &root;
        for (char c : s) {
            if (!node->next[c - 'a'] || node->next[c - 'a']->cnt == 0) return nullptr;
            node = node->next[c - 'a'];
        }
        return node;
    }
public:
    Trie() {}
    void insert(string s) {
        auto node = &root;
        for (char c : s) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
            ++node->cnt;
        }
        ++node->end;
    }
    int countWordsEqualTo(string s) {
        auto node = findNode(s);
        return node ? node->end : 0;
    }
    int countWordsStartingWith(string s) {
        auto node = findNode(s);
        return node ? node->cnt : 0;
    }
    void erase(string s) {
        auto node = &root;
        for (char c : s) {
            node = node->next[c - 'a'];
            --node->cnt;
        }
        --node->end;
    }
};
```