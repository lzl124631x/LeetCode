// OJ: https://leetcode.com/problems/friend-circles
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
private:
  void dfs(vector<vector<int>>& M, int i, vector<bool> &visited) {
    visited[i] = true;
    for (int j = i + 1; j < M.size(); ++j) {
      if (!M[i][j] || visited[j]) continue;
      dfs(M, j, visited);
    }
  }
public:
  int findCircleNum(vector<vector<int>>& M) {
    vector<bool> visited(M.size(), false);
    int cnt = 0;
    for (int i = 0; i < M.size(); ++i) {
      if (visited[i]) continue;
      dfs(M, i, visited);
      ++cnt;
    }
    return cnt;
  }
};