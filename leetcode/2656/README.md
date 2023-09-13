# [2656. Maximum Sum With Exactly K Elements  (Easy)](https://leetcode.com/problems/maximum-sum-with-exactly-k-elements)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> and an integer <code>k</code>. Your task is to perform the following operation <strong>exactly</strong> <code>k</code> times in order to maximize your score:</p>
<ol>
	<li>Select an element <code>m</code> from <code>nums</code>.</li>
	<li>Remove the selected element <code>m</code> from the array.</li>
	<li>Add a new element with a value of <code>m + 1</code> to the array.</li>
	<li>Increase your score by <code>m</code>.</li>
</ol>
<p>Return <em>the maximum score you can achieve after performing the operation exactly</em> <code>k</code> <em>times.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3,4,5], k = 3
<strong>Output:</strong> 18
<strong>Explanation:</strong> We need to choose exactly 3 elements from nums to maximize the sum.
For the first iteration, we choose 5. Then sum is 5 and nums = [1,2,3,4,6]
For the second iteration, we choose 6. Then sum is 5 + 6 and nums = [1,2,3,4,7]
For the third iteration, we choose 7. Then sum is 5 + 6 + 7 = 18 and nums = [1,2,3,4,8]
So, we will return 18.
It can be proven, that 18 is the maximum answer that we can achieve.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [5,5,5], k = 2
<strong>Output:</strong> 11
<strong>Explanation:</strong> We need to choose exactly 2 elements from nums to maximize the sum.
For the first iteration, we choose 5. Then sum is 5 and nums = [5,5,6]
For the second iteration, we choose 6. Then sum is 5 + 6 = 11 and nums = [5,5,7]
So, we will return 11.
It can be proven, that 11 is the maximum answer that we can achieve.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 100</code></li>
</ul>
<p>&nbsp;</p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Greedy

Greedily pick the greatest element `n`, and keep increasing it. We will get `n + (n+1) + ... + (n+k-1) = (n + n + k - 1) * k / 2` score.

```cpp
// OJ: https://leetcode.com/problems/maximum-sum-with-exactly-k-elements
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximizeSum(vector<int>& A, int k) {
        int n = *max_element(begin(A), end(A));
        return (n + n + k - 1) * k / 2;
    }
};
```