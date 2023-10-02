# [2717. Semi-Ordered Permutation (Easy)](https://leetcode.com/problems/semi-ordered-permutation)

<p>You are given a <strong>0-indexed</strong> permutation of <code>n</code> integers <code>nums</code>.</p>
<p>A permutation is called <strong>semi-ordered</strong> if the first number equals <code>1</code> and the last number equals <code>n</code>. You can perform the below operation as many times as you want until you make <code>nums</code> a <strong>semi-ordered</strong> permutation:</p>
<ul>
	<li>Pick two adjacent elements in <code>nums</code>, then swap them.</li>
</ul>
<p>Return <em>the minimum number of operations to make </em><code>nums</code><em> a <strong>semi-ordered permutation</strong></em>.</p>
<p>A <strong>permutation</strong> is a sequence of integers from <code>1</code> to <code>n</code> of length <code>n</code> containing each number exactly once.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [2,1,4,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can make the permutation semi-ordered using these sequence of operations: 
1 - swap i = 0 and j = 1. The permutation becomes [1,2,4,3].
2 - swap i = 2 and j = 3. The permutation becomes [1,2,3,4].
It can be proved that there is no sequence of less than two operations that make nums a semi-ordered permutation. 
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,4,1,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can make the permutation semi-ordered using these sequence of operations:
1 - swap i = 1 and j = 2. The permutation becomes [2,1,4,3].
2 - swap i = 0 and j = 1. The permutation becomes [1,2,4,3].
3 - swap i = 2 and j = 3. The permutation becomes [1,2,3,4].
It can be proved that there is no sequence of less than three operations that make nums a semi-ordered permutation.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,4,2,5]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The permutation is already a semi-ordered permutation.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= nums.length == n &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i]&nbsp;&lt;= 50</code></li>
	<li><code>nums is a permutation.</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Simulation](https://leetcode.com/tag/simulation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/semi-ordered-permutation
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int semiOrderedPermutation(vector<int>& A) {
        int a = min_element(begin(A), end(A)) - begin(A), b = max_element(begin(A), end(A)) - begin(A);
        return a + A.size() - 1 - b - (a > b);
    }
};
```