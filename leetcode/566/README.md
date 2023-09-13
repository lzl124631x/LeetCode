# [566. Reshape the Matrix (Easy)](https://leetcode.com/problems/reshape-the-matrix/)

<p>In MATLAB, there is a handy function called <code>reshape</code>&nbsp;which can reshape an <code>m x n</code> matrix into a new one with a different size <code>r x c</code>&nbsp;keeping its original data.</p>

<p>You are given an <code>m x n</code>&nbsp;matrix <code>mat</code> and two integers <code>r</code> and <code>c</code> representing the row number and column number of the wanted reshaped matrix.</p>

<p>The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.</p>

<p>If the <code>reshape</code>&nbsp;operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/reshape1-grid.jpg" style="width: 613px; height: 173px;">
<pre><strong>Input:</strong> mat = [[1,2],[3,4]], r = 1, c = 4
<strong>Output:</strong> [[1,2,3,4]]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/reshape2-grid.jpg" style="width: 453px; height: 173px;">
<pre><strong>Input:</strong> mat = [[1,2],[3,4]], r = 2, c = 4
<strong>Output:</strong> [[1,2],[3,4]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>-1000 &lt;= mat[i][j] &lt;= 1000</code></li>
	<li><code>1 &lt;= r, c &lt;= 300</code></li>
</ul>


**Companies**:  
[Mathworks](https://leetcode.com/company/mathworks)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Matrix](https://leetcode.com/tag/matrix/), [Simulation](https://leetcode.com/tag/simulation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reshape-the-matrix/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int M = nums.size(), N = nums[0].size();
        if (M * N != r * c) return nums;
        vector<vector<int>> ans;
        for (int i = 0; i < r; ++i) {
            vector<int> row;
            for (int j = 0; j < c; ++j) {
                int index = i * c + j;
                row.push_back(nums[index / N][index % N]);
            }
            ans.push_back(row);
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/reshape-the-matrix/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& A, int r, int c) {
        int M = A.size(), N = A[0].size(), a = 0, b = 0;
        if (M == r || r * c != M * N) return A;
        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                ans[a][b] = A[i][j];
                if (++b == c) {
                    b = 0;
                    ++a;
                }
            }
        }
        return ans;
    }
};
```