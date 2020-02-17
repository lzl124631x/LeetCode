// OJ: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class UnionFind {
    vector<int> id, rank;
    int cnt;
public:
    UnionFind(int n) : cnt(n), id(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) id[i] = i;
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
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
    int removeStones(vector<vector<int>>& stones) {
        int N = stones.size();
        UnionFind uf(N);
        for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    uf.connect(i, j);
                }
            }
        }
        return stones.size() - uf.getCount();
    }
};