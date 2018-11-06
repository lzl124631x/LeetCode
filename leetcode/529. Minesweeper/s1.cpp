// OJ: https://leetcode.com/problems/minesweeper
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
private:
  static const int DIR[8][2];
  int M, N;
  void updateBoard(vector<vector<char>> &board, int x, int y) {
    if (board[x][y] == 'M') {
      board[x][y] = 'X';
    } else if (board[x][y] == 'E') {
      int cnt = 0;
      for (int k = 0; k < 8; ++k) {
        int i = x + DIR[k][0], j = y + DIR[k][1];
        if (i >= 0 && i < M && j >= 0 && j < N && (board[i][j] == 'M' || board[i][j] == 'X')) ++cnt;
      }
      board[x][y] = cnt ? '0' + cnt : 'B';
      if (cnt) return;
      for (int k = 0; k < 8; ++k) {
        int i = x + DIR[k][0], j = y + DIR[k][1];
        if (i >= 0 && i < M && j >= 0 && j < N && board[i][j] == 'E') updateBoard(board, i, j);
      }
    }
  }
public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    M = board.size();
    N = board[0].size();
    updateBoard(board, click[0], click[1]);
    return board;
  }
};
const int Solution::DIR [][2] = {{ -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }};