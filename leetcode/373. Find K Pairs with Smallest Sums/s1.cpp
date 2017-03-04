// Let M, N denote the length of nums1 and nums2
// Let K = min(k, MN)
// Time: O(KlogK)
// Space: O(K)
class Solution {
public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    auto cmp = [&nums1, &nums2](pair<int, int> &a, pair<int, int> &b) {
      return (nums1[a.first] + nums2[a.second]) > (nums1[b.first] + nums2[b.second]);
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
    q.emplace(0, 0);
    set<pair<int, int>> s {{ 0, 0 }};
    k = min(int(nums1.size() * nums2.size()), k);
    vector<pair<int, int>> ans;
    while (k-- > 0) {
      auto p = q.top();
      q.pop();
      int i = p.first, j = p.second;
      ans.emplace_back(nums1[i], nums2[j]);
      if (i + 1 < nums1.size() && !s.count({ i + 1, j })) {
        q.emplace(i + 1, j);
        s.emplace(i + 1, j);
      }
      if (j + 1 < nums2.size() && !s.count({ i, j + 1 })) {
        q.emplace(i, j + 1);
        s.emplace(i, j + 1);
      }
    }
    return ans;
  }
};