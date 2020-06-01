// OJ: https://leetcode.com/problems/course-schedule-iv/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V^2)
class Solution {
    vector<vector<int>> G, m;
    bool dfs(int from, int to) {
        if (m[from][to] != -1) return m[from][to];
        bool ans = false;
        for (int v : G[from]) {
            if (dfs(v, to)) {
                ans = true;
                break;
            }
        }
        return m[from][to] = ans;
    }
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& A, vector<vector<int>>& Q) {
        G.assign(n, {});
        m.assign(n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) m[i][i] = 1;
        for (auto &e : A) G[e[0]].push_back(e[1]);
        vector<bool> ans;
        for (auto &e : Q) ans.push_back(dfs(e[0], e[1]));
        return ans;
    }
};