class TrieNode {
public:
    TrieNode *children[26];
    int count = 0;
    // Initialize your data structure here.
    TrieNode() {
        memset(children, 0, sizeof(TrieNode*)*26);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->count++;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *node = searchToNode(word);
        return node && node->count;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return searchToNode(prefix);
    }

private:
    TrieNode* root;
    TrieNode* searchToNode(string prefix) {
        TrieNode *node = root;
        for (char c : prefix) {
            if (!node->children[c - 'a']) return NULL;
            node = node->children[c - 'a'];
        }
        return node;
    }
};