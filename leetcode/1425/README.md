# [1425. Constrained Subsequence Sum (Hard)](https://leetcode.com/problems/constrained-subsequence-sum)

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return the maximum sum of a <strong>non-empty</strong> subsequence of that array such that for every two <strong>consecutive</strong> integers in the subsequence, <code>nums[i]</code> and <code>nums[j]</code>, where <code>i &lt; j</code>, the condition <code>j - i &lt;= k</code> is satisfied.</p>

<p>A <em>subsequence</em> of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [10,2,-10,5,20], k = 2
<strong>Output:</strong> 37
<b>Explanation:</b> The subsequence is [10, 2, 5, 20].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1,-2,-3], k = 1
<strong>Output:</strong> -1
<b>Explanation:</b> The subsequence must be non-empty, so we choose the largest number.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [10,-2,-10,-5,20], k = 2
<strong>Output:</strong> 23
<b>Explanation:</b> The subsequence is [10, -2, -5, 20].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Akuna Capital](https://leetcode.com/company/akuna-capital)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Queue](https://leetcode.com/tag/queue), [Sliding Window](https://leetcode.com/tag/sliding-window), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue), [Monotonic Queue](https://leetcode.com/tag/monotonic-queue)

**Similar Questions**:
* [Maximum Element-Sum of a Complete Subset of Indices (Hard)](https://leetcode.com/problems/maximum-element-sum-of-a-complete-subset-of-indices)

**Hints**:
* Use dynamic programming.
* Let dp[i] be the solution for the prefix of the array that ends at index i, if the element at index i is in the subsequence.
* dp[i] = nums[i] + max(0, dp[i-k], dp[i-k+1], ..., dp[i-1])
* Use a heap with the sliding window technique to optimize the dp.

## Solution 1. DP + Monotonic Deque

Let `dp[i]` be the maximum constrained subsequence sum of `A[0..i]` ending with `A[i]`. The answer is `max( dp[i] | 0 <= i < N )`. Initially `dp[i] = A[i]`.

The transition between `dp` values are easy to think of:

```
dp[i] = max(0, max(dp[j] | i-k <= j < i )) + A[i]
```

Notice this part `max(dp[j] | i-k <= j < i )`. It's asking for the maximum `dp[j]` where `j` is in the window `[i-k, i-1]`. This is a typical monotonic deque problem.

* We use a monotonic decreasing `deque<int> q` to store the indices of the possible maximum values within the window `i-k <= j <= i-1`.
* For a new `dp[i]` value, we keep popping `q.back()` if `dp[q.back()] <= dp[i]`.
* Then push `i` into `q`.
* Since `i-k` will go out of window, we pop `q.front()` if `q.front() == i - k`.

```cpp
// OJ: https://leetcode.com/problems/constrained-subsequence-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& A, int k) {
        deque<int> q{0};
        vector<int> dp = A;
        for (int i = 1, N = A.size(); i < N; ++i) {
            dp[i] = max(0, dp[q.front()]) + A[i];
            while (q.size() && dp[q.back()] <= dp[i]) q.pop_back();
            q.push_back(i);
            if (q.front() == i - k) q.pop_front();
        }
        return *max_element(begin(dp), end(dp));
    }
};
```