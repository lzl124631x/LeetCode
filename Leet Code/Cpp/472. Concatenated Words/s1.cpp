// Have to use statically allocated memory to avoid MLE in C++.
// https://discuss.leetcode.com/topic/72754/trie-dfs-method-using-static-trie-node-to-avoid-getting-mle-runtime-about-300ms
class TrieNode {
public:
    bool end = false;
    TrieNode *next[26];
    TrieNode () {
        memset(next, 0, sizeof(TrieNode*) * 26);
    }
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
            if (i != word.size() - 1 && node->end) {
                if (check(word, i + 1)) return true;
            }
        }
        return node->end && start;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        memset(pool, 0, sizeof(pool));
        for (string s : words) {
            insert(s);
        }
        vector<string> v;
        for (string s : words) {
            if (s.empty()) continue;
            if (check(s, 0)) v.push_back(s);
        }
        return v;
    }
};