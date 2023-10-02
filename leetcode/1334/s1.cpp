// OJ: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// Author: github.com/lzl124631x
// Time: O(V * (E + VlogV))
// Space: O(E)
class Solution {
    typedef pair<int, int> iPair; 
    unordered_map<int, vector<iPair>> graph;
    int th, N, minNum = INT_MAX;
    int dijkstra(int i) {
        priority_queue<iPair, vector<iPair>, greater<iPair>> q;
        vector<int> dist(N, INT_MAX);
        q.push(make_pair(0, i));
        dist[i] = 0;
        while (q.size()) {
            int u = q.top().second;
            q.pop();
            for (auto ne : graph[u]) {
                int v = ne.first;
                int w = ne.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.push(make_pair(dist[v], v));
                }
            }
        }
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            if (j != i && dist[j] <= th) ++cnt;
        }
        return cnt;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        th = distanceThreshold;
        N = n;
        for (auto e : edges) {
            m[e[0]].push_back(make_pair(e[1], e[2]));
            m[e[1]].push_back(make_pair(e[0], e[2]));
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = dijkstra(i);
            if (cnt <= minNum) {
                minNum = cnt;
                ans = i;
            }
        }
        return ans;
    }
};