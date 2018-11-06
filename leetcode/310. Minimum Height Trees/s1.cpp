// OJ: https://leetcode.com/problems/minimum-height-trees
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    if (n == 1) return { 0 };
    map<int, set<int>> m;
    for (auto e : edges) {
      m[e.first].insert(e.second);
      m[e.second].insert(e.first);
    }
    while (m.size() > 2) {
      vector<int> rm;
      for (auto p : m) if (p.second.size() == 1) rm.push_back(p.first);
      for (int n : rm) {
        m[*m[n].begin()].erase(n);
        m.erase(n);
      }
    }
    vector<int> ans;
    for (auto p : m) ans.push_back(p.first);
    return ans;
  }
};