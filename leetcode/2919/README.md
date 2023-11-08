# [2919. Minimum Increment Operations to Make Array Beautiful (Medium)](https://leetcode.com/problems/minimum-increment-operations-to-make-array-beautiful)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> having length <code>n</code>, and an integer <code>k</code>.</p>

<p>You can perform the following <strong>increment</strong> operation <strong>any</strong> number of times (<strong>including zero</strong>):</p>

<ul>
	<li>Choose an index <code>i</code> in the range <code>[0, n - 1]</code>, and increase <code>nums[i]</code> by <code>1</code>.</li>
</ul>

<p>An array is considered <strong>beautiful</strong> if, for any <strong>subarray</strong> with a size of <code>3</code> or <strong>more</strong>, its <strong>maximum</strong> element is <strong>greater than or equal</strong> to <code>k</code>.</p>

<p>Return <em>an integer denoting the <strong>minimum</strong> number of increment operations needed to make </em><code>nums</code><em> <strong>beautiful</strong>.</em></p>

<p>A subarray is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,3,0,0,2], k = 4
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can perform the following increment operations to make nums beautiful:
Choose index i = 1 and increase nums[1] by 1 -&gt; [2,4,0,0,2].
Choose index i = 4 and increase nums[4] by 1 -&gt; [2,4,0,0,3].
Choose index i = 4 and increase nums[4] by 1 -&gt; [2,4,0,0,4].
The subarrays with a size of 3 or more are: [2,4,0], [4,0,0], [0,0,4], [2,4,0,0], [4,0,0,4], [2,4,0,0,4].
In all the subarrays, the maximum element is equal to k = 4, so nums is now beautiful.
It can be shown that nums cannot be made beautiful with fewer than 3 increment operations.
Hence, the answer is 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1,3,3], k = 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can perform the following increment operations to make nums beautiful:
Choose index i = 2 and increase nums[2] by 1 -&gt; [0,1,4,3].
Choose index i = 2 and increase nums[2] by 1 -&gt; [0,1,5,3].
The subarrays with a size of 3 or more are: [0,1,5], [1,5,3], [0,1,5,3].
In all the subarrays, the maximum element is equal to k = 5, so nums is now beautiful.
It can be shown that nums cannot be made beautiful with fewer than 2 increment operations.
Hence, the answer is 2.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,2], k = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> The only subarray with a size of 3 or more in this example is [1,1,2].
The maximum element, 2, is already greater than k = 1, so we don&#39;t need any increment operation.
Hence, the answer is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming)

**Hints**:
* There needs to be at least one value among <code>3</code> consecutive values in the array that is greater than or equal to <code>k</code>.
* The problem can be solved using dynamic programming.
* Let <code>dp[i]</code> be the minimum number of increment operations required to make the subarray consisting of the first <code>i</code> values beautiful, while also having the value at <code>nums[i] >= k</code>.
* <code>dp[0] = max(0, k - nums[0])</code>, <code>dp[1] = max(0, k - nums[1])</code>, and <code>dp[2] = max(0, k - nums[2])</code>.
* <code>dp[i] = max(0, k - nums[i]) + min(dp[i - 1], dp[i - 2], dp[i - 3])</code> for <code>i</code> in the range <code>[3, n - 1]</code>.
* The answer to the problem is <code>min(dp[n - 1], dp[n - 2], dp[n - 3])</code>.

## Solution 1.

Let `dp[i+1]` be the minimum number of operations needed to make `A[0..i]` beautiful with the last operation applied onto `A[i]`. The answer is `min(dp[N-1], dp[N-2], dp[N-3])`.

When we apply an operation on `A[i]` with `max(k - A[i], 0)` operations, the previous operation must be applied on one of `A[i-1]`, `A[i-2]` and `A[i-3]`. We can greedily pick the minimum of `dp[i-1], dp[i-2], dp[i-3]`.

```
dp[0] = 0
dp[i+1] = max(k - n, 0)       // # of operations needed on A[i]
            + min({a, b, c})  // min # of operations needed for the previous 3 states
```

```cpp
// OJ: https://leetcode.com/problems/minimum-increment-operations-to-make-array-beautiful
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    long long minIncrementOperations(vector<int>& A, int k) {
        long long a = 0, b = LLONG_MAX, c = LLONG_MAX;
        for (int n : A){
            long long x = max(k - n, 0) + min({a, b, c});
            c = b;
            b = a;
            a = x;
        }
        return min({a, b, c});
    }
};
```

## Discussion

https://leetcode.com/problems/minimum-increment-operations-to-make-array-beautiful/solutions/4220728/c-iterative-dp-o-n-time-o-1-space/