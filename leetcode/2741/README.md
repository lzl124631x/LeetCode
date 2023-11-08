# [2741. Special Permutations (Medium)](https://leetcode.com/problems/special-permutations)

<p>You are given a&nbsp;<strong>0-indexed</strong>&nbsp;integer array&nbsp;<code>nums</code>&nbsp;containing&nbsp;<code>n</code>&nbsp;<strong>distinct</strong> positive integers. A permutation of&nbsp;<code>nums</code>&nbsp;is called special if:</p>

<ul>
	<li>For all indexes&nbsp;<code>0 &lt;= i &lt; n - 1</code>, either&nbsp;<code>nums[i] % nums[i+1] == 0</code>&nbsp;or&nbsp;<code>nums[i+1] % nums[i] == 0</code>.</li>
</ul>

<p>Return&nbsp;<em>the total number of special permutations.&nbsp;</em>As the answer could be large, return it&nbsp;<strong>modulo&nbsp;</strong><code>10<sup>9&nbsp;</sup>+ 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,3,6]
<strong>Output:</strong> 2
<strong>Explanation:</strong> [3,6,2] and [2,6,3] are the two special permutations of nums.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,4,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> [3,1,4] and [4,1,3] are the two special permutations of nums.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 14</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation), [Bitmask](https://leetcode.com/tag/bitmask)

**Hints**:
* Can we solve this problem using DP with bit masking?
* You just need two states in DP which are last_ind in the permutation and the mask of numbers already used.

## Solution 1. Bitmask DP (Top-down DP)

The brute force way is to use DFS to traverse all the `14!` permutations. But there are lots of repeated compuations. For example, there are multiple ways, say `k` ways, to reach a state where we've used the first 5 numbers and the last number was `A[i]`, then the computations for the rest `N-5` numbers will repeat `k` times. We can resolve this via memoization, i.e. DP.

Let `dp[i][used]` be the number of ways forming a good permuation using the numbers masked via `used` and the last number being `A[i]`. The answer is `SUM( dp[i][1 << i] | 0 <= i < N)`.

For `dp[i][used]`, we have:

```
dp[i][used] = SUM( dp[j][1 << j | used] )
            where j is unused and A[j] % A[i] == 0 || A[i] % A[j] == 0
```

```cpp
// OJ: https://leetcode.com/problems/special-permutations
// Author: github.com/lzl124631x
// Time: O(2^N * N^2)
// Space: O(2^N * N)
class Solution {
    long getKey(int last, int used) {
        return ((long)last << 14) + used;
    }
public:
    int specialPerm(vector<int>& A) {
        long N = A.size(), mod = 1e9 + 7, ans = 0, all = (1 << N) - 1;
        unordered_map<int, long> m;
        function<long(int, int)> dp = [&](int i, int used) {
            if (used == all) return 1L;
            long key = getKey(i, used);
            if (m.count(key)) return m[key];
            long ans = 0;
            for (int j = 0; j < N; ++j) {
                if ((used >> j & 1) || (A[i] % A[j] && A[j] % A[i])) continue;
                ans = (ans + dp(j, used | (1 << j))) % mod;
            }
            return m[key] = ans;
        };
        for (int i = 0; i < N; ++i) {
            ans = (ans + dp(i, 1 << i)) % mod;
        }
        return ans;
    }
};
```