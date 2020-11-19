# [1658. Minimum Operations to Reduce X to Zero (Medium)](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)

<p>You are given an integer array <code>nums</code> and an integer <code>x</code>. In one operation, you can either remove the leftmost or the rightmost element from the array <code>nums</code> and subtract its value from <code>x</code>. Note that this <strong>modifies</strong> the array for future operations.</p>

<p>Return <em>the <strong>minimum number</strong> of operations to reduce </em><code>x</code> <em>to <strong>exactly</strong></em> <code>0</code> <em>if it's possible</em><em>, otherwise, return </em><code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,4,2,3], x = 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> The optimal solution is to remove the last two elements to reduce x to zero.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5,6,7,8,9], x = 4
<strong>Output:</strong> -1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,2,20,1,1,3], x = 10
<strong>Output:</strong> 5
<strong>Explanation:</strong> The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= x &lt;= 10<sup>9</sup></code></li>
</ul>


**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [Binary Search](https://leetcode.com/tag/binary-search/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Minimum Size Subarray Sum (Medium)](https://leetcode.com/problems/minimum-size-subarray-sum/)
* [Subarray Sum Equals K (Medium)](https://leetcode.com/problems/subarray-sum-equals-k/)

## Solution 1. Two pointers

```cpp
// OJ: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minOperations(vector<int>& A, int x) {
        int left = 0, right = 0, N = A.size(), i = 0, j = N - 1, ans = INT_MAX;
        for (; i < A.size(); ++i) {
            left += A[i];
            if (left >= x || i == N - 1) break;
        }
        if (left < x) return -1;
        if (left == x) ans = i + 1;
        for (; j >= 0 && right <= x; --j) {
            right += A[j];
            while (i >= 0 && left + right > x) left -= A[i--];
            if (left + right == x) ans = min(ans, i + 1 + N - j);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
```