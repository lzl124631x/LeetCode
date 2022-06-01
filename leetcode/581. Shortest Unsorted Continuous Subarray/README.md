# [581. Shortest Unsorted Continuous Subarray (Medium)](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/)

<p>Given an integer array <code>nums</code>, you need to find one <b>continuous subarray</b> that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.</p>

<p>Return <em>the shortest such subarray and output its length</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,6,4,8,10,9,15]
<strong>Output:</strong> 5
<strong>Explanation:</strong> You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> 0
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Can you solve it in <code>O(n)</code> time complexity?

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack/)

## Solution 1. Greedy

The goal is to:
* find the greatest index `L` such that `A[L] <= min(A[L .. N-1])` and `A[0 .. L]` is non-decreasing
* find the smallest index `R` such that `A[R] >= max(A[0 .. R-1])` and `A[R .. N-1]` is non-decreasing.

Then, we need to sort `A[L+1 .. R-1]`, `R - L - 1` elements in total.

```cpp
// OJ: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& A) {
        int N = A.size(), L = N - 1, R = 0;
        for (int i = N - 2, mn = A.back(); i >= 0; --i) {
            mn = min(mn, A[i]);
            if (mn != A[i]) L = i - 1;
        }
        for (int i = 1, mx = A[0]; i < N; ++i) {
            mx = max(mx, A[i]);
            if (mx != A[i]) R = i + 1;
        }
        return max(0, R - L - 1);
    }
};
```