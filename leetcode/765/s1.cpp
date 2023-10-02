// OJ: https://leetcode.com/problems/couples-holding-hands/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/couples-holding-hands/discuss/117520/Java-union-find-easy-to-understand-5-ms
class UnionFind {
    vector<int> id, rank;
    int cnt;
public:
    UnionFind(int n) : id(n), rank(n, 1), cnt(n) {
        for(int i = 0; i < n; ++i) id[i] = i;
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
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    int getCount() { return cnt; }
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int N = row.size() / 2;
        UnionFind uf(N);
        for (int i = 0; i < N; ++i) uf.connect(row[2 * i] / 2, row[2 * i + 1] / 2);
        return N - uf.getCount();
    }
};