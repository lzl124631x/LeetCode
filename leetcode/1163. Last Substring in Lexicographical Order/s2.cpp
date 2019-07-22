// OJ: https://leetcode.com/problems/last-substring-in-lexicographical-order/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
// Ref: https://leetcode.com/problems/last-substring-in-lexicographical-order/discuss/360957/C%2B%2B-Brute-Force
class Solution {
public:
    string lastSubstring(string s) {
        int start = 0, N = s.size(), j;
        for (int i = 1; i < N; ++i) {
            for (j = 0; i + j < N; ++j) {
                if (s[start + j] == s[i + j]) continue;
                start = s[start + j] > s[i + j] ? start : i;
                break;
            }
            if (i + j == N) break;
        }
        return s.substr(start);
    }
};