// OJ: https://leetcode.com/problems/queue-reconstruction-by-height
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
      return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
    });
    vector<vector<int>> ans;
    for (auto p : people) {
      int cnt = 0, i = 0;
      while (i < ans.size() && cnt < p[1]) cnt += (ans[i++][0] >= p[0]);
      ans.insert(ans.begin() + i, p);
    }
    return ans;
  }
};