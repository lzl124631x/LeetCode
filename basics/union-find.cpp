class UnionFind {
private:
    vector<int> id, rank;
    int cnt;
    int find (int i) {
        if (id[i] == i) return i;
        return id[i] = find(id[i]);
    }
public:
    UnionFind(int n) : id(n), rank(n, 0), cnt(n) {
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
        --cnt;
    }
    bool connected(int i, int j) { return find(i) == find(j); }
    int getCount() { return cnt; }
};