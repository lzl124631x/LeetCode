// OJ: https://leetcode.com/problems/valid-tic-tac-toe-state/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
private:
    int count(vector<string>& board, char target){ 
        int cnt = 0;
        for (auto row : board) {
            for (char c : row) {
                if (c == target) ++cnt;
            }
        }
        return cnt;
    }
    bool testWin(vector<string>& board, char target) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] != target) break;
                if (j == 2) return true;
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[j][i] != target) break;
                if (j == 2) return true;
            }
        }
        for (int i = 0; i < 3; ++i) {
            if (board[i][i] != target) break;
            if (i == 2) return true;
        }
        for (int i = 0; i < 3; ++i) {
            if (board[i][2 - i] != target) break;
            if (i == 2) return true;
        }
        return false;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        int xCnt = count(board, 'X');
        int oCnt = count(board, 'O');
        if (xCnt != oCnt && xCnt != oCnt + 1) return false;
        bool xWin = testWin(board, 'X');
        bool oWin = testWin(board, 'O');
        if (xWin && oWin) return false;
        if (!xWin && !oWin) return true;
        return (xWin && xCnt == oCnt + 1) || (oWin && xCnt == oCnt);
    }
};