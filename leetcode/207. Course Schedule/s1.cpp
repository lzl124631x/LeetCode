// OJ: https://leetcode.com/problems/course-schedule/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& A) {
        unordered_map<int, vector<int>> G;
        vector<int> indegree(N);
        for (auto &e : A) {
            G[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        int visited = 0;
        while (q.size()) {
            int u = q.front();
            q.pop();
            ++visited;
            for (int v : G[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
        return visited == N;
    }
};