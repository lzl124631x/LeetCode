// OJ: https://leetcode.com/problems/course-schedule/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& E) {
        unordered_map<int, vector<int>> m;
        vector<int> indegree(N);
        for (auto &pre : E) {
            m[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
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
            for (int v : m[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
        return visited == N;
    }
};