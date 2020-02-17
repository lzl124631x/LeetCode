// OJ: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    void bfs(vector<vector<int>> &G, vector<bool> &visited, int start) {
        visited[start] = true;
        queue<int> q;
        q.push(start);
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int v : G[u]) {
                if (visited[v]) continue;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    int getComponentCount(vector<vector<int>> &G) {
        int ans = 0;
        vector<bool> visited(G.size());
        for (int i = 0; i < G.size(); ++i) {
            if (visited[i]) continue;
            ++ans;
            bfs(G, visited, i);
        }
        return ans;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int N = stones.size();
        vector<vector<int>> G(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        return stones.size() - getComponentCount(G);
    }
};