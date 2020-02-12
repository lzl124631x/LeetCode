// OJ: https://leetcode.com/problems/satisfiability-of-equality-equations/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    vector<bool> visited = vector<bool>(26, false);
    int color[26];
    vector<vector<int>> adj = vector<vector<int>>(26);
    void dfs(int u, int c) {
        visited[u] = true;
        color[u] = c;
        for (auto v : adj[u]) {
            if (!visited[v]) dfs(v, c);
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for (auto e : equations) {
            if (e[1] != '=') continue;
            adj[e[0] - 'a'].push_back(e[3] - 'a');
            adj[e[3] - 'a'].push_back(e[0] - 'a');
        }
        for (int i = 0, c = 0; i < 26; ++i) {
            if (!visited[i]) dfs(i, c++);
        }
        for (auto e : equations) {
            if (e[1] == '!' && color[e[0] - 'a'] == color[e[3] - 'a']) return false;
        }
        return true;
    }
};