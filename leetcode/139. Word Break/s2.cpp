// OJ: https://leetcode.com/problems/word-break/
// Author: github.com/lzl124631x
// Time: O(S^3)
// Space: O(S + W)
class Solution {
    unordered_set<string> ws;
    vector<int> m;
    bool dp(string &s, int i) {
        if (i == s.size()) return true;
        if (m[i] != -1) return m[i];
        m[i] = 0;
        for (int j = s.size(); j > i && m[i] != 1; --j) {
            if (!dp(s, j) || ws.count(s.substr(i, j - i)) == 0) continue;
            m[i] = 1;
        }
        return m[i];
    }
public:
    bool wordBreak(string s, vector<string>& dist) {
        ws = { dist.begin(), dist.end() };
        m.assign(s.size(), -1);
        return dp(s, 0);
    }
};