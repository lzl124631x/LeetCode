// OJ: https://leetcode.com/problems/surrounded-regions
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
// Ref: https://discuss.leetcode.com/topic/1944/solve-it-using-union-find
class UnionFind {
    vector<int> id, rank;
public:
    UnionFind(int n): id(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) id[i] = i;
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        if (rank[x] <= rank[y]) {
            id[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        } else id[y] = x;
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};
class Solution {
    int M, N, dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    inline int get(int x, int y) { return N * x + y; }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        M = board.size(), N = board[0].size();
        UnionFind uf(M * N + 1);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] != 'O') continue;
                if (!i || i == M - 1 || !j || j == N - 1) uf.connect(get(i, j), M * N);
                for (auto &dir : dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    if (x < 0 || x >= M || y < 0 || y >= N || board[x][y] != 'O') continue;
                    uf.connect(get(i, j), get(x, y));
                }
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!uf.connected(get(i, j), M * N)) board[i][j] = 'X';
            }
        }
    }
};