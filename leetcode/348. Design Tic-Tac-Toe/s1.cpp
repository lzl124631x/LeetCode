// OJ: https://leetcode.com/problems/design-tic-tac-toe/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N^2)
class TicTacToe {
private:
    vector<vector<int>> board;
    int n;
    int status(int row, int col) {
        int p = board[row][col];
        bool win = true;
        for (int i = 0; i < n && win; ++i) {
            if (board[row][i] != p) win = false;
        }
        if (win) return p;
        win = true;
        for (int i = 0; i < n && win; ++i) {
            if (board[i][col] != p) win = false;
        }
        if (win) return p;
        if (row == col) {
            win = true;
            for (int i = 0; i < n && win; ++i) {
                if (board[i][i] != p) win = false;
            }
            if (win) return p;
        }
        if (row + col == n - 1) {
            win = true;
            for (int i = 0; i < n && win; ++i) {
                if (board[i][n - 1 - i] != p) win = false;
            }
            if (win) return p;
        }
        return 0;
    }
public:
    TicTacToe(int n) : n(n) {
        board = vector<vector<int>>(n, vector<int>(n));
    }
    int move(int row, int col, int player) {
        board[row][col] = player;
        return status(row, col);
    }
};