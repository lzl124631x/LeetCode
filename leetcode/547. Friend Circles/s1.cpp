// OJ: https://leetcode.com/problems/friend-circles
// Auther: github.com/lzl124631x
// Time: O(N^2 * logN)
// Space: O(N)
class UnionFind {
private:
  vector<int> id, rank;
  int cnt;
public:
  UnionFind(int cnt) : cnt(cnt) {
    id = vector<int>(cnt);
    rank = vector<int>(cnt, 0);
    for (int i = 0; i < cnt; ++i) id[i] = i;
  }
  int find(int p) {
    while (p != id[p]) {
      id[p] = id[id[p]];
      p = id[p];
    }
    return p;
  }
  int getCount() { return cnt; }
  bool connected(int p, int q) { return find(p) == find(q); }
  void connect(int p, int q) {
    int i = find(p), j = find(q);
    if (i == j) return;
    if (rank[i] < rank[j]) id[i] = j;
    else if (rank[i] > rank[j]) id[j] = i;
    else {
      id[j] = i;
      rank[j]++;
    }
    --cnt;
  }
};
class Solution {
public:
  int findCircleNum(vector<vector<int>>& M) {
    int N = M.size();
    UnionFind uf(N);
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        if (M[i][j]) uf.connect(i, j);
    return uf.getCount();
  }
};