# [1186. Maximum Subarray Sum with One Deletion (Medium)](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/)

<p>Given an array of integers, return the maximum sum for a <strong>non-empty</strong>&nbsp;subarray (contiguous elements) with at most one element deletion.&nbsp;In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the&nbsp;sum of the remaining elements is maximum possible.</p>

<p>Note that the subarray needs to be <strong>non-empty</strong> after deleting one element.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,-2,0,3]
<strong>Output:</strong> 4
<strong>Explanation: </strong>Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,-2,-2,3]
<strong>Output:</strong> 3
<strong>Explanation: </strong>We just choose [3] and it's the maximum sum.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [-1,-1,-1,-1]
<strong>Output:</strong> -1
<strong>Explanation:</strong>&nbsp;The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^5</code></li>
	<li><code>-10^4 &lt;= arr[i] &lt;= 10^4</code></li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Let:
* `dp[i + 1][0]` be the maximum sum of subarrays that end at `A[i]` and don't without deletion.
* `dp[i + 1][1]` be the maximum sum of subarrays that end at `A[i]` and have one deletion.

For `dp[i + 1][0]`, we have two options:
1. Only pick `A[i]` -- `A[i]`.
1. Append `A[i]` to previous best result without deletion -- `dp[i][0] + A[i]`
So `dp[i + 1][0] = max(A[i], dp[i][0] + A[i])`.

For `dp[i + 1][1]`, we have two options:
1. treat `A[i]` as deleted and use the previous best result without deletion -- `dp[i][0]`.
1. Append `A[i]` to the previous best result with deletion -- `dp[i][1] + A[i]`.

So in sum:

```
dp[i + 1][0] = max(A[i], dp[i][0] + A[i])
dp[i + 1][1] = max(dp[i][0], dp[i][1] + A[i])

dp[0][0] = dp[0][1] = -INF
```

We treat invalid states as `-INF` so that we can ignore them when comparing `max`.

```cpp
// OJ: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maximumSum(vector<int>& A) {
        int N = A.size(), ans = INT_MIN;
        auto dp = vector<vector<int>>(N + 1, vector<int>(2));
        dp[0][0] = dp[0][1] = INT_MIN;
        for (int i = 0; i < N; ++i) {
            dp[i + 1][0] = max(A[i], dp[i][0] == INT_MIN ? INT_MIN : (dp[i][0] + A[i]));
            dp[i + 1][1] = max(dp[i][1] == INT_MIN ? INT_MIN : (A[i] + dp[i][1]), dp[i][0]);
            ans = max({ ans, dp[i + 1][0], dp[i + 1][1] });
        }
        return ans;
    }
};
```

## Solution 2. DP with Space Optimization

Since `dp[i + 1][x]` is only dependent on `dp[i][y]`, we can reduce the `dp` array from `N * 2` to `2 * 2`.

```cpp
// OJ: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumSum(vector<int>& A) {
        int N = A.size(), ans = INT_MIN;
        auto dp = vector<vector<int>>(2, vector<int>(2));
        dp[0][0] = dp[0][1] = INT_MIN;
        for (int i = 0; i < N; ++i) {
            dp[(i + 1) % 2][0] = max(A[i], dp[i % 2][0] == INT_MIN ? INT_MIN : (dp[i % 2][0] + A[i]));
            dp[(i + 1) % 2][1] = max(dp[i % 2][1] == INT_MIN ? INT_MIN : (A[i] + dp[i % 2][1]), dp[i % 2][0]);
            ans = max({ ans, dp[(i + 1) % 2][0], dp[(i + 1) % 2][1] });
        }
        return ans;
    }
};
```