# [525. Contiguous Array (Medium)](https://leetcode.com/problems/contiguous-array)

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

**Example 1:**  

```
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
```

**Example 2:**  

```
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
```

**Note:** The length of the given binary array will not exceed 50,000.

## Solution 1. 

Let `dp[i + 1] :=  the max length of contiguous array ending at index i`.

Given `start = i - dp[i]`, nums from `nums[start]` to `nums[i - 1]` forms a contiguous array.

If `nums[start - 1] != nums[i]`, `dp[i + 1]` can be constructed using `dp[i] + 2 + dp[start - 1]`. The DP array saves computation in this case, but if `nums[start - 1] == nums[i]` I have to do linear search.

The search direction should be rightward. Assume `nums[start - 1] = nums[i] = 1`, If there are two zeroes can help form a longer contiguous array at the left of `nums[start - 1]`, it's contradicts with the fact that `nums[start] ... nums[i - 1]` is the longest contiguous array ending at `i - 1` since `nums[start - 2] ... nums[i - 1]` is contiguous and even longer.

```
        v     v
... 0 0 1 ... 1
```

When search rightward from `start`, use `int diff = 0` to denote the difference between `0` and `1`. If `nums[start] == nums[i]`, increment `diff`; otherwise decrement `diff`. When `diff == 1`, breaks the iteration because it means one more number same as `nums[i]` are popped.

```cpp
// OJ: https://leetcode.com/problems/contiguous-array
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    vector<int> dp(nums.size() + 1, 0);
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int start = i - dp[i];
      if (start > 0 && nums[start - 1] != nums[i]) {
        dp[i + 1] = dp[i] + 2 + dp[start - 1];
      } else {
        for (int diff = 0; start <= i && diff != 1; ++start) {
          if (nums[start] == nums[i]) diff++;
          else diff--;
        }
        dp[i + 1] = i - start + 1;
      }
      ans = max(ans, dp[i + 1]);
    }
    return ans;
  }
};
```

## Solution 2.

Replace all `0`s with `-1`s, and now the question becomes finding the longest contiguous array that sums up to 0. 

Use `unordered_map<int, int> m` to store the mapping between the running sum and the index of its first occurrence. `m` initially holds `{ 0, -1 }` which means a pseudo running sum `0` at index `-1`.

For each running sum,
* if it's the first occurrence, store the mapping - `m[sum] = i`
* otherwise, update `ans` with `max(ans, i - m[sum])`.

```cpp
// OJ: https://leetcode.com/problems/contiguous-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/79906/easy-java-o-n-solution-presum-hashmap/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int &n : nums) if (!n) n = -1;
        unordered_map<int, int> m {{ 0, -1 }};
        int ans = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (m.find(sum) == m.end()) m[sum] = i;
            else ans = max(ans, i - m[sum]);
        }
        return ans;
    }
};
```