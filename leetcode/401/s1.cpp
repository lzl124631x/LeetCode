// OJ: https://leetcode.com/problems/binary-watch
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
private:
  vector<string> ans;
  bool valid(int bits) { return (bits >> 6) < 12 && (bits & ((1 << 6) - 1)) < 60; }
  void read(int bits) {
    int h = bits >> 6, m = bits - (h << 6);
    ans.push_back(to_string(h) + ':' + string(m < 10 ? 1 : 0, '0') + to_string(m));
  }
  void dfs(int num, int start, int bits) {
    if (!num) {
      read(bits);
      return;
    }
    for (int i = start; i < 10; ++i) {
      bits |= 1 << i;
      if (valid(bits)) dfs(num - 1, i + 1, bits);
      bits ^= 1 << i;
    }
  }
public:
  vector<string> readBinaryWatch(int num) {
    dfs(num, 0, 0);
    return ans;
  }
};