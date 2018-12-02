// OJ: https://leetcode.com/problems/unique-letter-string
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int uniqueLetterString(string S) {
        int mod = 1e9 + 7, N = S.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            int cnts[26] = {0}, prev = 0, two = 0;
            for (int j = i; j < N && two != 26; ++j) {
                cnts[S[j] - 'A']++;
                int cur = prev;
                if (cnts[S[j] - 'A'] == 1) ++cur;
                else if (cnts[S[j] - 'A'] == 2) {
                    --cur;
                    two++;
                }
                ans = (ans + cur) % mod;
                prev = cur;
            }
        }
        return ans;
    }
};