// OJ: https://leetcode.com/problems/container-with-most-water
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/3462/yet-another-way-to-see-what-happens-in-the-o-n-algorithm
class Solution {
public:
  int maxArea(vector<int>& height) {
    int maxVal = 0, L = 0, R = height.size() - 1;
    while (L < R) {
      maxVal = max(maxVal, (R - L) * min(height[L], height[R]));
      if (height[L] < height[R]) L++;
      else R--;
    }
    return maxVal;
  }
};