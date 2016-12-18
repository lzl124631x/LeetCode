class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int cnt = 0;
        for (int i = 0; i < 26; ++i) {
            int maxLen = 0;
            for (int j = 0; j < p.size(); ++j) {
                if (p[j] == 'a' + i) {
                    int start = j;
                    while (j + 1 < p.size() && (p[j + 1] - 'a') == (p[j] - 'a' + 1) % 26) ++j;
                    maxLen = max(maxLen, j - start + 1);
                }
            }
            cnt += maxLen;
        }
        return cnt;
    }
};