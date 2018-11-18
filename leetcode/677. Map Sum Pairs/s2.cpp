// OJ: https://leetcode.com/problems/map-sum-pairs/
// Author: github.com/lzl124631x
// Time:
//     * insert: O(W) where W is word length
//     * sum: O(W)
// Space: O(NW)
class TrieNode {
public:
    unordered_map<char, TrieNode*> m;
    int count = 0;
};

class MapSum {
private:
    TrieNode root;
    unordered_map<string, int> m;
public:
    MapSum() {}
    
    void insert(string key, int val) {
        int delta = val - m[key];
        m[key] = val;
        TrieNode *node = &root;
        for (char c : key) {
            if (!node->m[c]) node->m[c] = new TrieNode();
            node = node->m[c];
            node->count += delta;
        }
    }
    
    int sum(string prefix) {
        TrieNode *node = &root;
        for (char c : prefix) {
            node = node->m[c];
            if (!node) return 0;
        }
        return node->count;
    }
};