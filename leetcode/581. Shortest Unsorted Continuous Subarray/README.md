# [581. Shortest Unsorted Continuous Subarray (Easy)](https://leetcode.com/problems/shortest-unsorted-continuous-subarray)

Given an integer array, you need to find one **continuous subarray** that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the **shortest** such subarray and output its length.

**Example 1:**
```
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
```
**Note:**
1. Then length of the input array is in range [1, 10,000].
2. The input array may contain duplicates, so ascending order here means **<=**.

# Solution 1. Insertion Sort
Naive insertion sort. For `nums[i]`, if its insertion position `pos[i]` is not the same as `i`, numbers between `pos[i]` and `i` are unsorted. Keep record of the leftmost `pos[i]` (as `lb`) and rightmost `i` (as `rb`) that `pos[i] != i`. The answer is `rb - lb + 1`.

```cpp
// OJ: https://leetcode.com/problems/shortest-unsorted-continuous-subarray
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    int lb = INT_MAX, rb = INT_MIN;
    for (int i = 1; i < nums.size(); ++i) {
      int val = nums[i], j = i;
      for (; j - 1 >= 0 && nums[j - 1] > val; --j) nums[j] = nums[j - 1];
      nums[j] = val;
      if (j != i) {
        lb = min(lb, j);
        rb = i;
      }
    }
    return lb == INT_MAX ? 0 : rb - lb + 1;
  }
};
```