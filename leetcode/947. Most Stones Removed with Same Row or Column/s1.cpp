// OJ: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int N = stones.size();
        vector<vector<int>> graph(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i][++graph[i][0]] = j;
                    graph[j][++graph[j][0]] = i;
                }
            }
        }
        int ans = 0;
        vector<bool> seen(N);
        for (int i = 0; i < N; ++i) {
            if (seen[i]) continue;
            stack<int> s;
            s.push(i);
            seen[i] = true;
            --ans;
            while (s.size()) {
                int node = s.top();
                s.pop();
                ++ans;
                for (int j = 1; j <= graph[node][0]; ++j) {
                    int n = graph[node][j];
                    if (!seen[n]) {
                        s.push(n);
                        seen[n] = true;
                    }
                }
            }
        }
        return ans;
    }
};