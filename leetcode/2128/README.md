# [2128. Remove All Ones With Row and Column Flips (Medium)](https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips/)

<p>You are given an <code>m x n</code> binary matrix <code>grid</code>.</p>

<p>In one operation, you can choose <strong>any</strong> row or column and flip each value in that row or column (i.e., changing all <code>0</code>'s to <code>1</code>'s, and all <code>1</code>'s to <code>0</code>'s).</p>

<p>Return <code>true</code><em> if it is possible to remove all </em><code>1</code><em>'s from </em><code>grid</code> using <strong>any</strong> number of operations or <code>false</code> otherwise.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/01/03/image-20220103191300-1.png" style="width: 756px; height: 225px;">
<pre><strong>Input:</strong> grid = [[0,1,0],[1,0,1],[0,1,0]]
<strong>Output:</strong> true
<strong>Explanation:</strong> One possible way to remove all 1's from grid is to:
- Flip the middle row
- Flip the middle column
</pre>

<p><strong>Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/01/03/image-20220103181204-7.png" style="width: 237px; height: 225px;">
<pre><strong>Input:</strong> grid = [[1,1,0],[0,0,0],[0,0,0]]
<strong>Output:</strong> false
<strong>Explanation:</strong> It is impossible to remove all 1's from grid.
</pre>

<p><strong>Example 3:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/01/03/image-20220103181224-8.png" style="width: 114px; height: 100px;">
<pre><strong>Input:</strong> grid = [[0]]
<strong>Output:</strong> true
<strong>Explanation:</strong> There are no 1's in grid.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>grid[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Score After Flipping Matrix (Medium)](https://leetcode.com/problems/score-after-flipping-matrix/)
* [Minimum Number of Flips to Convert Binary Matrix to Zero Matrix (Hard)](https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/)
* [Minimum Operations to Remove Adjacent Ones in Matrix (Hard)](https://leetcode.com/problems/minimum-operations-to-remove-adjacent-ones-in-matrix/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    bool removeOnes(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            if (A[i][0] == 0) continue;
            for (int j = 0; j < N; ++j) A[i][j] = 1 - A[i][j];
        }
        for (int j = 0; j < N; ++j) {
            if (A[0][j] == 0) continue;
            for (int i = 0; i < M; ++i) {
                A[i][j] = 1 - A[i][j];
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j]) return false;
            }
        }
        return true;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    bool removeOnes(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            if (A[i][0]) {
                for (int j = 0; j < N; ++j) A[i][j] = 1 - A[i][j];
            }
            if (i > 0) {
                for (int j = 0; j < N; ++j) {
                    if (A[i][j] != A[0][j]) return false;
                }
            }
        }
        return true;
    }
};
```