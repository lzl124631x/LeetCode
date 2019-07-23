// OJ: https://leetcode.com/problems/find-and-replace-pattern/
// Author: github.com/lzl124631x
// Time: O(CW) where C is count of words and W is word length
// Space: O(W)
class Solution {
private:
    bool match(string &word, string &pattern) {
        unordered_map<char, char> m;
        unordered_set<char> used;
        for (int i = 0; i < word.size(); ++i) {
            if (m.find(word[i]) == m.end()) {
                if (used.find(pattern[i]) != used.end()) return false;
                m[word[i]] = pattern[i];
                used.insert(pattern[i]);                                            
            } else if (m[word[i]] != pattern[i]) return false;
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (auto word : words) {
            if (match(word, pattern)) ans.push_back(word);
        }
        return ans;
    }
};