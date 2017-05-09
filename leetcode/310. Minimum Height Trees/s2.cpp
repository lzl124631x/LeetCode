// OJ: https://leetcode.com/problems/minimum-height-trees
// Auther: github.com/lzl124631x
// Time: O(N)
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
    queue<int> q;
    for (auto p : m) if (p.second.size() == 1) q.push(p.first);
    while (m.size() > 2) {
      int cnt = q.size();
      while (cnt--) {
        int from = q.front(), to = *m[from].begin();
        q.pop();
        m[to].erase(from);
        m.erase(from);
        if (m[to].size() == 1) q.push(to);
      }
    }
    vector<int> ans;
    for (auto p : m) ans.push_back(p.first);
    return ans;
  }
};