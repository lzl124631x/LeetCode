# [2778. Sum of Squares of Special Elements  (Easy)](https://leetcode.com/problems/sum-of-squares-of-special-elements)

<p>You are given a <strong>1-indexed</strong> integer array <code>nums</code> of length <code>n</code>.</p>
<p>An element <code>nums[i]</code> of <code>nums</code> is called <strong>special</strong> if <code>i</code> divides <code>n</code>, i.e. <code>n % i == 0</code>.</p>
<p>Return <em>the <strong>sum of the squares</strong> of all <strong>special</strong> elements of </em><code>nums</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> 21
<strong>Explanation:</strong> There are exactly 3 special elements in nums: nums[1] since 1 divides 4, nums[2] since 2 divides 4, and nums[4] since 4 divides 4. 
Hence, the sum of the squares of all special elements of nums is nums[1] * nums[1] + nums[2] * nums[2] + nums[4] * nums[4] = 1 * 1 + 2 * 2 + 4 * 4 = 21.  
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,7,1,19,18,3]
<strong>Output:</strong> 63
<strong>Explanation:</strong> There are exactly 4 special elements in nums: nums[1] since 1 divides 6, nums[2] since 2 divides 6, nums[3] since 3 divides 6, and nums[6] since 6 divides 6. 
Hence, the sum of the squares of all special elements of nums is nums[1] * nums[1] + nums[2] * nums[2] + nums[3] * nums[3] + nums[6] * nums[6] = 2 * 2 + 7 * 7 + 1 * 1 + 3 * 3 = 63. 
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length == n &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Simulation](https://leetcode.com/tag/simulation/)

**Similar Questions**:
* [Sum of Square Numbers (Medium)](https://leetcode.com/problems/sum-of-square-numbers/)
* [Sum of All Odd Length Subarrays (Easy)](https://leetcode.com/problems/sum-of-all-odd-length-subarrays/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sum-of-squares-of-special-elements
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int sumOfSquares(vector<int>& A) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            if (N % (i + 1) == 0) ans += A[i] * A[i];
        }
        return ans;
    }
};
```