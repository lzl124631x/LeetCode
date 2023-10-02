# [2740. Find the Value of the Partition (Medium)](https://leetcode.com/problems/find-the-value-of-the-partition)

<p>You are given a <strong>positive</strong> integer array <code>nums</code>.</p>
<p>Partition <code>nums</code> into two arrays,&nbsp;<code>nums1</code> and <code>nums2</code>, such that:</p>
<ul>
	<li>Each element of the array <code>nums</code> belongs to either the array <code>nums1</code> or the array <code>nums2</code>.</li>
	<li>Both arrays are <strong>non-empty</strong>.</li>
	<li>The value of the partition is <strong>minimized</strong>.</li>
</ul>
<p>The value of the partition is <code>|max(nums1) - min(nums2)|</code>.</p>
<p>Here, <code>max(nums1)</code> denotes the maximum element of the array <code>nums1</code>, and <code>min(nums2)</code> denotes the minimum element of the array <code>nums2</code>.</p>
<p>Return <em>the integer denoting the value of such partition</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,2,4]
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can partition the array nums into nums1 = [1,2] and nums2 = [3,4].
- The maximum element of the array nums1 is equal to 2.
- The minimum element of the array nums2 is equal to 3.
The value of the partition is |2 - 3| = 1. 
It can be proven that 1 is the minimum value out of all partitions.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [100,1,10]
<strong>Output:</strong> 9
<strong>Explanation:</strong> We can partition the array nums into nums1 = [10] and nums2 = [100,1].
- The maximum element of the array nums1 is equal to 10.
- The minimum element of the array nums2 is equal to 1.
The value of the partition is |10 - 1| = 9.
It can be proven that 9 is the minimum value out of all partitions.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-the-value-of-the-partition
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1) if we allow sorting the array in place.
class Solution {
public:
    int findValueOfPartition(vector<int>& A) {
        int N = A.size(), ans = INT_MAX;
        sort(begin(A), end(A));
        for (int i = 1; i < N; ++i) {
            ans = min(ans, A[i] - A[i - 1]);
        }
        return ans;
    }
};
```