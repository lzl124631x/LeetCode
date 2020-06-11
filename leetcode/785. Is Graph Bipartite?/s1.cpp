// OJ: https://leetcode.com/problems/is-graph-bipartite/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
    bool dfs(vector<vector<int>> &G, vector<int> &id, int u, int prev = 1) {
        if (id[u]) return id[u] != prev;
        id[u] = -prev;
        for (int v : G[u]) {
            if (!dfs(G, id, v, id[u])) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& G) {
        vector<int> id(G.size());
        for (int i = 0; i < G.size(); ++i) {
            if (id[i]) continue;
            if (!dfs(G, id, i)) return false;
        }
        return true;
    }
};