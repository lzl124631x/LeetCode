class Solution {
private:
  const vector<vector<int>> dirs {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  bool exist(vector<vector<char>> &board, string &word, int x, int y, int start) {
    if (board[x][y] != word[start]) return false;
    if (start == word.size() - 1) return true;
    char c = board[x][y];
    board[x][y] = '\0';
    bool ans = false;
    for (auto dir : dirs) {
      int i = x + dir[0], j = y + dir[1];
      if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size()
        && exist(board, word, i, j, start + 1)) {
        ans = true;
      break;
    }
  }
  board[x][y] = c;
  return ans;
}
bool exist(vector<vector<char>> &board, string &word) {
  for (int i = 0; i < board.size(); ++i)
    for (int j = 0; j < board[0].size(); ++j)
      if (exist(board, word, i, j, 0)) return true;
    return false;
  }
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    set<string> s;
    for (auto word : words) if (!s.count(word) && exist(board, word)) s.insert(word);
      return vector<string>(s.begin(), s.end());
  }
};