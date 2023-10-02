# [1262. Greatest Sum Divisible by Three (Medium)](https://leetcode.com/problems/greatest-sum-divisible-by-three/)

<p>Given an array&nbsp;<code>nums</code>&nbsp;of integers, we need to find the maximum possible sum of elements of the array such that it is divisible by three.</p>

<ol>
</ol>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [3,6,5,1,8]
<strong>Output:</strong> 18
<strong>Explanation:</strong> Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [4]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Since 4 is not divisible by 3, do not pick any number.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4,4]
<strong>Output:</strong> 12
<strong>Explanation:</strong> Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 4 * 10^4</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^4</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Let `dp[i + 1][r]` be the maximum possible sum on the subarray `A[0..i]` where the current sum modulo 3 is equal to `r`.

Initially `dp[0][0] = 0`, `dp[0][1] = dp[0][2] = -INF` meaning they are invalid states.

```
dp[i + 1][j] = max(
                    dp[i][j],                            // if we skip A[i]
                    A[i] + dp[i][(j + 3 - A[i] % 3) % 3] // if we pick A[i]
                  )
```

The result is `dp[N][0]`.

```cpp
// OJ: https://leetcode.com/problems/greatest-sum-divisible-by-three/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxSumDivThree(vector<int>& A) {
        int dp[40001][3] = {}, N = A.size();
        dp[0][1] = dp[0][2] = INT_MIN;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < 3; ++j) dp[i + 1][j] = max(dp[i][j], A[i] + dp[i][(j + 3 - A[i] % 3) % 3]);
        }
        return dp[N][0];
    }
};
```

## Solution 2. DP with Space Optimization

```cpp
// OJ: https://leetcode.com/problems/greatest-sum-divisible-by-three/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxSumDivThree(vector<int>& A) {
        array<int, 3> dp = { 0, INT_MIN, INT_MIN }, tmp;
        for (int n : A) {
            tmp = dp;
            for (int j = 0; j < 3; ++j) dp[j] = max(tmp[j], n + tmp[(j + 3 - n % 3) % 3]);
        }
        return dp[0];
    }
};
```