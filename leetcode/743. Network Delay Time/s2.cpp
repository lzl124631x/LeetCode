// OJ: https://leetcode.com/problems/network-delay-time/
// Author: github.com/lzl124631x
// Time: O(VE)
// Space: O(V)
class Solution {
    vector<int> bellmanFord(vector<vector<int>>& edges, int V, int src) {
        vector<int> dist(V, INT_MAX);
        dist[src - 1] = 0;
        for (int i = 1; i < V; ++i) {
            for (auto &e : edges) {
                int u = e[0] - 1, v = e[1] - 1, w = e[2];
                if (dist[u] == INT_MAX) continue;
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
        return dist;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        auto dist = bellmanFord(times, N, K);
        int ans = *max_element(dist.begin(), dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};