// OJ: https://leetcode.com/problems/group-anagrams/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& A) {
        unordered_map<string, int> m;
        vector<vector<string>> ans;
        for (auto &s : A) {
            auto p = s;
            sort(p.begin(), p.end());
            if (!m.count(p)) {
                m[p] = ans.size();
                ans.push_back({});
            }
            ans[m[p]].push_back(s);
        }
        return ans;
    }
};