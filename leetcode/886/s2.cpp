// OJ: https://leetcode.com/problems/possible-bipartition/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& A) {
        vector<vector<int>> G(N + 1);
        vector<int> id(N + 1, 0);
        for (auto &v : A) {
            G[v[0]].push_back(v[1]);
            G[v[1]].push_back(v[0]);
        }
        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (id[i]) continue;
            q.push(i);
            id[i] = 1;
            while (q.size()) {
                int u = q.front();
                q.pop();
                for (int v : G[u]) {
                    if (id[v]) {
                        if (id[v] != -id[u]) return false;
                        else continue;
                    }
                    id[v] = -id[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
};