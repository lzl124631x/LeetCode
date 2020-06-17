// OJ: https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Author: github.com/lzl124631x
// Time: O(K * (N+ E))
// Space: O(N)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& A, int src, int dst, int K) {
        vector<int> dist(n, 1e8);
        dist[src] = 0;
        for (int i = 0; i <= K; ++i) {
            vector<int> tmp = dist;
            for (auto &e : A) {
                int u = e[0], v = e[1], w = e[2];
                dist[v] = min(dist[v], tmp[u] + w);
            }
        }
        return dist[dst] == 1e8 ? -1 : dist[dst];
    }
};