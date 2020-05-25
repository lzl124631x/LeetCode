// OJ: https://leetcode.com/problems/sort-characters-by-frequency/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string frequencySort(string s) {
        vector<char> v;
        int cnt[256] = {};
        for (char c : s) {
            if (cnt[c]++ == 0) v.push_back(c);
        }
        sort(v.begin(), v.end(), [&](char a, char b) { return cnt[a] > cnt[b]; });
        string ans;
        for (char c : v) {
            for (int i = 0; i < cnt[c]; ++i) ans.push_back(c);
        }
        return ans;
    }
};