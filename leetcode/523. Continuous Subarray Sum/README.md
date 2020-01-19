# [523. Continuous Subarray Sum (Medium)](https://leetcode.com/problems/continuous-subarray-sum/)

<p>Given a list of <b>non-negative</b> numbers and a target <b>integer</b> k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to a multiple of <b>k</b>, that is, sums up to n*k where n is also an <b>integer</b>.</p>

<p>&nbsp;</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> [23, 2, 4, 6, 7],  k=6
<b>Output:</b> True
<b>Explanation:</b> Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> [23, 2, 6, 4, 7],  k=6
<b>Output:</b> True
<b>Explanation:</b> Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ol>
	<li>The length of the array won't exceed 10,000.</li>
	<li>You may assume the sum of all the numbers is in the range of a signed 32-bit integer.</li>
</ol>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Subarray Sum Equals K (Medium)](https://leetcode.com/problems/subarray-sum-equals-k/)

## Solution 1. Brute force

```cpp
// OJ: https://leetcode.com/problems/continuous-subarray-sum
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    for (int i = 0; i < nums.size(); ++i) {
      int sum = nums[i];
      for (int j = i + 1; j < nums.size(); ++j) {
        sum += nums[j];
        if ((!k && !sum) || (k && sum % k == 0)) return true;
      }
    }
    return false;
  }
};
```

## Solution 2. Brute force

```cpp
// OJ: https://leetcode.com/problems/continuous-subarray-sum
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        nums[j] += nums[i];
        if (k) nums[j] %= k;
        if (!nums[j]) return true;
      }
    }
    return false;
  }
};
```

## Solution 3. Map from mod value to index

Let `sum(i, j) = A[i] + ... + A[j - 1]`, `sum(i, j) = sum(0, j) - sum(0, i)` so `sum(i, j) % k = sum(0, j) % k - sum(0, i) % k`.

If `sum(i, j) % k == 0`, then `sum(0, j) % k` must be equal to `sum(0, i) % k`.

So we can keep track of the map from `sum(0, i) % k` to the index `i`. If the same mod value appears twice, we take a look at the difference between the corresponding indexes, if the difference is greater than `1`, we've found the subarray.

```cpp
// OJ: https://leetcode.com/problems/continuous-subarray-sum
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(K)
class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> m {{ 0, -1 }};
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (k) sum %= k;
      if (m.count(sum)) {
        if (m[sum] < i - 1) return true;
      } else m[sum] = i;
    }
    return false;
  }
};
```

## Solution 4. Set of mod values

In solution 3, we keep track of the map from mod value to index because we need to check whether the difference between the indexes are greater than 1.

In other words, if we found the same mod value appeared in adjacent elements, we can't take that as a valid subarray.

One way to get around this issue is to delay the recording of the previous mod into map/set by one step such that when we find the same mod value appearing twice, there must be at least one cell gap between them.

```cpp
// OJ: https://leetcode.com/problems/continuous-subarray-sum
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(K)
// Ref: https://discuss.leetcode.com/topic/80892/concise-c-solution-use-set-instead-of-map
class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_set<int> s;
    int sum = 0, prev = 0;
    for (int n : nums) {
      sum += n;
      if (k) sum %= k;
      if (s.count(sum)) return true;
      s.insert(prev);
      prev = sum;
    }
    return false;
  }
};
```