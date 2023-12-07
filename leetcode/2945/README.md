# [2945. Find Maximum Non-decreasing Array Length (Hard)](https://leetcode.com/problems/find-maximum-non-decreasing-array-length)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>.</p>

<p>You can perform any number of operations, where each operation involves selecting a <strong>subarray</strong> of the array and replacing it with the <strong>sum</strong> of its elements. For example, if the given array is <code>[1,3,5,6]</code> and you select subarray <code>[3,5]</code> the array will convert to <code>[1,8,6]</code>.</p>

<p>Return <em>the </em><strong><em>maximum</em></strong><em> length of a </em><strong><em>non-decreasing</em></strong><em> array that can be made after applying operations.</em></p>

<p>A <strong>subarray</strong> is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [5,2,2]
<strong>Output:</strong> 1
<strong>Explanation:</strong> This array with length 3 is not non-decreasing.
We have two ways to make the array length two.
First, choosing subarray [2,2] converts the array to [5,4].
Second, choosing subarray [5,2] converts the array to [7,2].
In these two ways the array is not non-decreasing.
And if we choose subarray [5,2,2] and replace it with [9] it becomes non-decreasing. 
So the answer is 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The array is non-decreasing. So the answer is 4.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,3,2,6]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Replacing [3,2] with [5] converts the given array to [4,5,6] that is non-decreasing.
Because the given array is not non-decreasing, the maximum<!-- notionvc: 3447a505-d1ee-4411-8cae-e52162f53a55 --> possible answer is 3.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Binary Search](https://leetcode.com/tag/binary-search), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Stack](https://leetcode.com/tag/stack), [Queue](https://leetcode.com/tag/queue), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack), [Monotonic Queue](https://leetcode.com/tag/monotonic-queue)

**Hints**:
* Let <code>dp[i]</code> be the maximum number of elements in the increasing sequence after processing the first <code>i</code> elements of the original array.
* We have <code>dp[0] = 0</code>. <code>dp[i + 1] >= dp[i]</code> (since if we have the solution for the first <code>i</code> elements, we can always merge the last one of the first <code>i + 1</code> elements which is <code>nums[i]</code> into the solution of the first <code>i</code> elements.
* For <code>i > 0</code>, we want to <code>dp[i] = max(dp[j] + 1)</code> where <code>sum(nums[i - 1] + nums[i - 2] +… + nums[j]) >= v[j]</code> and <code>v[j]</code> is the last element of the solution ending with <code>nums[j - 1]</code>.

## Solution 1.

```
[272,(482,115),925,983] - 3
[171,(282,119,154),952,(569,633)] - 4
[171,282,150,150,952,569,633] - 5
[520,531,(573,65),(426,501),955] - 5
```

Let `dp[i+1]` be the maximum number of elements in the increasing sequence after processing `A[0..i]`.

We have `dp[0] = 0` and `dp[i+1] >= dp[i]`.

```cpp
// OJ: https://leetcode.com/problems/find-maximum-non-decreasing-array-length
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/find-maximum-non-decreasing-array-length/solutions/4329014/java-c-python-dp-binary-search/
class Solution {
public:
    int findMaximumLength(vector<int>& A) {
        int N = A.size();
        vector<int> dp(N + 1), pre(N + 2);
        vector<long long> sum(N + 1);
        for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + A[i];
        for (int i = 0, j = 1; j <= N; ++j) {
           i = max(i, pre[j]);
           dp[j] = dp[i] + 1;
           int k = lower_bound(begin(sum), end(sum), 2 * sum[j] - sum[i]) - begin(sum);
           pre[k] = j;
        }
        return dp[N];
    }
};
```