// OJ: https://leetcode.com/contest/weekly-contest-190/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(1)
class Solution {
public:
    int isPrefixOfWord(string s, string w) {
        istringstream ss(s);
        string word;
        for (int i = 1; ss >> word; ++i) {
            string_view wv(word);
            if (word.size() >= w.size() && wv.substr(0, w.size()) == w) return i;
        }
        return -1;
    }
};