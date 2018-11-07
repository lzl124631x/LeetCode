# [745. Prefix and Suffix Search (Hard)](https://leetcode.com/problems/prefix-and-suffix-search/)

Given many `words`, `words[i]` has weight `i`.

Design a class `WordFilter` that supports one function, `WordFilter.f(String prefix, String suffix)`. It will return the word with given `prefix` and `suffix` with maximum weight. If no word exists, return -1.

**Examples:**  

**Input:**  
WordFilter(\["apple"\])  
WordFilter.f("a", "e") // returns 0  
WordFilter.f("b", "") // returns -1

**Note:**  

1.  `words` has length in range `[1, 15000]`.
2.  For each test case, up to `words.length` queries `WordFilter.f` may be made.
3.  `words[i]` has length in range `[1, 10]`.
4.  `prefix, suffix` have lengths in range `[0, 10]`.
5.  `words[i]` and `prefix, suffix` queries consist of lowercase letters only.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/prefix-and-suffix-search/
// Author: github.com/lzl124631x
// Time:
//   * WordFilter: O(WL)
//   * f: O(L + W)
// Space: O(WL) where W is `words` length and L is max word length.
class TrieNode {
public:
    TrieNode *next[26];
    vector<int> indexes;
    TrieNode () {
        memset(next, 0, sizeof(TrieNode*) * 26);
    }
};

class WordFilter {
private:
    TrieNode *pTrie = new TrieNode();
    TrieNode *sTrie = new TrieNode();
    void addWordToTrie(string &word, int i, TrieNode *node) {
        node->indexes.push_back(i);
        for (char c : word) {
            int index = c - 'a';
            if (!node->next[index]) node->next[index] = new TrieNode();
            node = node->next[index];
            node->indexes.push_back(i);
        }
    }
    
    void addWord(string &word, int i) {
        addWordToTrie(word, i, pTrie);
        reverse(word.begin(), word.end());
        addWordToTrie(word, i, sTrie);
    }
    
    vector<int> search(TrieNode *node, string &prefix) {
        for (char c : prefix) {
            int index = c - 'a';
            node = node->next[index];
            if (!node) return {};
        }
        return node->indexes;
    }
public:
    WordFilter(vector<string> words) {
        for (int i = 0; i < words.size(); ++i) addWord(words[i], i);
    }
    
    int f(string prefix, string suffix) {
        auto p = search(pTrie, prefix);
        reverse(suffix.begin(), suffix.end());
        auto s = search(sTrie, suffix);
        int i = p.size() - 1;
        int j = s.size() - 1;
        while (i >= 0 && j >= 0 && p[i] != s[j]) {
            if (p[i] > s[j]) --i;
            else --j;
        }
        return (i < 0 || j < 0) ? -1 : p[i];
    }
};
```