// OJ: https://leetcode.com/problems/largest-component-size-by-common-factor/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class UnionFind {
private:
  vector<int> id, rank, size;
public:
  UnionFind(int cnt) {
    id = vector<int>(cnt);
    rank = vector<int>(cnt, 0);
      size=vector<int>(cnt, 1);
    for (int i = 0; i < cnt; ++i) id[i] = i;
  }
  int find(int p) {
      if (id[p] == p) return p;
      return id[p] = find(id[p]);
  }
  bool connected(int p, int q) { return find(p) == find(q); }
  void connect(int p, int q) {
    int i = find(p), j = find(q);
    if (i == j) return;
    if (rank[i] < rank[j]) {
        id[i] = j;
        size[j] += size[i];
    }
    else {
      id[j] = i;
        size[i] += size[j];
      if (rank[i] == rank[j]) rank[j]++;
    }
  }
  int maxSize() {
      int ans = 1;
      for (int r : size) ans = max(ans, r);
      return ans;
  }
};
class Solution {
private:
    bool shareCommonFactor(int a, int b) {
        if (b > a) swap(a, b);
        while (b) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a != 1;
    }
public:
    int largestComponentSize(vector<int>& A) {
        int N = A.size();
        UnionFind uf(N);
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (uf.connected(i, j)) continue;
                if (shareCommonFactor(A[i], A[j])) uf.connect(i, j);
            }
        }
        return uf.maxSize();
    }
};