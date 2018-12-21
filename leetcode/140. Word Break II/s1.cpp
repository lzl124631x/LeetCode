// OJ: https://leetcode.com/problems/word-break-ii
// Author: github.com/lzl124631x
// Time: O(sum{i * (i - 1) / 2 | i in [1, S]}) where S is the length of s.
// Space: O(C) where C is the length sum of wordDict
class Solution {
private:
    int maxLen = 0;
    vector<int> states;
    vector<string> ans;
    unordered_set<string> dict;
    bool dfs(string &s, int start, string tmp){
        if (start == s.size()) {
            ans.push_back(tmp);
            return true;
        }
        if (states[start] == 2) return false;
        states[start] = 2;
        for(int end = start + 1; end <= s.size() && end - start <= maxLen; ++end){
            string sub = s.substr(start, end - start);
            if (dict.find(sub) == dict.end()) continue;
            if (dfs(s, end, tmp.size() ? tmp + " " + sub : sub) == 1) states[start] = 1;
        }
        return states[start] == 1;
    }
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        for (auto &s : wordDict) maxLen = max(maxLen, (int)s.size());
        states = vector<int>(s.size(), 0); // 0 unvisited; 1 can research the end; 2 can not.
        dfs(s, 0, "");
        return ans;
    }
};