class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto j = t.begin();
        for (auto i = s.begin(); i != s.end(); ++i) {
            while (j != t.end() && *i != *j) ++j;
            if (j == t.end()) return false;
            else ++j;
        }
        return true;
    }
};