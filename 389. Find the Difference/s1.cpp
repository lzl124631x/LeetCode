class Solution {
public:
    char findTheDifference(string s, string t) {
        int c[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            c[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); ++i) {
            c[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (c[i]) return i + 'a';
        }
        return ' ';
    }
};