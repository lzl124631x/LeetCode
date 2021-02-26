# [581. Shortest Unsorted Continuous Subarray (Medium)](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/submissions/)

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
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& A) {
        if (A.size() == 1) return 0;
        int N = A.size(), mx = -1e6, left = -1, right = N - 2;
        while (right >= 0 && A[right] <= A[right + 1]) --right;
        if (right < 0) return 0;
        for (int i = 0; i <= right; ++i) {
            mx = max(mx, A[i]);
            while (right + 1 < N && A[right + 1] < mx) ++right;
            if (i - 1 >= 0 && A[i] < A[i - 1]) {
                if (left == -1) left = i;
                while (left - 1 >= 0 && A[left - 1] > A[i]) --left;
            }
        }
        return right - left + 1;
    }
};
```