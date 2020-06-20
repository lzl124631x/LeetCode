// OJ: https://leetcode.com/problems/word-break-ii
// Author: github.com/lzl124631x
// Time: O(2^M) where M is the max length of string in wordDict.
// Space: O(C) where C is the length sum of wordDict
class Solution {
    int maxLen = 0;
    unordered_set<string> ws;
    vector<int> m;
    vector<string> ans;
    bool dfs(string &s, int i, string tmp) {
        if (i == s.size()) {
            ans.push_back(tmp);
            return true; 
        }
        if (m[i] == 0) return m[i];
        m[i] = 0;
        for (int j = min((int)s.size(), i + maxLen); j > i; --j) {
            auto sub = s.substr(i, j - i);
            if (ws.count(sub) && dfs(s, j, tmp.size() ? tmp + " " + sub : sub)) m[i] = 1;
        }
        return m[i];
    }
public:
    vector<string> wordBreak(string s, vector<string>& dict) {
        ws = { dict.begin(), dict.end() };
        for (auto &w : dict) maxLen = max(maxLen, (int)w.size());
        m.assign(s.size(), -1); // -1 = unvisited, 0 = can not reach end, 1 = can reach end.
        dfs(s, 0, "");
        return ans;
    }
};