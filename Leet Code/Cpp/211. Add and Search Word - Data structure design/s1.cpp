class TrieNode {
public:
    TrieNode *next[26];
    int count = 0;
    TrieNode () {
        memset(next, 0, sizeof(TrieNode*) * 26);
    }
};

class WordDictionary {
private:
    TrieNode *root;
 
    void insert(string word) {
        TrieNode *node = root;
        for (char c : word) {
            if (!node->next[c - 'a']) {
                node->next[c - 'a'] = new TrieNode();
            }
            node = node->next[c - 'a'];
        }
        node->count++;
    }
    
    bool search(TrieNode *node, string word, int i) {
        if (!node) return false;
        while (i < word.size()) {
            char c = word[i];
            if (c == '.') {
                for (auto next : node->next) {
                    if (search(next, word, i + 1)) return true;
                }
                return false;
            }
            if (!node->next[c - 'a']) return false;
            node = node->next[c - 'a'];
            ++i;
        }
        return node->count;
    }
public:
    WordDictionary () {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(root, word, 0);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");