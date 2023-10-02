// OJ: https://leetcode.com/problems/uncommon-words-from-two-sentences/
// Author: github.com/lzl124631x
// Time: O(A+B)
// Space: O(A+B)
class Solution {
private:
    unordered_map<string, int> getCounts(string s) {
        istringstream ss(s);
        string word;
        unordered_map<string, int> m;
        while (ss >> word) m[word]++;
        return m;
    }
public:
    vector<string> uncommonFromSentences(string A, string B) {
        auto m = getCounts(A), n = getCounts(B);
        vector<string> ans;
        for (auto &p : m) {
            if (p.second == 1 && n.find(p.first) == n.end()) ans.push_back(p.first);
        }
        for (auto &p : n) {
            if (p.second == 1 && m.find(p.first) == m.end()) ans.push_back(p.first);
        }
        return ans;
    }
};