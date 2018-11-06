// OJ: https://leetcode.com/problems/valid-triangle-number
// Author: github.com/lzl124631x
// Time: O(N^2logN)
// Space: O(1)
class Solution {
public:
  int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int cnt = 0, N = nums.size();
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        int lb = nums[j] - nums[i], rb = nums[i] + nums[j];
        int L = j + 1, R = N - 1, left = 0;
        while (L <= R) {
          int M = (L + R) / 2;
          if (nums[M] > lb) R = M - 1;
          else L = M + 1;
        }
        left = L;
        L = j + 1, R = N - 1;
        while (L <= R) {
          int M = (L + R) / 2;
          if (nums[M] >= rb) R = M - 1;
          else L = M + 1;
        }
        if (R >= left) cnt += R - left + 1;
      }
    }
    return cnt;
  }
};