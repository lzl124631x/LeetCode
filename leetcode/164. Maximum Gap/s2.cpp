// OJ: https://leetcode.com/problems/maximum-gap
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/articles/maximum-gap
class Solution {
public:
  int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    int maxVal = *max_element(nums.begin(), nums.end());
    vector<int> aux(nums.size());
    for (int exp = 1, radix = 10; maxVal / exp > 0; exp *= radix) {
      vector<int> cnt(radix, 0);
      for (int n : nums) cnt[(n / exp) % radix]++;
      for (int i = 1; i < cnt.size(); ++i) cnt[i] += cnt[i - 1];
      for (int i = nums.size() - 1; i >= 0; --i) aux[--cnt[(nums[i] / exp) % radix]] = nums[i];
      nums = aux;
    }
    int ans = 0;
    for (int i = 1; i < nums.size(); ++i) ans = max(ans, nums[i] - nums[i - 1]);
    return ans;
  }
};