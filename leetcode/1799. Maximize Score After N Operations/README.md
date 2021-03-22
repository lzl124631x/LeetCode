# [1799. Maximize Score After N Operations (Hard)](https://leetcode.com/problems/maximize-score-after-n-operations/)

<p>You are given <code>nums</code>, an array of positive integers of size <code>2 * n</code>. You must perform <code>n</code> operations on this array.</p>

<p>In the <code>i<sup>th</sup></code> operation <strong>(1-indexed)</strong>, you will:</p>

<ul>
	<li>Choose two elements, <code>x</code> and <code>y</code>.</li>
	<li>Receive a score of <code>i * gcd(x, y)</code>.</li>
	<li>Remove <code>x</code> and <code>y</code> from <code>nums</code>.</li>
</ul>

<p>Return <em>the maximum score you can receive after performing </em><code>n</code><em> operations.</em></p>

<p>The function <code>gcd(x, y)</code> is the greatest common divisor of <code>x</code> and <code>y</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2]
<strong>Output:</strong> 1
<strong>Explanation:</strong>&nbsp;The optimal choice of operations is:
(1 * gcd(1, 2)) = 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,4,6,8]
<strong>Output:</strong> 11
<strong>Explanation:</strong>&nbsp;The optimal choice of operations is:
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4,5,6]
<strong>Output:</strong> 14
<strong>Explanation:</strong>&nbsp;The optimal choice of operations is:
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 7</code></li>
	<li><code>nums.length == 2 * n</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/), [Recursion](https://leetcode.com/tag/recursion/)

## Solution 1. Bitmask DP

Let `dp[m]` be the maximum score we can get on subset `m` where `m` is a binary mask representation of a subset of array `A`. (e.g. `m = 0101` means that `A[0]` and `A[2]` are in the subset `m`)

Given a subset `m`, we can select two elements out of it as the last operation. Assume their indexes are `i` and `j` respectively, the score we get from the last operation is `cnt / 2 * gcd(A[i], A[j])` where `cnt` is the number of bit 1s in `m`. For the rest of the elements, they form a subset represented by `next = m & ~(1 << i) & ~(1 << j)`, whose maximum score is `dp[next]`.

```
dp[m] = max( cnt / 2 * gcd(A[i], A[j]) + dp[next]  )
```

where `i `and `j` are two different indexes of bit 1s in `m`, and `next = m & ~(1 << i) & ~(1 << j)` represents the subset `m` excluding `A[i]` and `A[j]`.

### Complexity Analysis

We traverse the binary masks from `2` to `2^N - 1` so the outer `for` loop will run `O(2^N)` time.

In each round of `for` loop, we take `O(N^2)` time to traverse all the pairs of elements in the subset `m`.

Thus, overall it takes `O(2^N * N^2)` time.

And the space complexity is apparently `O(2^N)` as well because of the `dp` array.

```cpp
// OJ: https://leetcode.com/problems/maximize-score-after-n-operations/
// Author: github.com/lzl124631x
// Time: O(2^N * N^2)
// Space: O(2^N)
class Solution {
public:
    int maxScore(vector<int>& A) {
        int N = A.size();
        vector<int> dp(1 << N);
        for (int m = 3; m < (1 << N); ++m) { // `m` is a binary mask representation of the elements in the subset
            int cnt = __builtin_popcount(m);
            if (cnt % 2) continue; // if there are even number of elements in this subset, skip
            vector<int> b; // indexes of elements in this subset
            for (int tmp = m, i = 0; tmp; ++i, tmp >>= 1) {
                if (tmp & 1) b.push_back(i); // `m` has bit 1 at position `i`, which means that `A[i]` is in the current subset
            }
            for (int i = 0; i < b.size() ; ++i) {
                for (int j = i + 1; j < b.size(); ++j) { // use different pairs as the last operation on this subset
                    int next = m & ~(1 << b[i]) & ~(1 << b[j]); // `next` represents the subset after removing `A[b[i]]` and `A[b[j]]` from subset `m`
                    dp[m] = max(dp[m], cnt / 2 * gcd(A[b[i]], A[b[j]]) + dp[next]); // cnt / 2 * gcd(A[b[i]], A[b[j]]) is the score we get in the last operation. dp[next] is the maximum score we can get on the subset `next.
                }
            }
        }
        return dp.back();
    }
};
```