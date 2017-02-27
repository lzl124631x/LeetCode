class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int N = nums.size();
    stack<int> s;
    vector<int> ans(N, -1);
    for (int i = 0; i < 2 * N; ++i) {
      int n = nums[i % N];
      while (s.size() && nums[s.top()] < n) {
        ans[s.top()] = n;
        s.pop();
      }
      s.push(i % N);
    }
    return ans;
  }
};