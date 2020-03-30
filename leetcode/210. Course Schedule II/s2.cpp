// OJ: https://leetcode.com/problems/course-schedule-ii/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
    vector<int> ans;
    unordered_map<int, vector<int>> G;
    vector<int> seen;
    bool dfs(int u) {
        if (seen[u]) return seen[u] == 1;
        seen[u] = -1;
        for (int v : G[u]) {
            if (!dfs(v)) return false;
        }
        seen[u] = 1;
        ans.push_back(u);
        return true;
    }
public:
    vector<int> findOrder(int N, vector<vector<int>>& E) {
        seen.assign(N, 0);
        for (auto &e : E) G[e[1]].push_back(e[0]);
        for (int i = 0; i < N; ++i) {
            if (seen[i]) continue;
            if (!dfs(i)) return {};
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};