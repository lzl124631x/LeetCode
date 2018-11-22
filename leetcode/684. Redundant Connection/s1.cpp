// OJ: https://leetcode.com/problems/redundant-connection/
// Author: github.com/lzl124631x
// Time: O(N)
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
      if (id[p] == p) return p;
      return id[p] = find(id[p]);
  }
  int getCount() { return cnt; }
  bool connected(int p, int q) { return find(p) == find(q); }
  void connect(int p, int q) {
    int i = find(p), j = find(q);
    if (i == j) return;
    if (rank[i] < rank[j]) id[i] = j;
    else {
      id[j] = i;
      if (rank[i] == rank[j]) rank[j]++;
    }
    --cnt;
  }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size());
        for (auto e : edges) {
            if (uf.connected(e[0] - 1, e[1] - 1)) return e;
            uf.connect(e[0] - 1, e[1] - 1);
        }
    }
};