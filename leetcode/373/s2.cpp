// https://discuss.leetcode.com/topic/50481/clean-16ms-c-o-n-space-o-klogn-time-solution-using-priority-queue
// Let M, N denote the length of nums1 and nums2
// Let L = min(k, N), K = min(k, MN)
// Time: O(KlogL)
// Space: O(L)
class Solution {
public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    auto cmp = [&nums1, &nums2](pair<int, int> &a, pair<int, int> &b) {
      return (nums1[a.first] + nums2[a.second]) > (nums1[b.first] + nums2[b.second]);
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
    q.emplace(0, 0);
    k = min(int(nums1.size() * nums2.size()), k);
    vector<pair<int, int>> ans;
    while (k-- > 0) {
      auto p = q.top();
      q.pop();
      int i = p.first, j = p.second;
      ans.emplace_back(nums1[i], nums2[j]);
      if (i + 1 < nums1.size()) q.emplace(i + 1, j);
      if (i == 0 && j + 1 < nums2.size()) q.emplace(i, j + 1);
    }
    return ans;
  }
};