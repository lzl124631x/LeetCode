class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> memo;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        memo = vector<vector<string>>(s.size() + 1);
        memo[0].push_back("");
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                string sub = s.substr(j, i - j);
                if (dict.find(sub) == dict.end()) continue;
                for (auto &prefix : memo[j]) memo[i].push_back((prefix.size() ? (prefix + " ") : "") + sub);
            }
        }
        return memo[s.size()];
    }
};