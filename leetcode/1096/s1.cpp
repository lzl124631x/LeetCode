// OJ: https://leetcode.com/problems/brace-expansion-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    int i = 0, N;
    unordered_set<string> handleList(string &s) {
        ++i; // {
        unordered_set<string> ans;
        while (s[i] != '}') {
            auto st = dfs(s);
            for (auto &a : st)
                ans.insert(a);
            if (s[i] == ',') ++i;
        }
        ++i; // }
        return ans;
    }
    unordered_set<string> dfs(string &s) {
        unordered_set<string> ans{ "" };
        while (i < N && s[i] != ',' && s[i] != '}') {
            unordered_set<string> tmp;
            if (s[i] != '{') {
                string str;
                while (i < N && isalpha(s[i])) str += s[i++];
                for (auto &a : ans) tmp.insert(a + str); 
            } else {
                auto st = handleList(s);
                for (auto &a : ans) 
                    for (auto &b : st)
                        tmp.insert(a + b); 
            }
            swap(tmp, ans);
        }
        return ans;
    }
public:
    vector<string> braceExpansionII(string s) {
        N = s.size();
        auto st = dfs(s);
        vector<string> ans(st.begin(), st.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};