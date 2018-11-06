// OJ: https://leetcode.com/problems/maximum-gap
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://discuss.leetcode.com/topic/5999/bucket-sort-java-solution-with-explanation-o-n-time-and-space
class Solution {
public:
  int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());
    int N = nums.size(), gap = ceil((double)(maxVal - minVal) / (N - 1));
    vector<int> mins(N - 1, INT_MAX), maxes(N - 1, INT_MIN);
    for (int n : nums) {
      if (n == minVal || n == maxVal) continue;
      int i = (n - minVal) / gap;
      mins[i] = min(mins[i], n);
      maxes[i] = max(maxes[i], n);
    }
    int ans = INT_MIN, prev = minVal;
    for (int i = 0; i < N - 1; ++i) {
      if (mins[i] == INT_MAX) continue;
      ans = max(ans, mins[i] - prev);
      prev = maxes[i];
    }
    return max(ans, maxVal - prev);
  }
};