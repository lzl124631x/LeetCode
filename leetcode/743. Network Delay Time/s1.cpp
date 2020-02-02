// OJ: https://leetcode.com/problems/network-delay-time/
// Author: github.com/lzl124631x
// Time: O(E + VlogV)
// Space: O(E)
class Solution {
    typedef unordered_map<int, unordered_map<int, int>> Graph;
    typedef pair<int, int> iPair;
    vector<int> dijkstra(Graph graph, int N, int source) {
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        vector<int> dists(N, INT_MAX);
        pq.emplace(0, source);
        dists[source] = 0;
        while (pq.size()) {
            int u = pq.top().second;
            pq.pop();
            for (auto neighbor : graph[u]) {
                int v = neighbor.first, weight = neighbor.second;
                if (dists[v] > dists[u] + weight) {
                    dists[v] = dists[u] + weight;
                    pq.emplace(dists[v], v);
                }
            }
        }
        return dists;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        Graph graph;
        for (auto e : times) graph[e[0] - 1][e[1] - 1] = e[2];
        auto dists = dijkstra(graph, N, K - 1);
        int ans = 0;
        for (int d : dists) {
            if (d == INT_MAX) return -1;
            ans = max(ans, d);
        }
        return ans;
    }
};