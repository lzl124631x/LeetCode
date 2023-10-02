// OJ: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    vector<vector<int>> G;
    vector<bool> seen;
    int dfs(int u, vector<bool> &hasApple) {
        seen[u] = true;
        int ans = 0;
        for (auto v : G[u]) {
            if (seen[v]) continue;
            ans += dfs(v, hasApple);
        }
        if (!ans && !hasApple[u]) return 0;
        return u == 0 ? ans : ans + 1;
    }
public:
    int minTime(int n, vector<vector<int>>& E, vector<bool>& hasApple) {
        seen.assign(n, false);
        G.assign(n, {});
        for (auto & e : E) G[e[0]].push_back(e[1]), G[e[1]].push_back(e[0]);
        return 2 * dfs(0, hasApple);
    }
};