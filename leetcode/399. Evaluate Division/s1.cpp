// OJ: https://leetcode.com/problems/evaluate-division
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://discuss.leetcode.com/topic/59146/java-ac-solution-using-graph
class Solution {
private:
  unordered_map<string, unordered_map<string, double>> m;
  double dfs(string a, string b, unordered_set<string> &visited, double val) {
    if (m[a].count(b)) return val * m[a][b];
    for (auto p : m[a]) {
      if (visited.count(p.first)) continue;
      visited.insert(p.first);
      double v = dfs(p.first, b, visited, val * p.second);
      if (v != -1.0) return v;
    }
    return -1.0;
  }
public:
  vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    for (int i = 0; i < equations.size(); ++i) {
      auto eq = equations[i];
      double val = values[i];
      m[eq.first][eq.second] = val;
      m[eq.second][eq.first] = 1.0 / val;
    }
    vector<double> ans;
    for (auto q : queries) {
      string a = q.first, b = q.second;
      if (!m.count(a) || !m.count(b)) ans.push_back(-1.0);
      else if (a == b) ans.push_back(1.0);
      else {
        unordered_set<string> visited;
        ans.push_back(dfs(a, b, visited, 1.0));
      }
    }
    return ans;
  }
};