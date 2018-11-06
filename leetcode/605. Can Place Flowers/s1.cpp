// OJ: https://leetcode.com/problems/can-place-flowers
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    for (int i = 0; i < flowerbed.size() && n; ++i) {
      if (!flowerbed[i] && (!i || !flowerbed[i - 1])
          && (i == flowerbed.size() - 1 || !flowerbed[i + 1])) {
        --n;
        flowerbed[i] = 1;
      }
    }
    return !n;
  }
};