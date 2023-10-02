// OJ: https://leetcode.com/problems/minimize-malware-spread-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class UnionFind {
private:
    vector<int> rank, id, size;
public:
    UnionFind(int n): rank(n), id(n), size(n, 1) {
        for (int i = 0; i < n; ++i) id[i] = i;
    }
    int find(int p) {
        if (id[p] == p) return p;
        return id[p] = find(id[p]);
    }
    void connect(int p, int q) {
        int a = find(p), b = find(q);
        if (a == b) return;
        if (rank[a] > rank[b]) {
            id[b] = a;
            size[a] += size[b];
        } else {
            if (rank[a] == rank[b]) ++rank[b];
            id[a] = b;
            size[b] += size[a];
        }
    }
    int getUnionSize(int p) {
        return size[find(p)];
    }
};
class Solution {
private:
    int getInfectedCount(vector<vector<int>>& graph, int skip, vector<int>& initial) {
        int N = graph.size(), ans = 0;
        UnionFind uf(N);
        for (int i = 0; i < N; ++i) {
            if (i == skip) continue;
            for (int j = i + 1; j < N; ++j) {
                if (j == skip || !graph[i][j]) continue;
                uf.connect(i, j);
            }
        }
        unordered_set<int> s;
        for (int n : initial) s.insert(uf.find(n));
        for (int n : s) ans += uf.getUnionSize(n);
        return ans;
    }
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int ans = initial[0], minCnt = INT_MAX;
        sort(initial.begin(), initial.end());
        for (int n : initial) {
            int cnt = getInfectedCount(graph, n, initial);
            if (cnt < minCnt) {
                ans = n;
                minCnt = cnt;
            }
        }
        return ans;
    }
};