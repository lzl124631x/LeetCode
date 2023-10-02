# [73. Set Matrix Zeroes (Medium)](https://leetcode.com/problems/set-matrix-zeroes/)

<p>Given an <code>m x n</code> integer matrix <code>matrix</code>, if an element is <code>0</code>, set its entire row and column to <code>0</code>'s, and return <em>the matrix</em>.</p>

<p>You must do it <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in place</a>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/17/mat1.jpg" style="width: 450px; height: 169px;">
<pre><strong>Input:</strong> matrix = [[1,1,1],[1,0,1],[1,1,1]]
<strong>Output:</strong> [[1,0,1],[0,0,0],[1,0,1]]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/17/mat2.jpg" style="width: 450px; height: 137px;">
<pre><strong>Input:</strong> matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
<strong>Output:</strong> [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[0].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>-2<sup>31</sup> &lt;= matrix[i][j] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>A straightforward solution using <code>O(mn)</code> space is probably a bad idea.</li>
	<li>A simple improvement uses <code>O(m + n)</code> space, but still not the best solution.</li>
	<li>Could you devise a constant space solution?</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Qualtrics](https://leetcode.com/company/qualtrics)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Game of Life (Medium)](https://leetcode.com/problems/game-of-life/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/set-matrix-zeroes/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(M + N)
class Solution {
public:
    void setZeroes(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        vector<bool> row(M), col(N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                row[i] = row[i] || A[i][j] == 0;
                col[j] = col[j] || A[i][j] == 0;
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (row[i] || col[j]) A[i][j] = 0;
            }
        }
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/set-matrix-zeroes/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& A) {
        bool firstRow = false, firstColumn = false;
        int M = A.size(), N = A[0].size();
        for (int i = 0; i < N && !firstRow; ++i) firstRow = A[0][i] == 0;
        for (int i = 0; i < M && !firstColumn; ++i) firstColumn = A[i][0] == 0;
        for (int i = 1; i < M; ++i) {
            for (int j = 1; j < N; ++j) {
                if (A[i][j] == 0) A[i][0] = A[0][j] = 0;
            }
        }
        for (int i = 1; i < M; ++i) {
            for (int j = 1; j < N; ++j) {
                 if (A[i][0] == 0 || A[0][j] == 0) A[i][j] = 0;
            }
        }
        if (firstRow) {
            for (int i = 0; i < N; ++i) A[0][i] = 0;
        }
        if (firstColumn) {
            for (int i = 0; i < M; ++i) A[i][0] = 0;
        }
    }
};
```