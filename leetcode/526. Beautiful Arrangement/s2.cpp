// OJ: https://leetcode.com/problems/beautiful-arrangement
// Author: github.com/lzl124631x
// Time: O(N^2 * logN)
// Space: O(N)
class Solution {
private:
  int dfs(set<int> &s, int pos, int N) {
    if (pos == N) return 1;
    int cnt = 0;
    for (auto it = s.begin(); it != s.end(); ++it) {
      int n = *it;
      if (n % (pos + 1) && (pos + 1) % n) continue;
      s.erase(n);
      cnt += dfs(s, pos + 1, N);
      s.insert(n);
    }
    return cnt;
  }
public:
  int countArrangement(int N) {
    set<int> s;
    for (int i = 1; i <= N; ++i) s.insert(i);
    return dfs(s, 0, N);
  }
};