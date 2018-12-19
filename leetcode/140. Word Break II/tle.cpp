class Solution {
private:
    vector<string> ans;
    unordered_set<string> dict;
    void dfs(string &s, int start, string tmp) {
        if (start == s.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            string sub = s.substr(start, i - start + 1);
            if (dict.find(sub) == dict.end()) continue;
            string next = tmp;
            if (next.size()) next.push_back(' ');
            next += sub;
            dfs(s, i + 1, next);
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        dfs(s, 0, "");
        return ans;
    }
};