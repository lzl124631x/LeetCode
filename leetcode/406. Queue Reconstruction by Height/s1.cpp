// OJ: https://leetcode.com/problems/queue-reconstruction-by-height
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/60470/6-lines-concise-c
class Solution {
public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    sort(people.begin(), people.end(), [](pair<int, int> a, pair<int, int> b) {
      return a.first == b.first ? a.second < b.second : a.first > b.first;
    });
    vector<pair<int, int>> ans;
    for (auto p : people) ans.insert(ans.begin() + p.second, p);
    return ans;
  }
};