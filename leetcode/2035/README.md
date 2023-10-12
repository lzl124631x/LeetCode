# [2035. Partition Array Into Two Arrays to Minimize Sum Difference (Hard)](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/)

<p>You are given an integer array <code>nums</code> of <code>2 * n</code> integers. You need to partition <code>nums</code> into <strong>two</strong> arrays of length <code>n</code> to <strong>minimize the absolute difference</strong> of the <strong>sums</strong> of the arrays. To partition <code>nums</code>, put each element of <code>nums</code> into <strong>one</strong> of the two arrays.</p>

<p>Return <em>the <strong>minimum</strong> possible absolute difference</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="example-1" src="https://assets.leetcode.com/uploads/2021/10/02/ex1.png" style="width: 240px; height: 106px;">
<pre><strong>Input:</strong> nums = [3,9,7,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> One optimal partition is: [3,9] and [7,3].
The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [-36,36]
<strong>Output:</strong> 72
<strong>Explanation:</strong> One optimal partition is: [-36] and [36].
The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="example-3" src="https://assets.leetcode.com/uploads/2021/10/02/ex3.png" style="width: 316px; height: 106px;">
<pre><strong>Input:</strong> nums = [2,-1,0,4,-2,-9]
<strong>Output:</strong> 0
<strong>Explanation:</strong> One optimal partition is: [2,4,-9] and [-1,0,-2].
The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 15</code></li>
	<li><code>nums.length == 2 * n</code></li>
	<li><code>-10<sup>7</sup> &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
</ul>


**Similar Questions**:
* [Partition Equal Subset Sum (Medium)](https://leetcode.com/problems/partition-equal-subset-sum/)
* [Split Array With Same Average (Hard)](https://leetcode.com/problems/split-array-with-same-average/)
* [Tallest Billboard (Hard)](https://leetcode.com/problems/tallest-billboard/)
* [Last Stone Weight II (Medium)](https://leetcode.com/problems/last-stone-weight-ii/)
* [Closest Subsequence Sum (Hard)](https://leetcode.com/problems/closest-subsequence-sum/)

## Solution 1. Meet in the Middle

We select `k` elements from the first half (left part) whose sum is `a` and `N - k` elements from the right part whose sum is `b`. These total `N` elements have sum `a + b`, and the complement `N` elements have sum `sum(A) - a - b`. Since we want to minimize `abs(a + b - (sum(A) - a - b)) = abs(sum(A) - 2 * (a + b))`, for a given `a`, the optimal `b = (sum(A) - 2 * a) / 2`.

We can enumerate each possible `a` of a left subset of size `k`, and binary search the closest value to the optimal `b` of a right subset of size `N - k`.

```cpp
// OJ: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
// Author: github.com/lzl124631x
// Time: O(2^N * N)
// Space: O(2^N)
class Solution {
public:
    int minimumDifference(vector<int>& A) {
        int N = A.size() / 2, sum = accumulate(begin(A), end(A), 0); 
        vector<vector<int>> left(N + 1), right(N + 1); // left[k] is an array of all sums of left subsets of size `k`.
        for (int mask = 0; mask < 1 << N; ++mask) { // fill all the left and right sum arrays
            int k = __builtin_popcount(mask), L = 0, R = 0; 
            for (int i = 0; i < N; ++i) {
                if (mask >> i & 1) {
                    L += A[i];
                    R += A[i + N];
                }
            }
            left[k].push_back(L);
            right[k].push_back(R);
        }
        for (int k = 0; k <= N; ++k) sort(begin(right[k]), end(right[k])); // sort right[k] for binary search
        int ans = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0])); // If we pick all N elements from first half or second half
        for (int k = 1; k <= N; ++k) {
            auto &v = right[N - k];
            for (int a : left[k]) {
                int b = (sum - 2 * a) / 2;
                auto it = lower_bound(begin(v), end(v), b);
                if (it != end(v)) ans = min(ans, abs(sum - 2 * (a + *it)));
                if (it != begin(v)) ans = min(ans, abs(sum - 2 * (a + *prev(it))));
            }
        }
        return ans;
    }
};
```

## NOTE

Similar to [1755. Closest Subsequence Sum (Hard)](https://leetcode.com/problems/closest-subsequence-sum/)