// OJ: https://leetcode.com/problems/top-k-frequent-elements/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class cmp {
public:
  bool operator() (const pair<int, int>& lhs, const pair<int, int>&rhs) const {
      return lhs.second < rhs.second;
  }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int n : nums) ++m[n];
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q(m.begin(), m.end());
        vector<int> v;
        while (k--) {
            v.push_back(q.top().first);
            q.pop();
        }
        return v;
    }
};