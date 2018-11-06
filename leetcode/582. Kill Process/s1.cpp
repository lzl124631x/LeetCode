// OJ: https://leetcode.com/problems/kill-process
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
  unordered_map<int, vector<int>> m;
  vector<int> ans;
  void dfs(int kill) {
    ans.push_back(kill);
    for (int c : m[kill]) dfs(c);
  }
public:
  vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    for (int i = 0; i < pid.size(); ++i) m[ppid[i]].push_back(pid[i]);
    dfs(kill);
    return ans;
  }
};