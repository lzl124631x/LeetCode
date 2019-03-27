// OJ: https://leetcode.com/problems/palindromic-substrings/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int N = s.size(), ans = N;
        for (int i = 1; i + 1 < N; ++i) {
            for (int j = 1; i - j >= 0 && i + j < N && s[i - j] == s[i + j]; ++j, ++ans);
        }
        for (int i = 0; i + 1 < N; ++i) {
            for (int j = 0; i - j >= 0 && i + 1 + j < N && s[i - j] == s[i + 1 + j]; ++j, ++ans);
        }
        return ans;
    }
};