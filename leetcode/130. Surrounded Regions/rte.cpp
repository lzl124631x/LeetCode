// OJ: https://leetcode.com/problems/surrounded-regions
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
// Note: RTE caused by stack overflow.
class Solution {
private:
  const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  void dfs(vector<vector<char>> &board, int x, int y) {
    if (board[x][y] != 'O') return;
    board[x][y] = '#';
    for (auto dir : dirs) {
      int i = x + dir[0], j = y + dir[1];
      if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size()) dfs(board, i, j);
    }
  }
public:
  void solve(vector<vector<char>>& board) {
    if (board.empty() || board[0].empty()) return;
    int M = board.size(), N = board[0].size();
    for (int i = 0; i < N; ++i) {
      dfs(board, 0, i);
      if (M > 1) dfs(board, M - 1, i);
    }
    for (int j = 1; j < M - 1; ++j) {
      dfs(board, j, 0);
      if (N > 1) dfs(board, j, N - 1);
    }
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        board[i][j] = board[i][j] == '#' ? 'O' : 'X';
      }
    }
  }
};