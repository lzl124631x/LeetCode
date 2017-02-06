class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> cnt;
        for (char c : s) cnt[c]++;
        int i = 0, j = 0, ans = 0;
        while (i < s.size()) {
            unordered_map<char, int> added;
            while (i < s.size() && cnt[s[i]] < k) ++i;
            j = i;
            while (j < s.size() && cnt[s[j]] + added[s[j]] >= k) {
                added[s[j]]++;
                cnt[s[j]]--;
                ++j;
            }
            bool valid = true;
            for (char c = 'a'; c <= 'z' && valid; ++c) {
                if (added[c] != 0 && added[c] < k) valid = false;
            }
            if (valid) ans = max(ans, j - i);
            else ans = max(ans, longestSubstring(s.substr(i, j - i), k));
            i = j;
        }
        return ans;
    }
};