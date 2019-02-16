// OJ: https://leetcode.com/problems/graph-valid-tree/
// Author: github.com/lzl124631x
// Time: O(E)
// Space: O(N)
class UnionFind {
private:
    vector<int> rank;
    vector<int> id;
    int count;
    int find (int i) {
        if (id[i] == i) return i;
        return id[i] = find(id[i]);
    }
public:
    UnionFind(int n) : rank(n, 0), id(n), count(n) {
        for (int i = 0; i < n; ++i) id[i] = i;
    }
    void connect(int i, int j) {
        int p = find(i), q = find(j);
        if (p == q) return;
        if (rank[p] > rank[q]) id[p] = q;
        else {
            id[q] = p;
            if (rank[p] == rank[q]) rank[p]++;
        }
        --count;
    }
    int getCount() { return count; }
};
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n - 1) return false;
        UnionFind uf(n);
        for (auto &e : edges) uf.connect(e.first, e.second);
        return uf.getCount() == 1;
    }
};