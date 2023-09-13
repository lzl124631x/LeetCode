// OJ: https://leetcode.com/problems/last-substring-in-lexicographical-order/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    string lastSubstring(string s) {
        int start = 0, N = s.size();
        for (int i = 1; i < N; ++i) {
            if (s[i] == s[start] && s[i - 1] == s[start]) continue;
            for (int j = 0; i + j < N; ++j) {
                if (s[start + j] == s[i + j]) continue;
                start = s[start + j] > s[i + j] ? start : i;
                break;
            }
        }
        return s.substr(start);
    }
};