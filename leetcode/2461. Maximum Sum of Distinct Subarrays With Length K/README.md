# [2461. Maximum Sum of Distinct Subarrays With Length K (Medium)](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k)

<p>You are given an integer array <code>nums</code> and an integer <code>k</code>. Find the maximum subarray sum of all the subarrays of <code>nums</code> that meet the following conditions:</p>
<ul>
	<li>The length of the subarray is <code>k</code>, and</li>
	<li>All the elements of the subarray are <strong>distinct</strong>.</li>
</ul>
<p>Return <em>the maximum subarray sum of all the subarrays that meet the conditions</em><em>.</em> If no subarray meets the conditions, return <code>0</code>.</p>
<p><em>A <strong>subarray</strong> is a contiguous non-empty sequence of elements within an array.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,5,4,2,9,9,9], k = 3
<strong>Output:</strong> 15
<strong>Explanation:</strong> The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [4,4,4], k = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Max Consecutive Ones III (Medium)](https://leetcode.com/problems/max-consecutive-ones-iii/)
* [Longest Nice Subarray (Medium)](https://leetcode.com/problems/longest-nice-subarray/)
* [Optimal Partition of String (Medium)](https://leetcode.com/problems/optimal-partition-of-string/)
* [Count the Number of Good Subarrays (Medium)](https://leetcode.com/problems/count-the-number-of-good-subarrays/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(K)
class Solution {
public:
    long long maximumSubarraySum(vector<int>& A, int k) {
        unordered_map<int, int> cnt;
        long long sum = 0, N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            sum += A[i];
            cnt[A[i]]++;
            if (i - k >= 0) {
                sum -= A[i - k];
                if (--cnt[A[i - k]] == 0) cnt.erase(A[i - k]);
            }
            if (cnt.size() == k) ans = max(ans, sum);
        }
        return ans;
    }
};
```