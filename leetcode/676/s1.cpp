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