class Solution {
private:
    int M, N;
    vector<vector<int>> memo;
    int isMatch(string s, int i, string p, int j) {
        if (memo[i][j] != 0) return memo[i][j];
        while (i < M && j < N) {
            if (j + 1 >= N || p[j + 1] != '*') {
                if (p[j] != '.' && s[i] != p[j]) {
                    return memo[i][j] = -1;
                }
                ++i;
                ++j;
            } else {
                char c = p[j];
                j += 2;
                do {
                    memo[i][j] = isMatch(s, i, p, j);
                    if (memo[i][j] == 1) return 1;
                    if (c == '.' || s[i] == c) ++i;
                    else {
                        return memo[i][j] = -1;
                    }
                } while (i < M);
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
        memo = vector<vector<int>>(M + 1, vector<int>(N + 1, 0));
        return isMatch(s, 0, p, 0) == 1;
    }
};