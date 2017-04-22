// OJ: https://leetcode.com/problems/container-with-most-water
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
  int maxArea(vector<int>& height) {
    int maxVal = min(height[0], height[1]);
    for (int i = 0; i < height.size(); ++i) {
      if (!height[i]) continue;
      for (int j = i + 1 + maxVal / height[i]; j < height.size(); ++j) {
        maxVal = max(maxVal, min(height[i], height[j]) * (j - i));
      }
    }
    return maxVal;
  }
};