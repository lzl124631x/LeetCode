// OJ: https://leetcode.com/problems/minimum-height-trees
// Author: github.com/lzl124631x
// Time: O(E)
// Space: O(E)
class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    if (n == 1) return { 0 };
    unordered_map<int, unordered_set<int>> m;
    for (auto e : edges) {
      m[e.first].insert(e.second);
      m[e.second].insert(e.first);
    }
    queue<int> q;
    for (auto p : m) if (p.second.size() == 1) q.push(p.first);
    while (m.size() > 2) {
      int cnt = q.size();
      while (cnt--) {
        int leaf = q.front(), neighbor = *m[leaf].begin();
        q.pop();
        m[neighbor].erase(leaf);
        m.erase(leaf);
        if (m[neighbor].size() == 1) q.push(neighbor);
      }
    }
    vector<int> ans;
    for (auto p : m) ans.push_back(p.first);
    return ans;
  }
};