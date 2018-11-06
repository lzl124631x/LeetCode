// OJ: https://leetcode.com/problems/minimum-time-difference
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  int findMinDifference(vector<string>& timePoints) {
    set<int> s;
    for (string timeStr : timePoints) {
      int key = stoi(timeStr.substr(0, 2)) * 60 + stoi(timeStr.substr(3, 2));
      if (s.count(key)) return 0;
      s.insert(key);
    }
    int minDiff = INT_MAX;
    for (auto i = s.begin(); i != s.end(); ++i) {
      auto j = next(i);
      minDiff = min(minDiff, (j == s.end() ? 24 * 60 + *s.begin() : *j) - *i);
    }
    return minDiff;
  }
};