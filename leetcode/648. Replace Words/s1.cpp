// OJ: https://leetcode.com/problems/replace-words/
// Author: github.com/lzl124631x
// Time: O(D + S) where D is size of all contents in dictionary, S is size of all contents in sentence
// Space: O(D)
class TrieNode {
public:
    TrieNode *next[26] = {};
    bool isWord = false;
};
class Trie {
private:
    TrieNode root;
public:
    void insert(string &s) {
        auto node = &root;
        for (char c : s) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->isWord = true;
    }
    string getWord(string &s) {
        auto node = &root;
        for (int i = 0; i < s.size(); ++i) {
            if (!node->next[s[i] - 'a']) return s;
            node = node->next[s[i] - 'a'];
            if (node->isWord) return s.substr(0, i + 1);
        }
        return s;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        istringstream ss(sentence);
        string word, ans;
        Trie trie;
        for (auto s : dict) trie.insert(s);
        while (ss >> word) ans += trie.getWord(word)+ " ";
        ans.pop_back();
        return ans;
    }
};