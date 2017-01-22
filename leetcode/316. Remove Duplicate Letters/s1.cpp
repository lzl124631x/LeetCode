class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return s;
        unordered_map<char, int> cnt;
        for (char c : s) cnt[c]++;
        int index = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] < s[index]) index = i;
            if (--cnt[s[i]] == 0) break;
        }
        string r = s.substr(index + 1);
        r.erase(remove(r.begin(), r.end(), s[index]), r.end());
        return s[index] + removeDuplicateLetters(r);
    }
};