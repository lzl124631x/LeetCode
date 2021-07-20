# [795. Number of Subarrays with Bounded Maximum (Medium)](https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/)

<p>Given an integer array <code>nums</code> and two integers <code>left</code> and <code>right</code>, return <em>the number of contiguous non-empty <strong>subarrays</strong> such that the value of the maximum array element in that subarray is in the range </em><code>[left, right]</code>.</p>

<p>The test cases are generated so that the answer will fit in a <strong>32-bit</strong> integer.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,1,4,3], left = 2, right = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are three subarrays that meet the requirements: [2], [2, 1], [3].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,9,2,5,6], left = 2, right = 8
<strong>Output:</strong> 7
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= left &lt;= right &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [DoorDash](https://leetcode.com/company/doordash)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

## Solution 1. Two Pointers

For simplicity, let's map `A[i]` in the following way:

* `A[i] = 0` if `A[i] < left`
* `A[i] = 1` if `left <= A[i] <= right`
* `A[i] = 2` if `A[i] > right`

Consider `A = [2 0 1 1 0 0 0 1 2 0 1 0 1]`. The subarray can't have any `2`. So `2` separates `A` into several segments and we just need to look within each segment.

For the first segment, `[0 1 1 0 0 0 1]`, let's consider the subarrays from left to right one by one:

* `[0]` is not a valid subarray
* `[0 1]` is a valid subarray. And we can also form a valid subarray `[1]` by just using the second element.
* `[0 1 1]` is a valid subarray. And its subarrays ending with the last `1` are also valid -- `[1 1]` and `[1]`.
* `[0 1 1 0]` is a valid subarray. And its subarrays ending with the last `1` are also valid -- `[1 1 0]`, `[1, 0]`.
* ...

We can see that we can scan each segment from left to right, and just log the index of last `1` as `last`. For the current element `A[i]`, there are `last - start + 1` subarrays we can form starting from `start` where `start` is the index of the first element of this segment.

```cpp
// OJ: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int left, int right) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] > right) continue;
            int last = -1, start = i;
            for (; i < N && A[i] <= right; ++i) {
                if (A[i] >= left && A[i] <= right) last = i;
                if (last != -1) ans += last - start + 1;
            }
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int left, int right) {
        int N = A.size(), ans = 0, start = -1, end = -1;
        for (int i = 0; i < N; ++i) {
            if (A[i] > right) {
                start = end = i;
                continue;
            }
            if (A[i] >= left) end = i;
            ans += (end - start);
        }
        return ans;
    }
};
```