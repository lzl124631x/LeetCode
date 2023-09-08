# [2369. Check if There is a Valid Partition For The Array (Medium)](https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>. You have to partition the array into one or more <strong>contiguous</strong> subarrays.</p>
<p>We call a partition of the array <strong>valid</strong> if each of the obtained subarrays satisfies <strong>one</strong> of the following conditions:</p>
<ol>
	<li>The subarray consists of <strong>exactly</strong> <code>2</code> equal elements. For example, the subarray <code>[2,2]</code> is good.</li>
	<li>The subarray consists of <strong>exactly</strong> <code>3</code> equal elements. For example, the subarray <code>[4,4,4]</code> is good.</li>
	<li>The subarray consists of <strong>exactly</strong> <code>3</code> consecutive increasing elements, that is, the difference between adjacent elements is <code>1</code>. For example, the subarray <code>[3,4,5]</code> is good, but the subarray <code>[1,3,5]</code> is not.</li>
</ol>
<p>Return <code>true</code><em> if the array has <strong>at least</strong> one valid partition</em>. Otherwise, return <code>false</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [4,4,4,5,6]
<strong>Output:</strong> true
<strong>Explanation:</strong> The array can be partitioned into the subarrays [4,4] and [4,5,6].
This partition is valid, so we return true.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,1,2]
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no valid partition for this array.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Top-down DP

```cpp
// OJ: https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool validPartition(vector<int>& A) {
        int N = A.size();
        vector<int> memo(N, -1);
        function<bool(int)> dfs = [&](int start) -> bool {
            if (start == N) return true;
            if (memo[start] != -1) return memo[start];
            bool ans = false;
            if (start + 1 < N && A[start + 1] == A[start]) ans = dfs(start + 2);
            if (start + 2 < N &&
                ((A[start + 1] == A[start] && A[start + 2] == A[start])
                || (A[start + 1] == A[start] + 1 && A[start + 2] == A[start] + 2))) ans |= dfs(start + 3);
            return memo[start] = ans;
        };
        return dfs(0);
    }
};
```