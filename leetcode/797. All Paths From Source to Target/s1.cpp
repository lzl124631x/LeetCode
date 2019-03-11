// OJ: https://leetcode.com/problems/all-paths-from-source-to-target/
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(N)
class Solution {
private:
    vector<vector<int>> ans;
    unordered_set<int> seen;
    vector<int> path;
    void dfs(vector<vector<int>>& graph, int from) {
        path.push_back(from);
        if (from == graph.size() - 1) ans.push_back(path);
        else {
            seen.insert(from);
            for (int n : graph[from]) {
                if (seen.find(n) != seen.end()) continue;
                dfs(graph, n);
            }
            seen.erase(from);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0);
        return ans;
    }
};