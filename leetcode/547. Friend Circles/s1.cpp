// OJ: https://leetcode.com/problems/friend-circles/
// Author: github.com/lzl124631x
// Time: O(N^2 * a(N)), where `a` is the inverse function of Ackermann function. O(a(N)) is faster than O(log(N)).
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
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        UnionFind uf(N);
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                if (M[i][j]) uf.connect(i, j);
        return uf.getCount();
    }
};