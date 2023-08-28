# [2576. Find the Maximum Number of Marked Indices (Medium)](https://leetcode.com/problems/find-the-maximum-number-of-marked-indices)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>.</p>
<p>Initially, all of the indices are unmarked. You are allowed to make this operation any number of times:</p>
<ul>
	<li>Pick two <strong>different unmarked</strong> indices <code>i</code> and <code>j</code> such that <code>2 * nums[i] &lt;= nums[j]</code>, then mark <code>i</code> and <code>j</code>.</li>
</ul>
<p>Return <em>the maximum possible number of marked indices in <code>nums</code> using the above operation any number of times</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [3,5,2,4]
<strong>Output:</strong> 2
<strong>Explanation: </strong>In the first operation: pick i = 2 and j = 1, the operation is allowed because 2 * nums[2] &lt;= nums[1]. Then mark index 2 and 1.
It can be shown that there's no other valid operation so the answer is 2.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [9,2,5,4]
<strong>Output:</strong> 4
<strong>Explanation: </strong>In the first operation: pick i = 3 and j = 0, the operation is allowed because 2 * nums[3] &lt;= nums[0]. Then mark index 3 and 0.
In the second operation: pick i = 1 and j = 2, the operation is allowed because 2 * nums[1] &lt;= nums[2]. Then mark index 1 and 2.
Since there is no other operation, the answer is 4.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [7,6,8]
<strong>Output:</strong> 0
<strong>Explanation: </strong>There is no valid operation to do, so the answer is 0.

</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>
<p>&nbsp;</p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Binary Search](https://leetcode.com/tag/binary-search/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1. Binary Answer

```cpp
// OJ: https://leetcode.com/problems/find-the-maximum-number-of-marked-indices
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& A) {
        sort(begin(A), end(A));
        int N = A.size(), L = 0, R = N / 2;
        auto valid = [&](int k) {
            int i = 0, j = N - k;
            for (; i < k; ++i, ++j) {
                if (2 * A[i] > A[j]) return false;
            }
            return true;
        };
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(M)) L = M + 1;
            else R = M - 1;
        }
        return R * 2;
    }
};
```