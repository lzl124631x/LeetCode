// OJ: https://leetcode.com/problems/queue-reconstruction-by-height
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    sort(people.begin(), people.end(), [](pair<int, int> &a, pair<int, int> &b) {
      return a.second == b.second ? a.first > b.first : a.second < b.second;
    });
    vector<pair<int, int>> ans;
    for (auto p : people) {
      int cnt = 0, i = 0;
      while (i < ans.size() && cnt < p.second) cnt += (ans[i++].first >= p.first);
      ans.insert(ans.begin() + i, p);
    }
    return ans;
  }
};