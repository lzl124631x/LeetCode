# [1582. Special Positions in a Binary Matrix (Easy)](https://leetcode.com/problems/special-positions-in-a-binary-matrix)

<p>Given an <code>m x n</code> binary matrix <code>mat</code>, return <em>the number of special positions in </em><code>mat</code><em>.</em></p>

<p>A position <code>(i, j)</code> is called <strong>special</strong> if <code>mat[i][j] == 1</code> and all other elements in row <code>i</code> and column <code>j</code> are <code>0</code> (rows and columns are <strong>0-indexed</strong>).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/23/special1.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>Input:</strong> mat = [[1,0,0],[0,0,1],[1,0,0]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/24/special-grid.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>Input:</strong> mat = [[1,0,0],[0,1,0],[0,0,1]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> (0, 0), (1, 1) and (2, 2) are special positions.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>mat[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


**Companies**:
[Bloomberg](https://leetcode.com/company/bloomberg), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Matrix](https://leetcode.com/tag/matrix)

**Similar Questions**:
* [Difference Between Ones and Zeros in Row and Column (Medium)](https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column)

**Hints**:
* Keep track of 1s in each row and in each column. Then while iterating over matrix, if the current position is 1 and current row as well as current column contains exactly one occurrence of 1.

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/special-positions-in-a-binary-matrix/
// Author: github.com/lzl124631x
// Time: O(MN * (M + N))
// Space: O(1)
class Solution {
public:
    int numSpecial(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] != 1) continue;
                int row = 0, col = 0;
                for (int x = 0; x < N && row <= 1; ++x) row += A[i][x];
                if (row > 1) continue;
                for (int x = 0; x < M && col <= 1; ++x) col += A[x][j];
                ans += col == 1;
            }
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/special-positions-in-a-binary-matrix/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(M + N)
class Solution {
public:
    int numSpecial(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<int> row(M), col(N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                row[i] += A[i][j];
                col[j] += A[i][j];
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                ans += A[i][j] == 1 && row[i] == 1 && col[j] == 1;
            }
        }
        return ans;
    }
};
```