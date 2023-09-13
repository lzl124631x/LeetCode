# [1681. Minimum Incompatibility (Hard)](https://leetcode.com/problems/minimum-incompatibility/)

<p>You are given an integer array <code>nums</code>​​​ and an integer <code>k</code>. You are asked to distribute this array into <code>k</code> subsets of <strong>equal size</strong> such that there are no two equal elements in the same subset.</p>

<p>A subset's <strong>incompatibility</strong> is the difference between the maximum and minimum elements in that array.</p>

<p>Return <em>the <strong>minimum possible sum of incompatibilities</strong> of the </em><code>k</code> <em>subsets after distributing the array optimally, or return </em><code>-1</code><em> if it is not possible.</em></p>

<p>A subset is a group integers that appear in the array with no particular order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,1,4], k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> The optimal distribution of subsets is [1,2] and [1,4].
The incompatibility is (2-1) + (4-1) = 4.
Note that [1,1] and [2,4] would result in a smaller sum, but the first subset contains 2 equal elements.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [6,3,8,1,3,1,2,2], k = 4
<strong>Output:</strong> 6
<strong>Explanation:</strong> The optimal distribution of subsets is [1,2], [2,3], [6,8], and [1,3].
The incompatibility is (2-1) + (3-2) + (8-6) + (3-1) = 6.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [5,3,3,6,3,3], k = 3
<strong>Output:</strong> -1
<strong>Explanation:</strong> It is impossible to distribute nums into 3 subsets where no two elements are equal in the same subset.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 16</code></li>
	<li><code>nums.length</code> is divisible by <code>k</code></li>
	<li><code>1 &lt;= nums[i] &lt;= nums.length</code></li>
</ul>


**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Bitmask DP

### Preprocess

* Sort `A` in asending order
* Handle special cases where `k = 1` and `k = N`.

### State Definition

Let `dp[mask][pre]` be the minimum incompatibility we can get with:
* `mask`: If the `i`th bit is `0`, then `i`th number is used. Otherwise, `i`th number is available.
* `pre`: the index of the number selected in the previous choice.

### State Transition

We allocate the subsets one by one. For each subset, we allocate the numbers in ascending order.

We can use the number of `1` bits in `mask`, i.e. `__builtin_popcount(mask)`, to know how many numbers are available.

**If `__builtin_popcount(mask)` is not divisible by `sz`**, then in the current choice we need to consider `pre`. To avoid duplicate numbers in the same subset, we must choose a number that is greater than `A[pre]`. Assume we chose `A[p]`, then we added `A[p] - A[pre]` into the incompatibility.

```plaintext
          pre  p
           v   v
A:       1 2 2 3 4 4 5 5 6 
subset:  1 2   3

delta
incompa-   3 - 2 = 1
tibility
```

Transition formula:

```
dp[mask][pre] = min( dp[mask - (1 << p)][p] + A[p] - A[pre] | pre < p < N && A[p] > A[pre] && (mask & (1 << p)) != 0 )
```

**If `__builtin_popcount(mask)` is divisible by `sz`**, then we are allocating for a new subset. Now `pre` doesn't matter. We just need to pick the first available number.

```
dp[mask][0] = ... = dp[mask][N - 1] = min( dp[mask - (1 << p)][p] | 0 < p < N && (mask & (1 << p)) != 0 )
```

```cpp
// OJ: https://leetcode.com/problems/minimum-incompatibility/
// Author: github.com/lzl124631x
// Time: O(2^N * N^2)
// Space: O(2^N * N)
// Ref: https://leetcode-cn.com/problems/minimum-incompatibility/solution/lao-tao-lu-zhuang-tai-ya-suo-dp-by-newha-j58b/
class Solution {
public:
    int minimumIncompatibility(vector<int>& A, int k) {
        int N = A.size(), M = 1 << N, sz = N / k;
        if (k == 1) {
            set<int> s(begin(A), end(A));
            return s.size() == A.size() ? *s.rbegin() - *s.begin() : -1;
        }
        if (k == N) return 0;
        sort(begin(A), end(A));
        int dp[M][N];
        memset(dp, 0x3f, sizeof(dp)); // infinity
        memset(dp[0], 0, sizeof(dp[0]));
        for (int mask = 1; mask < M; ++mask) {
            if (__builtin_popcount(mask) % sz) {
                for (int pre = 0; pre < N; ++pre) {
                    for (int p = pre + 1; p < N; ++p) {
                        if ((mask & (1 << p)) && A[p] > A[pre]) {
                            dp[mask][pre] = min(dp[mask][pre], dp[mask - (1 << p)][p] + A[p] - A[pre]);
                        }
                    }
                }
            } else {
                for (int p = 0; p < N; ++p) {
                    if (mask & (1 << p)) dp[mask][0] = min(dp[mask][0], dp[mask - (1 << p)][p]);
                }
                for (int i = 1; i < N; ++i) dp[mask][i] = dp[mask][0];
            }
        }
        return dp[M - 1][0] > 10000 ? -1 : dp[M - 1][0];
    }
};
```