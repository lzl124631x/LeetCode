# [308. Range Sum Query 2D - Mutable (Hard)](https://leetcode.com/problems/range-sum-query-2d-mutable)

<p>Given a 2D matrix <code>matrix</code>, handle multiple queries of the following types:</p>
<ol>
	<li><strong>Update</strong> the value of a cell in <code>matrix</code>.</li>
	<li>Calculate the <strong>sum</strong> of the elements of <code>matrix</code> inside the rectangle defined by its <strong>upper left corner</strong> <code>(row1, col1)</code> and <strong>lower right corner</strong> <code>(row2, col2)</code>.</li>
</ol>
<p>Implement the NumMatrix class:</p>
<ul>
	<li><code>NumMatrix(int[][] matrix)</code> Initializes the object with the integer matrix <code>matrix</code>.</li>
	<li><code>void update(int row, int col, int val)</code> <strong>Updates</strong> the value of <code>matrix[row][col]</code> to be <code>val</code>.</li>
	<li><code>int sumRegion(int row1, int col1, int row2, int col2)</code> Returns the <strong>sum</strong> of the elements of <code>matrix</code> inside the rectangle defined by its <strong>upper left corner</strong> <code>(row1, col1)</code> and <strong>lower right corner</strong> <code>(row2, col2)</code>.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/summut-grid.jpg" style="width: 500px; height: 222px;">
<pre><strong>Input</strong>
["NumMatrix", "sumRegion", "update", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [3, 2, 2], [2, 1, 4, 3]]
<strong>Output</strong>
[null, 8, null, 10]

<strong>Explanation</strong>
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e. sum of the left red rectangle)
numMatrix.update(3, 2, 2);       // matrix changes from left image to right image
numMatrix.sumRegion(2, 1, 4, 3); // return 10 (i.e. sum of the right red rectangle)
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>-1000 &lt;= matrix[i][j] &lt;= 1000</code></li>
	<li><code>0 &lt;= row &lt; m</code></li>
	<li><code>0 &lt;= col &lt; n</code></li>
	<li><code>-1000 &lt;= val &lt;= 1000</code></li>
	<li><code>0 &lt;= row1 &lt;= row2 &lt; m</code></li>
	<li><code>0 &lt;= col1 &lt;= col2 &lt; n</code></li>
	<li>At most <code>5000</code> calls will be made to <code>sumRegion</code> and <code>update</code>.</li>
</ul>

**Companies**:
[Bloomberg](https://leetcode.com/company/bloomberg), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Design](https://leetcode.com/tag/design/), [Binary Indexed Tree](https://leetcode.com/tag/binary-indexed-tree/), [Segment Tree](https://leetcode.com/tag/segment-tree/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Range Sum Query 2D - Immutable (Medium)](https://leetcode.com/problems/range-sum-query-2d-immutable/)
* [Range Sum Query - Mutable (Medium)](https://leetcode.com/problems/range-sum-query-mutable/)
* [Increment Submatrices by One (Medium)](https://leetcode.com/problems/increment-submatrices-by-one/)
* [Sum of Matrix After Queries (Medium)](https://leetcode.com/problems/sum-of-matrix-after-queries/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/range-sum-query-2d-mutable
// Author: github.com/lzl124631x
// Time:
//      NumMatrix: O(MNlogN)
//      update: O(logN)
//      sumRegion: O(RlogN) where R is row2 - row1 + 1
// Space: O()
class NumMatrix {
    int M, N;
    vector<vector<int>> A, node;
    static inline int lb(int x) { return x & -x; }
    int query(int row, int col) {
        int ans = 0;
        for (col++; col; col -= lb(col)) ans += node[row][col];
        return ans;
    }
public:
    NumMatrix(vector<vector<int>>& A) : A(M, vector<int>(N)), M(A.size()), N(A[0].size()), node(M, vector<int>(N + 1)){
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                update(i, j, A[i][j]);
            }
        }
    }
    void update(int row, int col, int val) {
        int delta = val - A[row][col];
        for (int c = col + 1; c < N + 1; c += lb(c)) node[row][c] += delta;
        A[row][col] = val;
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for (int r = row1; r <= row2; ++r) {
            ans += query(r, col2) - query(r, col1 - 1);
        }
        return ans;
    }
};
```