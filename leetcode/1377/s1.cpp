// OJ: https://leetcode.com/problems/frog-position-after-t-seconds/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    unordered_map<int, vector<int>> g, nei;
    bool dfs(int start, int target, vector<int>&path) {
        path.push_back(start);
        if (start == target) return true;
        for (int n : g[start]) {
            if (dfs(n, target, path)) return true;
        }
        path.pop_back();
        return false;
    }
    void buildTree(int start, int p) {
        for (int n : nei[start]) {
            if (n == p) continue;
            g[start].push_back(n);
            buildTree(n, start);
        }
    }
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        for (auto & e : edges) {
            nei[e[0]].push_back(e[1]);
            nei[e[1]].push_back(e[0]);
        }
        buildTree(1, -1);
        vector<int> path;
        dfs(1, target, path);
        if (t + 1 < path.size() || (t + 1 > path.size() && g[path.back()].size())) return 0;
        int cnt = 1;
        for (int i = 0; i < path.size() - 1; ++i) cnt *= g[path[i]].size();
        return 1. / cnt;
    }
};