// OJ: https://leetcode.com/problems/regular-expression-matching/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
    int M, N;
    vector<vector<int>> m;
    int dfs(string &s, string &p, int i, int j) {
        if (m[i][j] != 0) return m[i][j];
        while (i < M && j < N) {
            if (j + 1 < N && p[j + 1] == '*') {
                do {
                    m[i][j] = dfs(s, p, i, j + 2);
                    if (m[i][j] == 1) return 1;
                    if (p[j] == '.' || s[i] == p[j]) ++i;
                    else return m[i][j] = -1;
                } while (i < M);
            } else {
                if (p[j] != '.' && s[i] != p[j]) return m[i][j] = -1;
                ++i, ++j;
            }
        }
        if (i == M) {
            while (j + 1 < N && p[j + 1] == '*') j += 2;
        }
        return i == M && j == N ? 1 : -1;
    }
public:
    bool isMatch(string s, string p) {
        M = s.size(), N = p.size();
        m.assign(M + 1, vector<int>(N + 1));
        return dfs(s, p, 0, 0) == 1;
    }
};