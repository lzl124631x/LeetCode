// OJ: https://leetcode.com/problems/binary-watch
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/59401/straight-forward-6-line-c-solution-no-need-to-explain
class Solution {
public:
  vector<string> readBinaryWatch(int num) {
    vector<string> ans;
    for (int h = 0; h < 12; ++h)
      for (int m = 0; m < 60; ++m)
        if (bitset<10>(h << 6 | m).count() == num)
          ans.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
    return ans;
  }
};