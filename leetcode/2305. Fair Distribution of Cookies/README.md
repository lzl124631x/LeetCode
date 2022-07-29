# [2305. Fair Distribution of Cookies (Medium)](https://leetcode.com/problems/fair-distribution-of-cookies/)

<p>You are given an integer array <code>cookies</code>, where <code>cookies[i]</code> denotes the number of cookies in the <code>i<sup>th</sup></code> bag. You are also given an integer <code>k</code> that denotes the number of children to distribute <strong>all</strong> the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.</p>

<p>The <strong>unfairness</strong> of a distribution is defined as the <strong>maximum</strong> <strong>total</strong> cookies obtained by a single child in the distribution.</p>

<p>Return <em>the <strong>minimum</strong> unfairness of all distributions</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> cookies = [8,15,10,20,8], k = 2
<strong>Output:</strong> 31
<strong>Explanation:</strong> One optimal distribution is [8,15,8] and [10,20]
- The 1<sup>st</sup> child receives [8,15,8] which has a total of 8 + 15 + 8 = 31 cookies.
- The 2<sup>nd</sup> child receives [10,20] which has a total of 10 + 20 = 30 cookies.
The unfairness of the distribution is max(31,30) = 31.
It can be shown that there is no distribution with an unfairness less than 31.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> cookies = [6,1,3,2,2,4,1,2], k = 3
<strong>Output:</strong> 7
<strong>Explanation:</strong> One optimal distribution is [6,1], [3,2,2], and [4,1,2]
- The 1<sup>st</sup> child receives [6,1] which has a total of 6 + 1 = 7 cookies.
- The 2<sup>nd</sup> child receives [3,2,2] which has a total of 3 + 2 + 2 = 7 cookies.
- The 3<sup>rd</sup> child receives [4,1,2] which has a total of 4 + 1 + 2 = 7 cookies.
The unfairness of the distribution is max(7,7,7) = 7.
It can be shown that there is no distribution with an unfairness less than 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= cookies.length &lt;= 8</code></li>
	<li><code>1 &lt;= cookies[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>2 &lt;= k &lt;= cookies.length</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Bitmask](https://leetcode.com/tag/bitmask/)

**Similar Questions**:
* [Split Array Largest Sum (Hard)](https://leetcode.com/problems/split-array-largest-sum/)
* [Split Array with Equal Sum (Hard)](https://leetcode.com/problems/split-array-with-equal-sum/)
* [Partition to K Equal Sum Subsets (Medium)](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)
* [Minimum XOR Sum of Two Arrays (Hard)](https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/)
* [The Number of Good Subsets (Hard)](https://leetcode.com/problems/the-number-of-good-subsets/)
* [Minimum Number of Work Sessions to Finish the Tasks (Medium)](https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/)
* [Partition Array Into Two Arrays to Minimize Sum Difference (Hard)](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/)

## Solution 1. DP

Brute force is assigning each bag to different children. So there are `8^8 ~= 2e7` ways and will get TLE.

The Brute force way has lots of duplicated computations. We can use DP to reduce such duplication.

Let `dp[k][m]` be the min unfairness of bags represented by bitmask `m` distributed to `k` children.

If we assign bags represented by `m` to a single child, the unfairness is `sum(m)`, i.e. the sum of cookies in bags represented by `m`.

```
dp[1][m] = sum(m)
```

For `dp[k][m]`, we can try `m`'s different subset `s` as the bags assigned to the last child, so this child get `sum(s)`. The rest of bags represented by `m-s` are assigned to `k-1` children.

```
dp[k][m] = min( max(dp[k-1][m-s], sum(s)) | s is a subset of m )
```

The answer is `dp[K][(1<<N)-1]`.

```cpp
// OJ: https://leetcode.com/problems/fair-distribution-of-cookies/
// Author: github.com/lzl124631x
// Time: O(2^N * N + K * 3^N)
// Space: O(K * 2^N)
class Solution {
public:
    int distributeCookies(vector<int>& A, int K) {
        int N = A.size();
        vector<vector<int>> dp(K + 1, vector<int>(1 << N, INT_MAX));
        vector<int> sum(1 << N);
        for (int m = 1; m < (1 << N); ++m) {
            int s = 0;
            for (int i = 0; i < N; ++i) {
                if (m >> i & 1) s += A[i];
            }
            sum[m] = s;
            dp[1][m] = s;
        }
        for (int k = 2; k <= K; ++k) {
            for (int m = 1; m < (1 << N); ++m) {
                for (int s = m; s; s = (s - 1) & m) {
                    dp[k][m] = min(dp[k][m], max(dp[k - 1][m - s], sum[s]));
                }
            }
        }
        return dp[K][(1 << N) - 1];
    }
};
```

## Solution 2. DP with Space Optimization

Since `dp[k][m]` only depends on `dp[k-1][m-s]`, we can reduce the space for the `dp` array from `K * 2^N` to `2^N`.

```cpp
// OJ: https://leetcode.com/problems/fair-distribution-of-cookies/
// Author: github.com/lzl124631x
// Time: O(2^N * N + K * 3^N)
// Space: O(2^N)
class Solution {
public:
    int distributeCookies(vector<int>& A, int K) {
        int N = A.size();
        vector<int> dp(1 << N, INT_MAX), next(1 << N), sum(1 << N);
        for (int m = 1; m < (1 << N); ++m) {
            int s = 0;
            for (int i = 0; i < N; ++i) {
                if (m >> i & 1) s += A[i];
            }
            sum[m] = s;
            dp[m] = s;
        }
        for (int k = 2; k <= K; ++k) {
            fill(begin(next), end(next), INT_MAX);
            for (int m = 1; m < (1 << N); ++m) {
                for (int s = m; s; s = (s - 1) & m) {
                    next[m] = min(next[m], max(dp[m - s], sum[s]));
                }
            }
            swap(dp, next);
        }
        return dp[(1 << N) - 1];
    }
};
```