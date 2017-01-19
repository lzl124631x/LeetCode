class Solution {
public:
    int longestPalindrome(string s) {
        int C[52] = {0};
        for (char c: s) {
            if (c >= 'a' && c <= 'z') C[c - 'a']++;
            else C[c - 'A' + 26]++;
        }
        int ret = 0;
        bool usedSingle = false;
        for (int i = 0; i < 52; ++i) {
            if (C[i] % 2) {
                ret += C[i] / 2 * 2;
                if (!usedSingle) {
                    usedSingle = true;
                    ret++;
                }
            } else {
                ret += C[i];
            }
        }
        return ret;
    }
};