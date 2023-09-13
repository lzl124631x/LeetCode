// OJ: https://leetcode.com/problems/longest-word-in-dictionary/
// Author: github.com/lzl124631x
// Time: O(NW)
// Space: O(Nw)
class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> s;
        for (auto &w : words) s.insert(w);
        string ans;
        for (auto &w : words) {
            if (w.size() < ans.size()) continue;
            auto x = w;
            do {
                x.pop_back();
            } while (x.size() && s.find(x) != s.end());
            if (x.size()) continue;
            if (w.size() > ans.size()
               || (w.size() == ans.size() && w < ans)) ans = w;
        }
        return ans;
    }
};