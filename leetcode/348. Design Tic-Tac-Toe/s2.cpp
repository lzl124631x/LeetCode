// OJ: https://leetcode.com/problems/design-tic-tac-toe/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(N)
class TicTacToe {
private:
    vector<int> rows, cols;
    int n, diag = 0, anti = 0;
public:
    TicTacToe(int n) : n(n), rows(n, 0), cols(n, 0) {}
    
    int move(int row, int col, int player) {
        int d = player == 1 ? 1 : -1;
        rows[row] += d;
        cols[col] += d;
        if (row == col) diag += d;
        if (row + col == n - 1) anti += d;
        if (abs(rows[row]) == n
           || abs(cols[col]) == n
           || abs(diag) == n
           || abs(anti) == n) return player;
        return 0;
    }
};