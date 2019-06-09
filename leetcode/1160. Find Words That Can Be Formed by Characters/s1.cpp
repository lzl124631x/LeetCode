// OJ: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
// Author: github.com/lzl124631x
// Time: O(N) where N is the length of all the contents in `words` and `chars`
// Space: O(1)
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt[26] = {0}, ans = 0;
        for (char c : chars) cnt[c - 'a']++;
        for (auto w : words) {
            int c[26] = {0};
            bool good = true;
            for (char ch : w) {
                if (++c[ch - 'a'] <= cnt[ch - 'a']) continue;
                good = false;
                break;
            }
            if (good) ans += w.size();
        }
        return ans;
    }
};