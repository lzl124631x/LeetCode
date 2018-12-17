// OJ: https://leetcode.com/problems/concatenated-words/
// Author: github.com/lzl124631x
// Time: O(N*2^W) where N is length of words array, W is max word length. 
//       2^W is because for each letter we may start or not start a new check there.
// Space: O(C) where C is the length sum of words.
// Ref: https://discuss.leetcode.com/topic/72754/trie-dfs-method-using-static-trie-node-to-avoid-getting-mle-runtime-about-300ms
// NOTE: Use statically allocated memory to avoid MLE in C++.
class TrieNode {
public:
    bool end = false;
    TrieNode *next[26];
};

TrieNode pool[60000];

class Solution {
private:
    TrieNode *root = pool;
    int cnt = 1;
    void insert(string &word) {
        TrieNode *node = root;
        for (char c : word) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = &pool[cnt++];
            node = node->next[c - 'a'];
        }
        node->end = true;
    }
    
    bool check(string &word, int start) {
        if (start == word.size()) return true;
        TrieNode *node = root;
        for (int i = start; i < word.size(); ++i) {
            node = node->next[word[i] - 'a'];
            if (!node) return false;
            if (i != word.size() - 1 && node->end && check(word, i + 1)) return true;
        }
        return node->end && start;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        memset(pool, 0, sizeof(pool)); // reset pool.
        for (string s : words) insert(s);
        vector<string> ans;
        for (string s : words) {
            if (s.empty()) continue;
            if (check(s, 0)) ans.push_back(s);
        }
        return ans;
    }
};