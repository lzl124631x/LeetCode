// OJ: https://leetcode.com/problems/find-common-characters/
// Author: github.com/lzl124631x
// Time: O(C) where C is the size of all the contents in A
// Space: O(1)
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> overlap(26, INT_MAX);
        for (string s : A) {
            vector<int> cnt(26, 0);
            for (char c : s) cnt[c - 'a']++;
            for (int i = 0; i < 26; ++i) overlap[i] = min(overlap[i], cnt[i]);
        }
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            while (overlap[i]--) ans.push_back(string(1, 'a' + i));
        }
        return ans;
    }
};