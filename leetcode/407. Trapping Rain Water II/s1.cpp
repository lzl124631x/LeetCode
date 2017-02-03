// https://discuss.leetcode.com/topic/60914/concise-c-priority_queue-solution
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) return 0;
        int M = heightMap.size(), N = heightMap[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == 0 || i == M - 1 || j == 0 || j == N - 1) {
                    q.push(make_pair(heightMap[i][j], i * N + j));
                    visited[i][j] = true;
                }
            }
        }
        vector<vector<int>> dir{{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};
        int ans = 0, maxH = INT_MIN;
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int h = p.first, x = p.second / N, y = p.second % N;
            maxH = max(maxH, h);
            for (auto d : dir) {
                int a = x + d[0], b = y + d[1];
                if (a < 0 || a >= M || b < 0 || b >= N || visited[a][b]) continue;
                visited[a][b] = true;
                if (heightMap[a][b] < maxH) ans += maxH - heightMap[a][b];
                q.push(make_pair(heightMap[a][b], a * N + b));
            }
        }
        return ans;
    }
};