# [611. Valid Triangle Number (Medium)](https://leetcode.com/problems/valid-triangle-number)

Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

**Example 1:**  

```
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
```

**Note:**  

1.  The length of the given array won't exceed 1000.
2.  The integers in the given array are in the range of [0, 1000].

## Solution 1.

The naive solution is of `O(N^3)` time complexity, that is, for each triplet, detect if it can form a triangle. This solution will get TLE.

To optimize it, I first sort `nums` in ascending order. And for each doublet `a` and `b`, use binary search to find the count of numbers greater than `a + b` and less than `a - b (a >= b)`.

```cpp
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
```

## Solution 2.

Same as solution 1, just uses built-in functions `lower_bound` and `upper_bound`.

```cpp
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
        auto left = upper_bound(nums.begin() + j + 1, nums.end(), nums[j] - nums[i]);
        auto right = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]);
        if (right > left) cnt += right - left;
      }
    }
    return cnt;
  }
};
```