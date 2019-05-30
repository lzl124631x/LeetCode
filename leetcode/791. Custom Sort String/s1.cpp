// OJ: https://leetcode.com/problems/custom-sort-string/
// Author: github.com/lzl124631x
// Time: O(TlogT)
// Space: O(1)
class Solution {
public:
    string customSortString(string S, string T) {
        int m[26] = { 0 };
        for (int i = 0; i < S.size(); ++i) m[S[i] - 'a'] = i;
        sort(T.begin(), T.end(), [&](const char a, const char b) {
            return m[a - 'a'] < m[b - 'a'];
        });
        return T;
    }
};