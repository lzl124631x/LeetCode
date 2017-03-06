// Author: github.com/lzl124631x
// Time: O(k + (N - k)logk)
// Space: O(k)
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int n : nums) {
      if (q.size() < k) q.push(n);
      else if (q.top() < n) {
        q.pop();
        q.push(n);
      }
    }
    return q.top();
  }
};