// OJ: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class UnionFind {
private:
    vector<int> ids, ranks;
    int cnt;
    int find(int i) {
        if (ids[i] == i) return i;
        return ids[i] = find(ids[i]);
    }
public:
    UnionFind(int cnt) : cnt(cnt) {
        ids = vector<int>(cnt);
        ranks = vector<int>(cnt);
        for (int i = 0; i < cnt; ++i) ids[i] = i;
    }
    bool connected(int i, int j) {
        return find(i) == find(j);
    }
    void connect(int i, int j) {
        if (connected(i, j)) return;
        int a = find(i), b = find(j);
        int r1 = ranks[a], r2 = ranks[b];
        if (r1 > r2) ids[b] = a;
        else {
            ids[a] = b;
            if (r1 == r2) ranks[b]++;
        }
        --cnt;
    }
    int count() { return cnt; }
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
        return stones.size() - uf.count();
    }
};