// OJ: https://leetcode.com/problems/is-graph-bipartite/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& G) {
        vector<int> id(G.size());
        queue<int> q;
        for (int i = 0; i < G.size(); ++i) {
            if (id[i]) continue;
            q.push(i);
            id[i] = 1;
            while (q.size()) {
                int u = q.front();
                q.pop();
                for (int v : G[u]) {
                    if (id[v]) {
                        if (id[v] != -id[u]) return false;
                        continue;
                    }
                    id[v] = -id[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
};