// https://discuss.leetcode.com/topic/63207/java-o-n-solution-using-trie
class TrieNode {
public:
    TrieNode *next[2];
    TrieNode () {
        memset(next, 0, sizeof (TrieNode*) * 2);
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *root = new TrieNode();
        for (int n : nums) {
            TrieNode *node = root;
            for (int i = 31; i >= 0; --i) {
                int bit = (n >> i) & 1;
                if (!node->next[bit]) node->next[bit] = new TrieNode();
                node = node->next[bit];
            }
        }
        int maxVal = 0;
        for (int n : nums) {
            TrieNode *node = root;
            int val = 0;
            for (int i = 31; i >= 0; --i) {
                int bit = (n >> i) & 1;
                if (node->next[1 ^ bit]) {
                    val += (1 << i);
                    node = node->next[1 ^ bit];
                } else {
                    node = node->next[bit];
                }
            }
            maxVal = max(maxVal, val);
        }
        return maxVal;
    }
};