// OJ: https://leetcode.com/problems/find-duplicate-file-in-system
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> m;
    for (auto path : paths) {
      int start = 0;
      string root;
      while (start < path.size()) {
        int next = path.find(" ", start);
        if (next == string::npos) next = path.size();
        string token = path.substr(start, next - start);
        start = next + 1;
        if (root.empty()) root = token;
        else {
          int paren = token.find("(");
          string file = root + "/" + token.substr(0, paren);
          string content = token.substr(paren + 1, token.size() - paren - 2);
          m[content].push_back(file);
        }
      }
    }
    vector<vector<string>> ans;
    for (auto p : m) {
      if (p.second.size() > 1) ans.push_back(p.second);
    }
    return ans;
  }
};