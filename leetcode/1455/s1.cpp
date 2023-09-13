// OJ: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(W)
class Solution {
public:
    int isPrefixOfWord(string s, string w) {
        istringstream ss(s);
        string word;
        for (int i = 1; ss >> word; ++i) {
            if (word.size() >= w.size() && word.substr(0, w.size()) == w) return i;
        }
        return -1;
    }
};