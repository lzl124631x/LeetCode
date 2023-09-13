// OJ: https://leetcode.com/problems/brace-expansion-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    int i = 0;
    vector<string> handleList(string &s) {
        ++i; // {
        vector<string> ans;
        while (s[i] != '}') {
            auto st = dfs(s);
            for (auto &a : st)
                ans.push_back(a);
            if (s[i] == ',') ++i;
        }
        ++i; // }
        return ans;
    }
    vector<string> dfs(string &s) {
        vector<string> ans{ "" };
        while (i < s.size() && s[i] != ',' && s[i] != '}') {
            if (s[i] != '{') {
                for (auto &a : ans) a += s[i]; 
                ++i;
            } else {
                auto list = handleList(s);
                vector<string> tmp;
                for (auto &a : ans) 
                    for (auto &b : list)
                        tmp.push_back(a + b); 
                swap(tmp, ans);
            }
        }
        return ans;
    }
public:
    vector<string> braceExpansionII(string s) {
        auto st = dfs(s);
        vector<string> ans(st.begin(), st.end());
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};