class Solution {
private:
    bool check(vector<vector<char>> &board, char (&get)(vector<vector<char>> &, int, int)) {
         for (int i = 0; i < 9; ++i) {
            unsigned b = 0;
            for (int j = 0; j < 9; ++j) {
                char x = get(board, i, j);
                if (x == '.') continue;
                unsigned mask = (1 << (x - '1'));
                if (b & mask) return false;
                b |= mask;
            }
        }
        return true;
    }
private:
    static char getRow(vector<vector<char>> &board, int i, int j) { return board[i][j]; }
    static char getCol(vector<vector<char>> &board, int i, int j) { return board[j][i]; }
    static char getCell(vector<vector<char>> &board, int i, int j) {
        return board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3];
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return check(board, getRow) && check(board, getCol) && check(board, getCell);
    }
};