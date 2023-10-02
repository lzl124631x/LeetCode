# [1329. Sort the Matrix Diagonally (Medium)](https://leetcode.com/problems/sort-the-matrix-diagonally/submissions/)

<p>A <strong>matrix diagonal</strong> is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the <strong>matrix diagonal</strong> starting from <code>mat[2][0]</code>, where <code>mat</code> is a <code>6 x 3</code> matrix, includes cells <code>mat[2][0]</code>, <code>mat[3][1]</code>, and <code>mat[4][2]</code>.</p>

<p>Given an <code>m x n</code> matrix <code>mat</code> of integers, sort each <strong>matrix diagonal</strong> in ascending order and return <em>the resulting matrix</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/01/21/1482_example_1_2.png" style="width: 500px; height: 198px;">
<pre><strong>Input:</strong> mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
<strong>Output:</strong> [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m ==&nbsp;mat.length</code></li>
	<li><code>n ==&nbsp;mat[i].length</code></li>
	<li><code>1 &lt;= m, n&nbsp;&lt;= 100</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 100</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sort](https://leetcode.com/tag/sort/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sort-the-matrix-diagonally/
// Author: github.com/lzl124631x
// Time: O((M + N) * XlogX) where X is min(M, N) 
// Space: O(X)
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            vector<int> v;
            for (int x = i, y = 0; x < M && y < N; ++x, ++y) v.push_back(A[x][y]);
            sort(begin(v), end(v));
            for (int x = i, y = 0; x < M && y < N; ++x, ++y) A[x][y] = v[y];
        }
        for (int j = 1; j < N; ++j) {
            vector<int> v;
            for (int x = 0, y = j; x < M && y < N; ++x, ++y) v.push_back(A[x][y]);
            sort(begin(v), end(v));
            for (int x = 0, y = j; x < M && y < N; ++x, ++y) A[x][y] = v[x];
        }
        return A;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/sort-the-matrix-diagonally/
// Author: github.com/lzl124631x
// Time: O(min(M, N)^2 * (M + N))
// Space: O(1)
class Solution {
    int M, N, minMN;
    void bubbleSort(vector<vector<int>> &v, int sx, int sy) {
        for (int i = 0; i < minMN; ++i) {
            int ix = sx + i, iy = sy + i;
            if (ix >= M || iy >= N) return;
            for (int j = minMN - 1; j > i; --j) {
                int jx = sx + j, jy = sy + j;
                if (jx >= M || jy  >= N) continue;
                if (jx - 1 < 0 || jy - 1 < 0) break;
                if (v[jx][jy] < v[jx - 1][ jy - 1]) swap(v[jx][jy] ,v[jx - 1][ jy - 1]);
            }
        }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        M = mat.size(), N = mat[0].size(), minMN = min(M, N);
        for (int i = 0; i < N; ++i) bubbleSort(mat, 0, i);
        for (int i = 1; i < M; ++i) bubbleSort(mat, i, 0);            
        return mat;
    }
};
```