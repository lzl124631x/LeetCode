# [410. Split Array Largest Sum (Hard)](https://leetcode.com/problems/split-array-largest-sum/)

<p>Given an array <code>nums</code> which consists of non-negative integers and an integer <code>m</code>, you can split the array into <code>m</code> non-empty continuous subarrays.</p>

<p>Write an algorithm to minimize the largest sum among these <code>m</code> subarrays.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [7,2,5,10,8], m = 2
<strong>Output:</strong> 18
<strong>Explanation:</strong>
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4,5], m = 2
<strong>Output:</strong> 9
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,4,4], m = 3
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= m &lt;= min(50, nums.length)</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [tiktok](https://leetcode.com/company/tiktok), [ByteDance](https://leetcode.com/company/bytedance)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Capacity To Ship Packages Within D Days (Medium)](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)
* [Divide Chocolate (Hard)](https://leetcode.com/problems/divide-chocolate/)
* [Subsequence of Size K With the Largest Even Sum (Medium)](https://leetcode.com/problems/subsequence-of-size-k-with-the-largest-even-sum/)

## Solution 1. Bottom-up DP

Let `dp[i][j+1]` be the answer to the subproblem with `i` subarrays within `A[0..j]`.

Let `sum[i][j]` be the sum of numbers in `A[i..j]`.

For `dp[i][j+1]`, we can try using `A[k..j]` as the last subarray. This last subarray has sum `sum[k][j]`, and the `A[0..(k-1)]` elements have minimum split sum `dp[i-1][k]`. So, if we try different `i - 1 <= k <= j`, `dp[i][j]` is the minimum of `max(dp[i-1][k], sum[k][j])`.

```
dp[i][j+1] = min( max(dp[i-1][k], sum[k][j]) | i - 1 <= k <= j )
```

The trivial case is as follows.

```
dp[1][j+1] = sum[0][j]
```

We can compute `sum` values on the fly instead of precomputing all `sum` values which takes `O(N^2)` space.

```cpp
// OJ: https://leetcode.com/problems/split-array-largest-sum/
// Author: github.com/lzl124631x
// Time: O(N^2 * M)
// Space: O(NM)
class Solution {
public:
    int splitArray(vector<int>& A, int m) {
        int N = A.size();
        vector<vector<int>> dp(m + 1, vector<int>(N + 1, INT_MAX));
        dp[1][0] = 0;
        for (int i = 0; i < N; ++i) dp[1][i + 1] = dp[1][i] + A[i];
        for (int i = 2; i <= m; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = j, sum = 0; k >= i - 1; --k) {
                    sum += A[k];
                    dp[i][j + 1] = min(dp[i][j + 1], max(sum, dp[i - 1][k]));
                    if (sum >= dp[i - 1][k]) break; // If `sum` is already no less than `dp[i-1][k]`, going left won't get smaller split sum. Break directly
                }
            }
        }
        return dp[m][N];
    }
};
```

## Solution 2. DP + Space Optimization

Given the `dp` dependency, we can just use 1D `dp` array.

```cpp
// OJ: https://leetcode.com/problems/split-array-largest-sum/
// Author: github.com/lzl124631x
// Time: O(N^2 * M)
// Space: O(N)
class Solution {
public:
    int splitArray(vector<int>& A, int m) {
        int N = A.size();
        vector<int> dp(N + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < N; ++i) dp[i + 1] = dp[i] + A[i];
        for (int i = 2; i <= m; ++i) {
            for (int j = N - 1; j >= 0; --j) {
                for (int k = j, sum = 0; k >= i - 1; --k) {
                    sum += A[k];
                    dp[j + 1] = min(dp[j + 1], max(sum, dp[k]));
                    if (sum >= dp[k]) break; // If `sum` is already no less than `dp[i-1][k]`, going left won't get smaller split sum. Break directly
                }
            }
        }
        return dp[N];
    }
};
```

## Solution 3. Binary Answer

The answer is between the maximum element and the sum of all the elements.

Let `maxSum` be the minimum subarray sum allowed. The greater this `maxSum` is, the more likely we can split `A` into `m` parts with `maxSum` as the maximum subarray sum -- let's call this **valid**.

There is a breakpoint that if `maxSum` is less than this value, we have to split `A` into more than `m` parts -- let's call this **invalid**.

We can use binary search to find the minimum valid `maxSum`.

```cpp
// OJ: https://leetcode.com/problems/split-array-largest-sum/
// Author: github.com/lzl124631x
// Time: O(N * log(S)) where S is sum of nums.
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/61324/clear-explanation-8ms-binary-search-java
class Solution {
public:
    int splitArray(vector<int>& A, int m) {
        long sum = accumulate(begin(A), end(A), 0L);
        if (m == 1) return sum;
        long L = *max_element(begin(A), end(A)), R = sum, N = A.size();
        auto valid = [&](int maxSum) {
            int cnt = 1, i = 0 ;
            for (int sum = 0; i < N && cnt <= m; ++i) {
                sum += A[i];
                if (sum > maxSum) {
                    sum = A[i];
                    ++cnt;
                }
            }
            return i == N && cnt <= m;
        };
        while (L <= R) {
            long M = L + (R - L) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};
```