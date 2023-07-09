# [2319. Check if Matrix Is X-Matrix (Easy)](https://leetcode.com/problems/check-if-matrix-is-x-matrix)

<p>A square matrix is said to be an <strong>X-Matrix</strong> if <strong>both</strong> of the following conditions hold:</p>
<ol>
	<li>All the elements in the diagonals of the matrix are <strong>non-zero</strong>.</li>
	<li>All other elements are 0.</li>
</ol>
<p>Given a 2D integer array <code>grid</code> of size <code>n x n</code> representing a square matrix, return <code>true</code><em> if </em><code>grid</code><em> is an X-Matrix</em>. Otherwise, return <code>false</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/05/03/ex1.jpg" style="width: 311px; height: 320px;">
<pre><strong>Input:</strong> grid = [[2,0,0,1],[0,3,1,0],[0,5,2,0],[4,0,0,2]]
<strong>Output:</strong> true
<strong>Explanation:</strong> Refer to the diagram above. 
An X-Matrix should have the green elements (diagonals) be non-zero and the red elements be 0.
Thus, grid is an X-Matrix.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/05/03/ex2.jpg" style="width: 238px; height: 246px;">
<pre><strong>Input:</strong> grid = [[5,7,0],[0,3,1],[0,5,0]]
<strong>Output:</strong> false
<strong>Explanation:</strong> Refer to the diagram above.
An X-Matrix should have the green elements (diagonals) be non-zero and the red elements be 0.
Thus, grid is not an X-Matrix.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>3 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Matrix Diagonal Sum (Easy)](https://leetcode.com/problems/matrix-diagonal-sum/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-if-matrix-is-x-matrix
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& A) {
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j || j == N - i - 1) {
                    if (A[i][j] == 0) return false;
                } else if (A[i][j] != 0) return false;
            }
        }
        return true;
    }
};
```