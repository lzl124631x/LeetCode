// https://discuss.leetcode.com/topic/39585/o-n-k-2-java-solution-with-trie-structure-n-total-number-of-words-k-average-length-of-each-word/2

class TrieNode {
public:
    TrieNode *next[26];
    int index = -1;
    vector<int> palindromeIndexes;
    TrieNode() {
        memset(next, 0, sizeof(next));
    }
};
class Solution {
private:
    TrieNode *root = new TrieNode();
    
    void insert(string &word, int index) {
        TrieNode *node = root;
        for (int i = word.size() - 1; i >= 0; --i) {
            if (isPalindrome(word.substr(0, i + 1))) node->palindromeIndexes.push_back(index);
            char c = word[i];
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->index = index;
        node->palindromeIndexes.push_back(index);
    }
    vector<vector<int>> v;
    
    bool isPalindrome (string word) {
        int i = 0, j = word.size() - 1;
        while (i < j && word[i] == word[j]) ++i, --j;
        return i >= j;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            insert(words[i], i);
        }
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            TrieNode *node = root;
            for (int j = 0; j < word.size() && node; ++j) {
                char c = word[j];
                if (node->index != -1 && node->index != i && isPalindrome(word.substr(j, word.size() - j))) {
                    v.push_back({ i, node->index });
                }
                node = node->next[c - 'a'];
            }
            if (node) {
                for (int index : node->palindromeIndexes) {
                    if (i == index) continue;
                    v.push_back({ i, index });
                }
            }
        }
        return v;
    }
};