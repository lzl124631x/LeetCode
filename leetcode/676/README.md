# [676. Implement Magic Dictionary (Medium)](https://leetcode.com/problems/implement-magic-dictionary/)

<p>
Implement a magic directory with <code>buildDict</code>, and <code>search</code> methods.
</p>

<p>
For the method <code>buildDict</code>, you'll be given a list of non-repetitive words to build a dictionary.
</p>

<p>
For the method <code>search</code>, you'll be given a word, and judge whether if you modify <b>exactly</b> one character into <b>another</b> character in this word, the modified word is in the dictionary you just built.
</p>

<p><b>Example 1:</b><br>
</p><pre>Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>You may assume that all the inputs are consist of lowercase letters <code>a-z</code>.</li>
<li>For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.</li>
<li>Please remember to <b>RESET</b> your class variables declared in class MagicDictionary, as static/class variables are <b>persisted across multiple test cases</b>. Please see <a href="https://leetcode.com/faq/#different-output">here</a> for more details.</li>
</ol>
<p></p>

**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Trie](https://leetcode.com/tag/trie/)

## Solution 1. Trie

```cpp
// OJ: https://leetcode.com/problems/implement-magic-dictionary/
// Author: github.com/lzl124631x
// Time:
//   buildDict: O(W) where W is the size of all content in word.
//   search: O(W) since we only branch once in backtracking, it's not O(26^W)
// Space: O(W)
class TrieNode {
public:
    TrieNode *next[26] = {};
    bool isWord = false;
};
class Trie {
public:
    TrieNode root;
    void insert(string &word) {
        auto node = &root;
        for (char c : word) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->isWord = true;
    }
};
class MagicDictionary {
private:
    Trie trie;
    bool search(string &word, int index, int diff, TrieNode *node) {
        if (diff > 1) return false;
        if (index == word.size()) return node->isWord && diff == 1;
        for (int i = 0; i < 26; ++i) {
            if (!node->next[i]) continue;
            if (search(word, index + 1, diff + (word[index] - 'a' == i ? 0 : 1), node->next[i])) return true;
        }
        return false;
    }
public:
    void buildDict(vector<string> dict) {
        for (auto &word : dict) trie.insert(word);
    }
    bool search(string word) {
        return search(word, 0, 0, &trie.root);
    }
};
```