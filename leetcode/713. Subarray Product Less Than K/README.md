# [713. Subarray Product Less Than K (Medium)](https://leetcode.com/problems/subarray-product-less-than-k/)

<p>Your are given an array of positive integers <code>nums</code>.</p>
<p>Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than <code>k</code>.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> nums = [10, 5, 2, 6], k = 100
<b>Output:</b> 8
<b>Explanation:</b> The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
</pre>
<p></p>

<p><b>Note:</b>
</p><li><code>0 &lt; nums.length &lt;= 50000</code>.</li>
<li><code>0 &lt; nums[i] &lt; 1000</code>.</li>
<li><code>0 &lt;= k &lt; 10^6</code>.</li>
<p></p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Maximum Product Subarray (Medium)](https://leetcode.com/problems/maximum-product-subarray/)
* [Maximum Size Subarray Sum Equals k (Medium)](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/)
* [Subarray Sum Equals K (Medium)](https://leetcode.com/problems/subarray-sum-equals-k/)
* [Two Sum Less Than K (Easy)](https://leetcode.com/problems/two-sum-less-than-k/)

## Solution 1. Sliding Window

```cpp
// OJ: https://leetcode.com/problems/subarray-product-less-than-k/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& A, int k) {
        if (k == 0) return 0;
        int N = A.size(), i = 0, j = 0, p = 1, ans = 0;
        while (j < N) {
            p *= A[j++];
            while (i < j && p >= k) p /= A[i++];
            ans += j - i;
        }
        return ans;
    }
};
```