// OJ: https://leetcode.com/problems/frog-position-after-t-seconds/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/frog-position-after-t-seconds/discuss/532571/Python-DFS
class Solution {
    vector<vector<int>> g;
    vector<bool> seen;
    double dfs(int node, int t, int target) {
        seen[node] = true;
        int cnt = g[node].size() - (node != 1);
        if (!t) return node == target;
        if (node == target) return !cnt;
        double ans = 0;
        for (int n : g[node]) {
            if (seen[n]) continue;
            if (ans = dfs(n, t - 1, target)) break;
        }
        if (ans) ans /= cnt;
        return ans;
    }
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        g.resize(n + 1);
        seen.resize(n + 1);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        return dfs(1, t, target);
    }
};