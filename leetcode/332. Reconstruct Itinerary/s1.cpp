// OJ: https://leetcode.com/problems/reconstruct-itinerary
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
  unordered_map<string, multiset<string>> m;
  bool dfs(vector<string> &path, int leftCnt) {
    if (!leftCnt) return true;
    multiset<string> &toes = m[path.back()];
    for (auto it = toes.begin(); it != toes.end(); it = toes.upper_bound(*it)) {
      string to = *it;
      path.push_back(to);
      toes.erase(it);
      if (dfs(path, leftCnt - 1)) return true;
      path.pop_back();
      toes.insert(to);
    }
    return false;
  }
public:
  vector<string> findItinerary(vector<pair<string, string>> tickets) {
    for (auto t : tickets) m[t.first].insert(t.second);
    vector<string> path { "JFK" };
    dfs(path, tickets.size());
    return path;
  }
};