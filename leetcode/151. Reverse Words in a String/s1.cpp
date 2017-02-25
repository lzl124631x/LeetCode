class Solution {
public:
    void reverseWords(string &s) {
        int i = 0, j = 0;
        while (j < s.size()) {
            while (j < s.size() && s[j] == ' ') ++j;
            if (i != 0 && j != s.size()) s[i++] = ' ';
            while (j < s.size() && s[j] != ' ') s[i++] = s[j++];
        }
        s.erase(i);
        i = j = 0;
        while (i < s.size()) {
            j = i;
            while (j < s.size() && s[j] != ' ') ++j;
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        reverse(s.begin(), s.end());
    }
};