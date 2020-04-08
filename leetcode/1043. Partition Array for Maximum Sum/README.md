# [1043. Partition Array for Maximum Sum (Medium)](https://leetcode.com/problems/partition-array-for-maximum-sum/)

<p>Given an integer array <code>A</code>, you partition the array into (contiguous) subarrays of length at most <code>K</code>.&nbsp; After partitioning, each subarray has their values changed to become the maximum value of that subarray.</p>

<p>Return the largest sum of the given array after partitioning.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-1-1">[1,15,7,9,2,5,10]</span>, K = <span id="example-input-1-2">3</span>
<strong>Output: </strong><span id="example-output-1">84
</span><strong>Explanation</strong>: A becomes [15,15,15,9,10,10,10]</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= K &lt;= A.length&nbsp;&lt;= 500</code></li>
	<li><code>0 &lt;= A[i] &lt;= 10^6</code></li>
</ol>


**Related Topics**:  
[Graph](https://leetcode.com/tag/graph/)

## Solution 1. DP

Let `dp[i]` be the subproblem in `A[0..i]`.

```
dp[i] = max( dp[j-1] + max(A[j], ..., A[i]) * (i - j + 1) | i - j + 1 <= K && j >= 0 )
dp[-1] = 0
```

```cpp
// OJ: https://leetcode.com/problems/partition-array-for-maximum-sum/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(N)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N = A.size();
        vector<int> dp(N);
        for (int i = 0; i < N; ++i) {
            int maxVal = 0;
            for (int j = i, k = 0; j >= 0 && k < K; --j, ++k) {
                maxVal = max(maxVal, A[j]);
                dp[i] = max(dp[i], (j == 0 ? 0 : dp[j - 1]) + maxVal * (i - j + 1));
            }
        }
        return dp[N - 1];
    }
};
```

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/partition-array-for-maximum-sum/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(K)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N = A.size();
        ++K;
        vector<int> dp(K);
        for (int i = 0; i < N; ++i) {
            int maxVal = 0;
            dp[i % K] = 0;
            for (int j = i, k = 0; j >= 0 && k < K - 1; --j, ++k) {
                maxVal = max(maxVal, A[j]);
                dp[i % K] = max(dp[i % K], (j == 0 ? 0 : dp[(j - 1) % K]) + maxVal * (i - j + 1));
            }
        }
        return dp[(N - 1) % K];
    }
};
```