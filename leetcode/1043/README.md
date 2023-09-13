# [1043. Partition Array for Maximum Sum (Medium)](https://leetcode.com/problems/partition-array-for-maximum-sum/)

<p>Given an integer array <code>arr</code>, partition the array into (contiguous) subarrays of length <strong>at most</strong> <code>k</code>. After partitioning, each subarray has their values changed to become the maximum value of that subarray.</p>

<p>Return <em>the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a <strong>32-bit</strong> integer.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,15,7,9,2,5,10], k = 3
<strong>Output:</strong> 84
<strong>Explanation:</strong> arr becomes [15,15,15,9,10,10,10]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
<strong>Output:</strong> 83
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [1], k = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 500</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= arr.length</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Bottom-up DP

Let `dp[i + 1]` be the answer to the subproblem on `A[0..i]`.

At each `dp[i + 1]`, we can let `A[t..i]` be the last subarray `0 <= t <= i && i - t + 1 <= K`.

```
dp[i+1] = max( dp[t] + max(t, i) * (i - t + 1) | 0 <= t <= i && i - t + 1 <= K )
dp[0] = 0
```

```cpp
// OJ: https://leetcode.com/problems/partition-array-for-maximum-sum/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(N)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int dp[501] = {}, N = A.size();
        for (int i = 0; i < N; ++i) {
            int mx = 0;
            for (int t = i, last = max(0, i + 1 - K); t >= last; --t) {
                mx = max(mx, A[t]);
                dp[i + 1] = max(dp[i + 1], dp[t] + mx * (i - t + 1));
            }
        }
        return dp[N];
    }
};
```

## Solution 2. Top-down DP

Same idea as Solution 1, just that the `dp[i]` is the answer to the subproblem on `A[i..(N-1)]`.

For `dp[i]`, we can take `A[i..j]` as the first subarray `i <= j < N && j - i + 1 <= K`.

```cpp
// OJ: https://leetcode.com/problems/partition-array-for-maximum-sum/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(N)
class Solution {
    int m[501] = {}, N, K;
    int dp(vector<int> &A, int i) {
        if (i == N) return 0;
        if (m[i] != -1) return m[i];
        int mx = 0;
        for (int j = i; j < N && j - i + 1 <= K; ++j) {
            mx = max(mx, A[j]);
            m[i] = max(m[i], mx * (j - i + 1) + dp(A, j + 1));
        }
        return m[i];
    }
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        N = A.size();
        this->K = K;
        memset(m, -1, sizeof(m));
        return dp(A, 0);
    }
};
```

## Solution 3. DP with Space Optimization

Since `dp[i + 1]` is only dependent on the previous `K` `dp` values, we can reduce the space complexity to `O(K)`.

```cpp
// OJ: https://leetcode.com/problems/partition-array-for-maximum-sum/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(K)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N = A.size();
        vector<int> dp(K);
        for (int i = 0; i < N; ++i) {
            int mx = 0, val = 0;
            for (int t = i, last = max(0, i + 1 - K); t >= last; --t) {
                mx = max(mx, A[t]);
                val = max(val, dp[t % K] + mx * (i - t + 1));
            }
            dp[(i + 1) % K] = val;
        }
        return dp[N % K];
    }
};
```