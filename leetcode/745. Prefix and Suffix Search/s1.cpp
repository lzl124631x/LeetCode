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