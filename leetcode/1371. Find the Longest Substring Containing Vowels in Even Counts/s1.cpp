// OJ: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findTheLongestSubstring(string s) {
        string v = "aeiou";
        int N = s.size(), cnt[26] = {0}, ans = 0;
        unordered_map<unsigned, int> m{{0, -1}};
        for (int i = 0; i < N; ++i) {
            cnt[s[i] - 'a']++;
            unsigned state = 0;
            for (int j = 0; j < v.size(); ++j) {
                if (cnt[v[j] - 'a'] % 2) state |= 1 << j;
            }
            if (m.count(state)) ans = max(ans, i - m[state]);
            else m[state] = i;
        }
        return ans;
    }
};