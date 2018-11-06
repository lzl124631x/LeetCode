// OJ: https://leetcode.com/problems/word-search
// Author: github.com/lzl124631x
// Time: O(MN4^K)
// Space: O(K)
class Solution {
private:
  const vector<vector<int>> dirs {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  bool exist(vector<vector<char>>& board, string &word, int x, int y, int k) {
    if (x < 0 || x >= board.size()
      || y < 0 || y >= board[0].size() || word[k] != board[x][y]) return false;
    if (k == word.size() - 1) return true;
    char c = board[x][y];
    board[x][y] = '\0';
    for (auto dir : dirs) {
      if (exist(board, word, x + dir[0], y + dir[1], k + 1)) return true;
    }
    board[x][y] = c;
    return false;
  }
public:
  bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (exist(board, word, i, j, 0)) return true;
      }
    }
    return false;
  }
};