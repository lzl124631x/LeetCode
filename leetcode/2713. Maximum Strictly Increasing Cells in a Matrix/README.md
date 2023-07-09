# [2713. Maximum Strictly Increasing Cells in a Matrix (Hard)](https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix)

<p>Given a <strong>1-indexed</strong>&nbsp;<code>m x n</code> integer matrix <code>mat</code>, you can select any cell in the matrix as your <strong>starting cell</strong>.</p>
<p>From the starting cell, you can move to any other cell <strong>in the</strong> <strong>same row or column</strong>, but only if the value of the destination cell is <strong>strictly greater</strong> than the value of the current cell. You can repeat this process as many times as possible, moving from cell to cell until you can no longer make any moves.</p>
<p>Your task is to find the <strong>maximum number of cells</strong> that you can visit in the matrix by starting from some cell.</p>
<p>Return <em>an integer denoting the maximum number of cells that can be visited.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2023/04/23/diag1drawio.png" style="width: 200px; height: 176px;"></strong></p>
<pre><strong>Input:</strong> mat = [[3,1],[3,4]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The image shows how we can visit 2 cells starting from row 1, column 2. It can be shown that we cannot visit more than 2 cells no matter where we start from, so the answer is 2. 
</pre>
<p><strong class="example">Example 2:</strong></p>
<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2023/04/23/diag3drawio.png" style="width: 200px; height: 176px;"></strong></p>
<pre><strong>Input:</strong> mat = [[1,1],[1,1]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Since the cells must be strictly increasing, we can only visit one cell in this example. 
</pre>
<p><strong class="example">Example 3:</strong></p>
<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2023/04/23/diag4drawio.png" style="width: 350px; height: 250px;"></strong></p>
<pre><strong>Input:</strong> mat = [[3,1,6],[-9,5,7]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The image above shows how we can visit 4 cells starting from row 2, column 1. It can be shown that we cannot visit more than 4 cells no matter where we start from, so the answer is 4. 
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>m == mat.length&nbsp;</code></li>
	<li><code>n == mat[i].length&nbsp;</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= mat[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Memoization](https://leetcode.com/tag/memoization/), [Sorting](https://leetcode.com/tag/sorting/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Number of Increasing Paths in a Grid (Hard)](https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/)

## Solution 1. DP

Let `dp[i][j]` be the maximum steps we can go from a starting point.

```
dp[i][j] = max({max steps in row}, {max steps in column}) + 1
```

Since we always want to visit the cells in ascending order of values, we sort `(i,j)` by value of `A[i][j]`. We can do this using a `map<int, vector<int>> m` where the keys are cell values and values are arrays of encoded `(i,j)` positions in form of `i * N + j`.

We log the maximum steps of row `i` in `ans[i]` and maximum steps of column `j` in `ans[M + j]`.

So, `dp[i][j] = max(ans[i], ans[M + j]) + 1`.

```cpp
// OJ: https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix
// Author: github.com/lzl124631x
// Time: O(MNlogMN)
// Space: O(MN)
class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        map<int, vector<int>> m;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                m[A[i][j]].push_back(i * N + j);
            }
        }
        vector<vector<int>> dp(M, vector<int>(N));
        vector<int> ans(M + N);
        for (auto &[val, pos] : m) {
            for (int p : pos) {
                int i = p / N, j = p % N;
                dp[i][j] = max(ans[i], ans[M + j]) + 1;
            }
            for (int p : pos) {
                int i = p / N, j = p % N;
                ans[M + j] = max(ans[M + j], dp[i][j]);
                ans[i] = max(ans[i], dp[i][j]);
            }
        }
        return *max_element(begin(ans), end(ans));
    }
};
```