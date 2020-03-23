// OJ: https://leetcode.com/problems/interleaving-string/
// Author: github.com/lzl124631x
// Time: O(2^(M+N))
// Space: O(MN)
class Solution {
    int M, N;
    vector<vector<int>> m;
    int dfs(string &a, string &b, string &c, int i, int j) {
        if (i == M && j == N) return 1;
        if (m[i][j] != 0) return m[i][j];
        int val = -1;
        if (i < M && a[i] == c[i + j]) val = dfs(a, b, c, i + 1, j);
        if (val != 1 && j < N && b[j] == c[i + j]) val = dfs(a, b, c, i, j + 1);
        return m[i][j] = val;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        M = s1.size(), N = s2.size();
        if (M + N != s3.size()) return false;
        m.assign(M + 1, vector<int>(N + 1));
        return dfs(s1, s2, s3, 0, 0) == 1;
    }
};