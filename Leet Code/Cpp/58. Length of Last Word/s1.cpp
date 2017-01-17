class Solution {
public:
    int lengthOfLastWord(string s) {
        int begin = 0, end = 0, i = 0;
        while (i < s.size() && s[i] == ' ') ++i;
        while (i < s.size()) {
            begin = i;
            while (i < s.size() && s[i] != ' ') ++i;
            end = i;
            while (i < s.size() && s[i] == ' ') ++i;
        }
        return end - begin;
    }
};