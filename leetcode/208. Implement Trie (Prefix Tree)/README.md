# [208. Implement Trie (Prefix Tree) (Medium)](https://leetcode.com/problems/implement-trie-prefix-tree/)

<p>Implement a trie with <code>insert</code>, <code>search</code>, and <code>startsWith</code> methods.</p>

<p><b>Example:</b></p>

<pre>Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
</pre>

<p><b>Note:</b></p>

<ul>
	<li>You may assume that all inputs are consist of lowercase letters <code>a-z</code>.</li>
	<li>All inputs are guaranteed to be non-empty strings.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Twitter](https://leetcode.com/company/twitter)

**Related Topics**:  
[Design](https://leetcode.com/tag/design/), [Trie](https://leetcode.com/tag/trie/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/implement-trie-prefix-tree/
// Author: github.com/lzl124631x
// Time: O(W) for insert/search/startsWith
// Space:
//   insert: O(W)
//   search/startsWith: O(1)
class TrieNode {
public:
    TrieNode *next[26] = {};
    int count = 0;
};
class Trie {
private:
    TrieNode root;
    TrieNode* searchToNode(string &prefix) {
        auto node = &root;
        for (char c : prefix) {
            if (!node->next[c - 'a']) return NULL;
            node = node->next[c - 'a'];
        }
        return node;
    }
public:
    void insert(string word) {
        auto node = &root;
        for (char c : word) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->count++;
    }
    bool search(string word) {
        auto node = searchToNode(word);
        return node && node->count;
    }
    bool startsWith(string prefix) {
        return searchToNode(prefix);
    }
};
```