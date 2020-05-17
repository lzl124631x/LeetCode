// OJ: https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int target[26] = {}, cnt[26] = {};
        for (char c : p) target[c - 'a']++;
        vector<int> ans;
        for (int i = 0; i < s.size(); ++i) {
            if (i >= p.size()) cnt[s[i - p.size()] - 'a']--;
            cnt[s[i] - 'a']++;
            int j = 0;
            for (; j < 26; ++j) {
                if (cnt[j] != target[j]) break;
            }
            if (j == 26) ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};