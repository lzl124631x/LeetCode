// OJ: https://leetcode.com/problems/knight-probability-in-chessboard/
// Author: github.com/lzl124631x
// Time: O(KN^2)
// Space: O(N^2)
class Solution {
private:
    int dirs[8][2] = {{-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}};
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> m(N, vector<double>(N, 1));
        while (K-- > 0) {
            vector<vector<double>> next(N, vector<double>(N, 0));
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    for (auto &dir : dirs) {
                        int x = i + dir[0], y = j + dir[1];
                        if (x < 0 || x >= N || y < 0 || y >= N) continue;
                        next[i][j] += m[x][y];
                    }
                    next[i][j] /= 8;
                }
            }
            m = next;
        }
        return m[r][c];
    }
};