// OJ: https://leetcode.com/problems/is-subsequence/
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0, M = s.size(), N = t.size();
        for (; i < M && j < N; ++j) {
            if (s[i] == t[j]) ++i;
        }
        return i == M;
    }
};