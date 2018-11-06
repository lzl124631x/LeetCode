// OJ: https://leetcode.com/problems/minimum-time-difference
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
private:
  inline int getKey(string &s) {
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
  }
public:
  int findMinDifference(vector<string>& timePoints) {
    sort(timePoints.begin(), timePoints.end());
    int ans = INT_MAX;
    for (int i = timePoints.size() - 1; i >= 0 && ans; --i) {
      ans = min(ans, getKey(timePoints[i]) - (i == 0 ? getKey(timePoints.back()) - 24 * 60 : getKey(timePoints[i - 1])));
    }
    return ans;
  }
};