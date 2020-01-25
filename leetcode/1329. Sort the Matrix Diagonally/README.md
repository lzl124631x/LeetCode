# [1329. Sort the Matrix Diagonally (Medium)](https://leetcode.com/problems/sort-the-matrix-diagonally/)

<p>Given a <code>m * n</code> matrix <code>mat</code>&nbsp;of integers, sort it diagonally in ascending order from the top-left to the bottom-right then return the sorted array.</p>

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