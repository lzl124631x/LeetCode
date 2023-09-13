// https://discuss.leetcode.com/topic/50885/simple-java-o-klogk-solution-with-explanation/
class Solution {
public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    auto cmp = [&nums1, &nums2](pair<int, int> &a, pair<int, int> &b) {
      return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
    k = min(int(nums1.size() * nums2.size()), k);
    for (int i = 0; i < k && i < nums1.size(); ++i) q.emplace(i, 0);
    vector<pair<int, int>> ans;
    while (k-- > 0) {
        auto p = q.top();
        q.pop();
        ans.emplace_back(nums1[p.first], nums2[p.second]);
        if (p.second + 1 < nums2.size()) q.emplace(p.first, p.second + 1);
    }
    return ans;
  }
};