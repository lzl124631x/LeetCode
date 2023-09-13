// OJ: https://leetcode.com/problems/valid-word-abbreviation/
// Author: github.com/lzl124631x
// Time: O(M+N)
// Space: O(1)
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0, M = word.size(), N = abbr.size();
        while (i < M && j < N) {
            if (isalpha(abbr[j])) {
                if (word[i] != abbr[j]) return false;
                ++i;
                ++j;
                continue;
            }
            int len = 0;
            while (j < N && isdigit(abbr[j])) {
                len = 10 * len + (abbr[j++] - '0');
                if (!len) return false;
            }
            i += len;
        }
        return i == M && j == N;
    }
};