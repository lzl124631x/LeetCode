# [1879. Minimum XOR Sum of Two Arrays (Hard)](https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/)

<p>You are given two integer arrays <code>nums1</code> and <code>nums2</code> of length <code>n</code>.</p>

<p>The <strong>XOR sum</strong> of the two integer arrays is <code>(nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1])</code> (<strong>0-indexed</strong>).</p>

<ul>
	<li>For example, the <strong>XOR sum</strong> of <code>[1,2,3]</code> and <code>[3,2,1]</code> is equal to <code>(1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4</code>.</li>
</ul>

<p>Rearrange the elements of <code>nums2</code> such that the resulting <strong>XOR sum</strong> is <b>minimized</b>.</p>

<p>Return <em>the <strong>XOR sum</strong> after the rearrangement</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,2], nums2 = [2,3]
<strong>Output:</strong> 2
<b>Explanation:</b> Rearrange <code>nums2</code> so that it becomes <code>[3,2]</code>.
The XOR sum is (1 XOR 3) + (2 XOR 2) = 2 + 0 = 2.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,0,3], nums2 = [5,3,4]
<strong>Output:</strong> 8
<b>Explanation:</b> Rearrange <code>nums2</code> so that it becomes <code>[5,4,3]</code>. 
The XOR sum is (1 XOR 5) + (0 XOR 4) + (3 XOR 3) = 4 + 4 + 0 = 8.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums1.length</code></li>
	<li><code>n == nums2.length</code></li>
	<li><code>1 &lt;= n &lt;= 14</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 10<sup>7</sup></code></li>
</ul>


**Companies**:  
[Media.net](https://leetcode.com/company/medianet)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1. DP Top-down

The brute force solution is to enumerate all `N!` permutations of array `B`.

We need to find ways to eliminate repetitive computations. Assume both `A` and `B` are `[1,2,3,4,5]`. If we have two paritial attempts `B1 = [2,3,?,?,?]` and `B2 = [3,2,?,?,?]`, the determined parts in `B1` and `B2` will yield different XOR sums, but the indetermined parts will have a single optimal solution which we can memoize.

We can use bitmask to represent the subset of numbers in `B` that are already used, and memoize the corresponding result.

In this way, we turned the `O(N!)` enumeration of permutations to a `O(N * 2^N)` enumeration of all the `O(2^N)` subsets.

```
dp[i][mask] = XOR_SUM(0, i) + min( dp[i + 1][next_mask] | next_mask has one more bit 1 than mask )
dp[0][0] = 0
```

Note that given `mask` we can know `i` so we just need to memoize `dp[mask]` (`2^N` items).

```
dp[mask] = XOR_SUM(0, i) + min( dp[next_mask] | next_mask has one more bit 1 than mask )
dp[0] = 0
```

The logic behind this algorithm is very similar to the traveling salesperson problem.

```cpp
// OJ: https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(2^N)
class Solution {
    int m[16384] = {[0 ... 16383] = INT_MAX}, N;
    int dp(vector<int> &A, vector<int> &B, int i, int mask) {
        if (i == N) return 0;
        if (m[mask] != INT_MAX) return m[mask];
        int ans = INT_MAX;
        for (int j = 0; j < N; ++j) {
            if (mask >> j & 1) continue;
            ans = min(ans, (A[i] ^ B[j]) + dp(A, B, i + 1, mask | (1 << j)));
        }
        return m[mask] = ans;
    }
public:
    int minimumXORSum(vector<int>& A, vector<int>& B) {
        N = A.size();
        return dp(A, B, 0, 0);
    }
};
```

## Solution 2. DP Bottom-up

```cpp
// OJ: https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(2^N)
class Solution {
public:
    int minimumXORSum(vector<int>& A, vector<int>& B) {
        int dp[16384] = {[0] = 0, [1 ... 16383] = INT_MAX}, N = A.size();
        for (int mask = 0; mask < (1 << N); ++mask) {
            int i = __builtin_popcount(mask);
            for (int j = 0; j < N; ++j) {
                if (mask >> j & 1) continue;
                int next = (mask | (1 << j));
                dp[next] = min(dp[next], dp[mask] + (A[i] ^ B[j]));
            }
        }
        return dp[(1 << N) - 1];
    }
};
```