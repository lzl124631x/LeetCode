// OJ: https://leetcode.com/problems/concatenated-words/
// Author: github.com/lzl124631x
// Time: O(N*2^W) where N is length of words array, W is max word length. 
//       2^W is because for each letter we may start or not start a new check there.
// Space: O(C) where C is the length sum of words.
// NOTE: use `unordered_map` instead of `TrieNode*[26]` to save space.
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};

class Trie {
private:
    TrieNode root;
    bool dfs(string &word, int start, int cnt) {
        if (start == word.size()) return cnt > 1;
        TrieNode *node = &root;
        for (int i = start; i < word.size(); ++i) {
            if (node->children.find(word[i]) == node->children.end()) return false;
            TrieNode *next = node->children[word[i]];
            if (next->isWord && dfs(word, i + 1, cnt + 1)) return true;
            node = next;
        }
        return false;
    }
public:
    void insert(string &word) {
        TrieNode *node = &root;
        for (char c : word) {
            if (!node->children[c]) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isWord = true;
    }
    
    bool isConcatednatedWord(string &word) {
        return dfs(word, 0, 0);
    }
};
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie trie;
        for (auto word : words) trie.insert(word);
        vector<string> ans;
        for (auto word : words) {
            if (trie.isConcatednatedWord(word)) ans.push_back(word);
        }
        return ans;
    }
};