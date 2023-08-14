# [2815. Max Pair Sum in an Array (Easy)](https://leetcode.com/problems/max-pair-sum-in-an-array)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>. You have to find the <strong>maximum</strong> sum of a pair of numbers from <code>nums</code> such that the maximum <strong>digit </strong>in both numbers are equal.</p>
<p>Return <em>the maximum sum or</em> <code>-1</code><em> if no such pair exists</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [51,71,17,24,42]
<strong>Output:</strong> 88
<strong>Explanation:</strong> 
For i = 1 and j = 2, nums[i] and nums[j] have equal maximum digits with a pair sum of 71 + 17 = 88. 
For i = 3 and j = 4, nums[i] and nums[j] have equal maximum digits with a pair sum of 24 + 42 = 66.
It can be shown that there are no other pairs with equal maximum digits, so the answer is 88.</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> -1
<strong>Explanation:</strong> No pair exists in nums with equal maximum digits.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/max-pair-sum-in-an-array
// Author: github.com/lzl124631x
// Time: O(NlogD)
// Space: O(1)
class Solution {
public:
    int maxSum(vector<int>& A) {
        int mx[10][2] = {}, ans = -1;
        for (int n : A) {
            int m = n, d = 0;
            for (; m; m /= 10) d = max(d, m % 10);
            if (n > mx[d][0]) mx[d][1] = mx[d][0], mx[d][0] = n;
            else if (n > mx[d][1]) mx[d][1] = n;
        }
        for (int d = 1; d <= 9; ++d) {
            if (mx[d][0] && mx[d][1]) ans = max(ans, mx[d][0] + mx[d][1]);
        }
        return ans;
    }
};
```