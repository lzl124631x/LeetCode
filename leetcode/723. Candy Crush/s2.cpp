// OJ: https://leetcode.com/problems/candy-crush/
// Author: github.com/lzl124631x
// Time: O((MN)^2)
// Space: O(1)
class Solution {
private:
    int M, N;
    int dirs[2][2] = {{ 1, 0 }, { 0, 1 }};
    int crushable(vector<vector<int>> &board, int i, int j) {
        if (!board[i][j]) return 0;
        int ans = 0, val = abs(board[i][j]);
        for (int k = 0; k < 2; ++k) {
            auto dir = dirs[k];
            int x = i, y = j, cnt = 1;
            do {
                x += dir[0];
                y += dir[1];
                if (x >= M || y >= N || abs(board[x][y]) != val) break;
                ++cnt;
            } while (cnt < 3);
            if (cnt >= 3) ans |= (1 << k);
        }
        return ans;
    }
    void mark(vector<vector<int>> &board, int i, int j, int c) {
        int val = abs(board[i][j]);
        board[i][j] = -val;
        for (int k = 0; k < 2; ++k) {
            if ((c & (1 << k)) == 0) continue;
            int x = i, y = j;
            auto dir = dirs[k];
            do {
                x += dir[0];
                y += dir[1];
                if (x >= M || y >= N || abs(board[x][y]) != val) break;
                board[x][y] = -val;
            } while (true);
        }
    }
    void drop(vector<vector<int>> &board) {
        for (int j = 0; j < N; ++j) {
            int k = M - 1;
            for (int i = M - 1; i >= 0; --i) {
                if (board[i][j] <= 0) continue;
                board[k--][j] = board[i][j];
            }
            while (k >= 0) board[k--][j] = 0;
        }
    }
    bool crush(vector<vector<int>> &board) {
        bool found = false;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int c = crushable(board, i, j);
                if (!c) continue;
                mark(board, i, j, c);
                found = true;
            }
        }
        if (!found) return false;
        drop(board);
        return true;
    }
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        M = board.size(), N = board[0].size();
        while (crush(board));
        return board;
    }
};