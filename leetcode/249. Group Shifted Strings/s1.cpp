// OJ: https://leetcode.com/problems/group-shifted-strings/
// Author: github.com/lzl124631x
// Time: O(S) where S is size of all the contents in `strings`.
// Space: O(K) where K is the length of output array.
class Solution {
private:
    string getKey(string s) {
        if (s.empty()) return "";
        int d = s[0] - 'a';
        for (int i = 0; i < s.size(); ++i) s[i] = 'a' + (s[i] - 'a' - d + 26) % 26;
        return s;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        for (auto s : strings) m[getKey(s)].push_back(s);
        vector<vector<string>> ans;
        for (auto &p : m) ans.push_back(p.second);
        return ans;
    }
};