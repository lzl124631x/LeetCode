// OJ: https://leetcode.com/problems/minimum-height-trees
// Author: github.com/lzl124631x
// Time: O(E)
// Space: O(E)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return { 0 };
        unordered_map<int, unordered_set<int>> neighbors;
        for (auto &e : edges) {
            neighbors[e.first].insert(e.second);
            neighbors[e.second].insert(e.first);
        }
        vector<int> leaves;
        for (auto &p : neighbors) {
            if (p.second.size() == 1) leaves.push_back(p.first);
        }
        while (neighbors.size() > 2) {
            vector<int> newLeaves;
            for (int leaf : leaves) {
                int neighbor = *neighbors[leaf].begin();
                neighbors[neighbor].erase(leaf);
                if (neighbors[neighbor].size() == 1) newLeaves.push_back(neighbor);
                neighbors.erase(leaf);
            }
            leaves = newLeaves;
        }
        vector<int> ans;
        for (auto &p : neighbors) ans.push_back(p.first);
        return ans;
    }
};