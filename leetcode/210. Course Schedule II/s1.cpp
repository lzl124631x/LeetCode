// OJ: https://leetcode.com/problems/course-schedule-ii/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& E) {
        unordered_map<int, vector<int>> G;
        vector<int> indegree(N);
        for (auto &e : E) {
            G[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        while (q.size()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (int v : G[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
        return ans.size() == N ? ans : vector<int>{};
    }
};