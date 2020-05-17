// OJ: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;
        for (char c : s) {
            if (st.empty() || st.back().first != c) st.emplace_back(c, 1);
            else if (++st.back().second == k) st.pop_back();
        }
        string ans;
        for (int i = 0; i < st.size(); ++i) {
            for (int j = 0; j < st[i].second; ++j) ans += st[i].first;
        }
        return ans;
    }
};