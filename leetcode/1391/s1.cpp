// OJ: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class UnionFind {
private:
    vector<int> id, rank;
    int find (int i) {
        if (id[i] == i) return i;
        return id[i] = find(id[i]);
    }
public:
    UnionFind(int n) : id(n), rank(n, 0) {
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
    }
    bool connected(int i, int j) { return find(i) == find(j); }
};
class Solution {
    int M, N;
    int h(int x, int y) { return x * N + y; }
    const int dirs[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
    const int neighbor[6][2] = {{0,1}, {2,3}, {0,3}, {1,3}, {0,2}, {1,2}};
public:
    bool hasValidPath(vector<vector<int>>& A) {
        M = A.size(), N = A[0].size();
        UnionFind uf(M * N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int n : neighbor[A[i][j] - 1]) {
                    int x = i + dirs[n][0], y = j + dirs[n][1];
                    if (x < 0 || x >= M || y < 0 || y >= N) continue;
                    int r = n ^ 1;
                    auto &rn = neighbor[A[x][y] - 1];
                    if (rn[0] != r && rn[1] != r) continue;
                    uf.connect(h(x, y), h(i, j));
                }
            }
        }
        return uf.connected(h(0,0), h(M-1,N-1));
    }
};