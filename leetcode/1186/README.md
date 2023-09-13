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
* `dp[i][0]` be the maximum sum of subarrays that end at `A[i]` and don't without deletion.
* `dp[i][1]` be the maximum sum of subarrays that end at `A[i]` and have one deletion.

For `dp[i][0]`, we have two options:
1. Only pick `A[i]` -- `A[i]`.
1. Append `A[i]` to previous best result without deletion -- `dp[i - 1][0] + A[i]`
So `dp[i][0] = max(A[i], dp[i - 1][0] + A[i])`.

For `dp[i][1]`, we have two options:
1. treat `A[i]` as deleted and use the previous best result without deletion -- `dp[i - 1][0]`.
1. Append `A[i]` to the previous best result with deletion -- `dp[i - 1][1] + A[i]`.

So in sum:

```
dp[i][0] = max(A[i], dp[i - 1][0] + A[i])
dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + A[i])
    where i >= 1

dp[0][0] = A[0]
dp[0][1] = -INF
```

Note that in implementation `dp[0][0]` can be set as `0` since it's only used in `A[1] + dp[0][1]` and thus setting it to `0` safely ignores it.

```cpp
// OJ: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maximumSum(vector<int>& A) {
        int N = A.size(), ans = A[0];
        auto dp = vector<vector<int>>(N, vector<int>(2));
        dp[0][0] = A[0];
        for (int i = 1; i < N; ++i) {
            dp[i][0] = max(A[i], dp[i - 1][0] + A[i]);
            dp[i][1] = max(A[i] + dp[i - 1][1], dp[i - 1][0]);
            ans = max({ ans, dp[i][0], dp[i][1] });
        }
        return ans;
    }
};
```

## Solution 2. DP with Space Optimization

Since `dp[i][x]` is only dependent on `dp[i - 1][y]`, we can reduce the `dp` array from `N * 2` to `2 * 2`.

```cpp
// OJ: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumSum(vector<int>& A) {
        int N = A.size(), ans = A[0];
        int pick = A[0], skip = 0;
        for (int i = 1; i < N; ++i) {
            int p = max(A[i], pick + A[i]), s = max(A[i] + skip, pick);
            pick = p;
            skip = s;
            ans = max({ ans, p, s });
        }
        return ans;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/discuss/377397/Intuitive-Java-Solution-With-Explanation
class Solution {
public:
    int maximumSum(vector<int>& A) {
        int N = A.size(), ans = A[0];
        vector<int> maxEndHere(N), maxStartHere(N);
        maxEndHere[0] = A[0];
        for (int i = 1; i < N; ++i) {
            maxEndHere[i] = max(A[i], maxEndHere[i - 1] + A[i]);
            ans = max(ans, maxEndHere[i]);
        }
        maxStartHere[N - 1] = A[N - 1];
        for (int i = N - 2; i >= 0; --i) maxStartHere[i] = max(A[i], maxStartHere[i + 1] + A[i]);
        for (int i = 1; i < N - 1; ++i) ans = max(ans, maxEndHere[i - 1] + maxStartHere[i + 1]);
        return ans;
    }
};
```