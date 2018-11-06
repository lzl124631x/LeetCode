// OJ: https://leetcode.com/problems/word-search-ii
// Author: github.com/lzl124631x
// Time: O(MN4^K)
// Space: O(WK)
// Where K is the average length of words.
struct TrieNode {
  struct TrieNode *next[26] = {0};
  bool end = false;
  void insert(string word) {
    TrieNode *node = this;
    for (char c : word) {
      if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
      node = node->next[c - 'a'];
    }
    node->end = true;
  }
};
class Solution {
private:
  vector<string> ans;
  void dfs(vector<vector<char>> &board, int x, int y, TrieNode *node, string &path) {
    char c = board[x][y];
    if (!c || !node->next[c - 'a']) return;
    node = node->next[c - 'a'];
    path.push_back(c);
    if (node->end) {
      ans.push_back(path);
      node->end = false;
    }
    board[x][y] = '\0';
    if (x + 1 < board.size()) dfs(board, x + 1, y, node, path);
    if (x - 1 >= 0) dfs(board, x - 1, y, node, path);
    if (y + 1 < board[0].size()) dfs(board, x, y + 1, node, path);
    if (y - 1 >= 0) dfs(board, x, y - 1, node, path);
    board[x][y] = c;
    path.pop_back();
  }
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    if (board.empty() || board[0].empty()) return {};
    TrieNode root;
    for (auto word : words) root.insert(word);
    string path;
    for (int i = 0; i < board.size(); ++i) 
      for (int j = 0; j < board[0].size(); ++j)
        dfs(board, i, j, &root, path);
    return ans;
  }
};