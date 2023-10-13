# [1458. Max Dot Product of Two Subsequences (Hard)](https://leetcode.com/problems/max-dot-product-of-two-subsequences)

<p>Given two arrays <code>nums1</code>&nbsp;and <code><font face="monospace">nums2</font></code><font face="monospace">.</font></p>

<p>Return the maximum dot product&nbsp;between&nbsp;<strong>non-empty</strong> subsequences of nums1 and nums2 with the same length.</p>

<p>A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie,&nbsp;<code>[2,3,5]</code>&nbsp;is a subsequence of&nbsp;<code>[1,2,3,4,5]</code>&nbsp;while <code>[1,5,3]</code>&nbsp;is not).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [2,1,-2,5], nums2 = [3,0,-6]
<strong>Output:</strong> 18
<strong>Explanation:</strong> Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [3,-2], nums2 = [2,-6,7]
<strong>Output:</strong> 21
<strong>Explanation:</strong> Take subsequence [3] from nums1 and subsequence [7] from nums2.
Their dot product is (3*7) = 21.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [-1,-1], nums2 = [1,1]
<strong>Output:</strong> -1
<strong>Explanation: </strong>Take subsequence [-1] from nums1 and subsequence [1] from nums2.
Their dot product is -1.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 500</code></li>
	<li><code>-1000 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
</ul>


**Companies**:
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming)

**Hints**:
* Use dynamic programming, define DP[i][j] as the maximum dot product of two subsequences starting in the position i of nums1 and position j of nums2.

## Solution 1. DP

Let `dp[i + 1][j + 1]` be the answer to the subproblem on `A[0..i]` and `B[0..j]`.

For `dp[0][i]` and `dp[i][0]`, they mean that either `A` or `B` is empty array. Since the question is asking for **non-empty** subsequences, they are not valid cases, so we should regard them as `-INF`.

For `dp[i + 1][j + 1]`, we have three choices:

* We include `A[i]` and `B[j]` in the subsequences. We get `max(0, dp[i][j]) + A[i] * B[j]`.
* We ignore `A[i]` and reuse the result of `dp[i][j + 1]`.
* We ignore `B[j]` and reuse the result of `dp[i + 1][j]`.

```
// For 0 <= i < M, 0 <= j < N
dp[i + 1][j + 1] = max(
                        max(0, dp[i][j]) + A[i] * B[j],   // If we include A[i] and B[j] in the subsequences
                        dp[i][j + 1],                     // If we don't include A[i] in the subsequence
                        dp[i + 1][j]                      // If we don't include B[j] in the subsequence
                      )

// For 0 <= j <= N, 0 <= i <= M
dp[0][j] = dp[i][0] = -INF
```

```cpp
// OJ: https://leetcode.com/problems/max-dot-product-of-two-subsequences/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int maxDotProduct(vector<int>& A, vector<int>& B) {
        int M = A.size(), N = B.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, INT_MIN));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i + 1][j + 1] = max({ max(0, dp[i][j]) + A[i] * B[j], dp[i + 1][j], dp[i][j + 1] });
            }
        }
        return dp[M][N];
    }
};
```

## Solution 2. DP with Space Optimization

Since `dp[i + 1][j + 1]` only depends on `dp[i][j]`, `dp[i + 1][j]` and `dp[i][j + 1]`, we can reduce the size of the `dp` array from `M * N` to `2 * N`.

```cpp
// OJ: https://leetcode.com/problems/max-dot-product-of-two-subsequences
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int maxDotProduct(vector<int>& A, vector<int>& B) {
        int M = A.size(), N = B.size();
        if (N > M) swap(A, B), swap(M, N);
        vector<int> dp(N + 1, INT_MIN);
        for (int i = 0; i < M; ++i) {
            vector<int> next(N + 1, INT_MIN);
            for (int j = 0; j < N; ++j) {
                next[j + 1] = max({A[i] * B[j] + max(0, dp[j]), dp[j + 1], next[j]});
            }
            swap(dp, next);
        }
        return dp[N];
    }
};
```

Or further reduce the space to `1 * N`.

```cpp
// OJ: https://leetcode.com/problems/max-dot-product-of-two-subsequences/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int maxDotProduct(vector<int>& A, vector<int>& B) {
        int M = A.size(), N = B.size();
        if (N > M) swap(A, B), swap(M, N);
        vector<int> dp(N + 1, INT_MIN);
        for (int i = 0; i < M; ++i) {
            int prev = INT_MIN;
            for (int j = 0; j < N; ++j) {
                int cur = dp[j + 1];
                dp[j + 1] = max({A[i] * B[j] + max(0, prev), dp[j + 1], dp[j]});
                prev = cur;
            }
        }
        return dp[N];
    }
};
```