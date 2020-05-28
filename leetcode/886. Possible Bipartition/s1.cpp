// OJ: https://leetcode.com/problems/possible-bipartition/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
    vector<unordered_set<int>> G;
    vector<int> id;
    bool dfs(int u, int prev = 1) {
        if (id[u]) return id[u] != prev;
        id[u] = -prev;
        for (int v : G[u]) {
            if (!dfs(v, id[u])) return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& A) {
        G.assign(N + 1, {});
        id.assign(N + 1, 0);
        for (auto &v : A) {
            G[v[0]].insert(v[1]);
            G[v[1]].insert(v[0]);
        }
        for (int i = 1; i <= N; ++i) {
            if (id[i]) continue;
            if (!dfs(i)) return false;
        }
        return true;
    }
};