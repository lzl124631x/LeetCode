// Let M, N denote the length of nums1 and nums2
// Let K = min(k, MN)
// Time: O(MNlogK)
// Space: O(K)
class Solution {
public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    auto cmp = [](pair<int, int> &a, pair<int, int> &b) {
      return a.first + a.second < b.first + b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
    k = min(int(nums1.size() * nums2.size()), k);
    for (int i = 0; i < nums1.size(); ++i) {
      for (int j = 0; j < nums2.size(); ++j) {
        if (q.size() < k) q.emplace(nums1[i], nums2[j]);
        else if (q.top().first + q.top().second > nums1[i] + nums2[j]) {
          q.pop();
          q.emplace(nums1[i], nums2[j]);
        }
      }
    }
    vector<pair<int, int>> ans;
    while (q.size()) {
      ans.push_back(q.top());
      q.pop();
    }
    return ans;
  }
};