// Author: github.com/lzl124631x
static bool cmp (pair<int, int> a, pair<int, int> b) {
  return a.first < b.first;
}
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int, int>> v;
    for (int i = 0; i < nums.size(); ++i) v.push_back(make_pair(nums[i], i));
      sort(v.begin(), v.end(), cmp);
    int i = 0, j = v.size() - 1;
    while (i < j) {
      int sum = v[i].first + v[j].first;
      if (sum > target) --j;
      else if (sum < target) ++i;
      else {
        return { v[i].second, v[j].second };
      }
    }
    return {};
  }
};