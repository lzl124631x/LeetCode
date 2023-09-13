// OJ: https://leetcode.com/problems/regular-expression-matching/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
    int M, N;
    bool dfs(string &s, string &p, int i, int j) {
        while (i < M && j < N) {
            if (j + 1 < N && p[j + 1] == '*') {
                if (dfs(s, p, i, j + 2)) return true;
                while (i < M && (p[j] == '.' || s[i] == p[j])) {
                    if (dfs(s, p, ++i, j + 2)) return true;
                }
                return false;
            } else {
                if (p[j] != '.' && s[i] != p[j]) return false;
                ++i, ++j;
            }
        }
        if (i == M) {
            while (j + 1 < N && p[j + 1] == '*') j += 2;
        }
        return i == M && j == N;
    }
public:
    bool isMatch(string s, string p) {
        M = s.size(), N = p.size();
        return dfs(s, p, 0, 0);
    }
};