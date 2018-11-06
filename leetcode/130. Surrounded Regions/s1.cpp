// OJ: https://leetcode.com/problems/surrounded-regions
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
private:
  const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
  void solve(vector<vector<char>>& board) {
    if (board.empty() || board[0].empty()) return;
    int M = board.size(), N = board[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < N; ++i) {
      if (board[0][i] == 'O') { q.emplace(0, i); board[0][i] = '#'; }
      if (board[M - 1][i] == 'O') { q.emplace(M - 1, i); board[M - 1][i] = '#'; }
    }
    for (int i = 1; i < M - 1; ++i) {
      if (board[i][0] == 'O') { q.emplace(i, 0); board[i][0] = '#'; }
      if (board[i][N - 1] == 'O') { q.emplace(i, N - 1); board[i][N - 1] = '#'; }
    }
    while (q.size()) {
      auto p = q.front();
      q.pop();
      for (auto dir : dirs) {
        int x = p.first + dir[0], y = p.second + dir[1];
        if (x >= 0 && x < M && y >= 0 && y < N && board[x][y] == 'O') {
          q.emplace(x, y);
          board[x][y] = '#';
        }
      }
    }
    for (auto &row : board)
      for (char &c : row) c = c == '#' ? 'O' : 'X';
  }
};