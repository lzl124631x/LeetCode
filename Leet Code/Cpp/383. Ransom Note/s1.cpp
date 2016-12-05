class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int C[26] = {0};
        for (char c : magazine) {
            C[c - 'a']++;
        }
        for (char c : ransomNote) {
            C[c - 'a']--;
            if (C[c - 'a'] < 0) return false;
        }
        return true;
    }
};