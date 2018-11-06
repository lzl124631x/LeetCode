// OJ: https://leetcode.com/problems/surrounded-regions
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
// Ref: https://discuss.leetcode.com/topic/1944/solve-it-using-union-find
class UnionFind {
private:
  int* id;
  int* rank;
  int count;
public:
  UnionFind (int N) {
    count = N;
    id = new int[N];
    rank = new int[N];
    for (int i = 0; i < N; ++i) {
      id[i] = i;
      rank[i] = 0;
    }
  }
  ~UnionFind () {
    delete [] id;
    delete [] rank;
  }
  int find (int p) {
    while (p != id[p]) {
      id[p] = id[id[p]];
      p = id[p];
    }
    return p;
  }
  int getCount() {
    return count;
  }
  bool connected(int p, int q) {
    return find(p) == find(q);
  }
  void connect(int p, int q) {
    int i = find(p), j = find(q);
    if (i == j) return;
    if (rank[i] < rank[j]) id[i] = j;
    else if (rank[i] > rank[j]) id[j] = i;
    else {
      id[j] = i;
      rank[i]++;
    }
    count--;
  }
};
class Solution {
private:
  const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
  void solve(vector<vector<char>>& board) {
    if (board.empty() || board[0].empty()) return;
    int M = board.size(), N = board[0].size();
    UnionFind uf(M * N + 1);
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (board[i][j] != 'O') continue;
        if (!i || i == M - 1 || !j || j == N - 1) uf.connect(i * N + j, M * N);
        else {
          for (auto &dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (board[x][y] == 'O') uf.connect(x * N + y, i * N + j);
          }
        }
      }
    }
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (!uf.connected(i * N + j, M * N)) board[i][j] = 'X';
      }
    }
  }
};