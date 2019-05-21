// OJ: https://leetcode.com/problems/expressive-words/
// Author: github.com/lzl124631x
// Time: O(SW) where S is size of string `S`, W is count of `words`
// Space: O(S)
class Solution {
private:
    vector<pair<char, int>> s;
    vector<pair<char, int>> get(string &s) {
        vector<pair<char, int>> v;
        for (int i = 0, N = s.size(); i < N;) {
            int start = i;
            while (i < N && s[i] == s[start]) ++i;
            v.emplace_back(s[start], i - start);
        }
        return v;
    }
    bool isExpressiveWord(string &word) {
        auto w = get(word);
        if (s.size() != w.size()) return false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i].first != w[i].first
               || !((s[i].second >= 3 && w[i].second <= s[i].second) || (s[i].second < 3 && w[i].second == s[i].second))) return false;
        }
        return true;
    }
public:
    int expressiveWords(string S, vector<string>& words) {
        s = get(S);
        int ans = 0;
        for (auto &word : words) {
            if (isExpressiveWord(word)) ++ans;
        }
        return ans;
    }
};