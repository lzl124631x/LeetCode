// OJ: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Author: github.com/lzl124631x
// Time: O(A * logN)
// Space: O(N)
class UnionFind {
    vector<int> rank, id;
    int cnt;
public:
    UnionFind(int n): rank(n, 1), id(n), cnt(n) {
        for (int i = 0; i < n; ++i) id[i] = i;
    }
    int find(int x) {
        if (x == id[x]) return x;
        return id[x] = find(id[x]);
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        if (rank[x] <= rank[y]) {
            id[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        } else id[y] = x;
        --cnt;
    }
    int getCount() { return cnt; }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& A) {
        if (A.size() < n - 1) return -1;
        UnionFind uf(n);
        for (auto &v : A) uf.connect(v[0], v[1]);
        return uf.getCount() - 1;
    }
};