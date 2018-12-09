// OJ: https://leetcode.com/problems/verifying-an-alien-dictionary/
// Author: github.com/lzl124631x
// Time: O(C) where C is the total content of `words`
// Space: O(1)
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, char> m;
        for (int i = 0; i < order.size(); ++i) {
            m[order[i]] = 'a' + i;
        }
        for (string &w : words) {
            for (char &c : w) {
                c = m[c];
            }
        }
        for (int i = 1; i < words.size(); ++i) {
            if (words[i] < words[i - 1]) return false;
        }
        return true;
    }
};