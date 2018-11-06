// OJ: https://leetcode.com/problems/beautiful-arrangement
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
private:
  int dfs(vector<int> &nums, int pos) {
    if (pos == nums.size()) return 1;
    int cnt = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (!nums[i] || (nums[i] % (pos + 1) && (pos + 1) % nums[i])) continue;
      int val = nums[i];
      nums[i] = 0;
      cnt += dfs(nums, pos + 1);
      nums[i] = val;
    }
    return cnt;
  }
public:
  int countArrangement(int N) {
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) nums[i] = i + 1;
    return dfs(nums, 0);
  }
};