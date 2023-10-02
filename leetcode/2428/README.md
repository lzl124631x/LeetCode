# [2428. Maximum Sum of an Hourglass (Medium)](https://leetcode.com/problems/maximum-sum-of-an-hourglass)

<p>You are given an <code>m x n</code> integer matrix <code>grid</code>.</p>
<p>We define an <strong>hourglass</strong> as a part of the matrix with the following form:</p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/08/21/img.jpg" style="width: 243px; height: 243px;">
<p>Return <em>the <strong>maximum</strong> sum of the elements of an hourglass</em>.</p>
<p><strong>Note</strong> that an hourglass cannot be rotated and must be entirely contained within the matrix.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/08/21/1.jpg" style="width: 323px; height: 323px;">
<pre><strong>Input:</strong> grid = [[6,2,1,3],[4,2,1,5],[9,2,8,7],[4,1,2,9]]
<strong>Output:</strong> 30
<strong>Explanation:</strong> The cells shown above represent the hourglass with the maximum sum: 6 + 2 + 1 + 2 + 9 + 2 + 8 = 30.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/08/21/2.jpg" style="width: 243px; height: 243px;">
<pre><strong>Input:</strong> grid = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> 35
<strong>Explanation:</strong> There is only one hourglass in the matrix, with the sum: 1 + 2 + 3 + 5 + 7 + 8 + 9 = 35.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>3 &lt;= m, n &lt;= 150</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 10<sup>6</sup></code></li>
</ul>

**Companies**:
[Nutanix](https://leetcode.com/company/nutanix)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Matrix](https://leetcode.com/tag/matrix/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Matrix Block Sum (Medium)](https://leetcode.com/problems/matrix-block-sum/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/maximum-sum-of-an-hourglass
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int maxSum(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        for (int i = 0; i <= M - 3; ++i) {
            for (int j = 0; j <= N - 3; ++j) {
                ans = max(ans, A[i][j] + A[i][j + 1] + A[i][j + 2] + A[i + 1][j + 1] + A[i + 2][j] + A[i + 2][j + 1] + A[i + 2][j + 2]);
            }
        }
        return ans;
    }
};
```