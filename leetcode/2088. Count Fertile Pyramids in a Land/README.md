# [2088. Count Fertile Pyramids in a Land (Hard)](https://leetcode.com/problems/count-fertile-pyramids-in-a-land/)

<p>A farmer has a <strong>rectangular grid</strong> of land with <code>m</code> rows and <code>n</code> columns that can be divided into unit cells. Each cell is either <strong>fertile</strong> (represented by a <code>1</code>) or <strong>barren</strong> (represented by a <code>0</code>). All cells outside the grid are considered barren.</p>

<p>A <strong>pyramidal plot</strong> of land can be defined as a set of cells with the following criteria:</p>

<ol>
	<li>The number of cells in the set has to be <strong>greater than </strong><code>1</code> and all cells must be <strong>fertile</strong>.</li>
	<li>The <strong>apex</strong> of a pyramid is the <strong>topmost</strong> cell of the pyramid. The <strong>height</strong> of a pyramid is the number of rows it covers. Let <code>(r, c)</code> be the apex of the pyramid, and its height be <code>h</code>. Then, the plot comprises of cells <code>(i, j)</code> where <code>r &lt;= i &lt;= r + h - 1</code> <strong>and</strong> <code>c - (i - r) &lt;= j &lt;= c + (i - r)</code>.</li>
</ol>

<p>An <strong>inverse pyramidal plot</strong> of land can be defined as a set of cells with similar criteria:</p>

<ol>
	<li>The number of cells in the set has to be <strong>greater than </strong><code>1</code> and all cells must be <strong>fertile</strong>.</li>
	<li>The <strong>apex</strong> of an inverse pyramid is the <strong>bottommost</strong> cell of the inverse pyramid. The <strong>height</strong> of an inverse pyramid is the number of rows it covers. Let <code>(r, c)</code> be the apex of the pyramid, and its height be <code>h</code>. Then, the plot comprises of cells <code>(i, j)</code> where <code>r - h + 1 &lt;= i &lt;= r</code> <strong>and</strong> <code>c - (r - i) &lt;= j &lt;= c + (r - i)</code>.</li>
</ol>

<p>Some examples of valid and invalid pyramidal (and inverse pyramidal) plots are shown below. Black cells indicate fertile cells.</p>
<img src="https://assets.leetcode.com/uploads/2021/11/08/image.png" style="width: 700px; height: 156px;">
<p>Given a <strong>0-indexed</strong> <code>m x n</code> binary matrix <code>grid</code> representing the farmland, return <em>the <strong>total number</strong> of pyramidal and inverse pyramidal plots that can be found in</em> <code>grid</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/23/eg11.png" style="width: 200px; height: 102px;">&nbsp;<img alt="" src="https://assets.leetcode.com/uploads/2021/10/23/exa12.png" style="width: 200px; height: 102px;">&nbsp;<img alt="" src="https://assets.leetcode.com/uploads/2021/10/23/exa13.png" style="width: 200px; height: 102px;">
<pre><strong>Input:</strong> grid = [[0,1,1,0],[1,1,1,1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
The 2 possible pyramidal plots are shown in blue and red respectively.
There are no inverse pyramidal plots in this grid.&nbsp;
Hence total number of pyramidal and inverse pyramidal plots is 2 + 0 = 2.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/23/eg21.png" style="width: 180px; height: 122px;">&nbsp;<img alt="" src="https://assets.leetcode.com/uploads/2021/10/23/exa22.png" style="width: 180px; height: 122px;">&nbsp;<img alt="" src="https://assets.leetcode.com/uploads/2021/10/23/exa23.png" style="width: 180px; height: 122px;">
<pre><strong>Input:</strong> grid = [[1,1,1],[1,1,1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
The pyramidal plot is shown in blue, and the inverse pyramidal plot is shown in red.&nbsp;
Hence the total number of plots is 1 + 1 = 2.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/23/eg3.png" style="width: 149px; height: 150px;">
<pre><strong>Input:</strong> grid = [[1,0,1],[0,0,0],[1,0,1]]
<strong>Output:</strong> 0
<strong>Explanation:</strong>
There are no pyramidal or inverse pyramidal plots in the grid.
</pre>

<p><strong>Example 4:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/23/eg41.png" style="width: 180px; height: 144px;">&nbsp;<img alt="" src="https://assets.leetcode.com/uploads/2021/10/23/eg42.png" style="width: 180px; height: 144px;">&nbsp;<img alt="" src="https://assets.leetcode.com/uploads/2021/10/23/eg43.png" style="width: 180px; height: 144px;">&nbsp;<img alt="" src="https://assets.leetcode.com/uploads/2021/10/23/eg44.png" style="width: 180px; height: 144px;">
<pre><strong>Input:</strong> grid = [[1,1,1,1,0],[1,1,1,1,1],[1,1,1,1,1],[0,1,0,0,1]]
<strong>Output:</strong> 13
<strong>Explanation:</strong>
There are 7 pyramidal plots, 3 of which are shown in the 2nd and 3rd figures.
There are 6 inverse pyramidal plots, 2 of which are shown in the last figure.
The total number of plots is 7 + 6 = 13.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 1000</code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>grid[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


**Similar Questions**:
* [Count Square Submatrices with All Ones (Medium)](https://leetcode.com/problems/count-square-submatrices-with-all-ones/)
* [Get Biggest Three Rhombus Sums in a Grid (Medium)](https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/)

## Solution 1. Prefix Sum

```cpp
// OJ: https://leetcode.com/problems/count-fertile-pyramids-in-a-land/
// Author: github.com/lzl124631x
// Time: O(M^2 * N)
// Space: O(MN) can be reduced to O(1) if we calculate prefix sums in-place
class Solution {
public:
    int countPyramids(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<vector<int>> sum(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) partial_sum(begin(A[i]), end(A[i]), begin(sum[i]) + 1);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 0) continue;
                int h = 1;
                while (i + h - 1 < M && j + h - 1 < N && j - h + 1 >= 0 && sum[i + h - 1][j + h] - sum[i + h - 1][j - h + 1] == 2 * h - 1) ++h;
                ans += max(0, h - 2);
                h = 1;
                while (i - h + 1 >= 0 && j + h - 1 < N && j - h + 1 >= 0 && sum[i - h + 1][j + h] - sum[i - h + 1][j - h + 1] == 2 * h - 1) ++h;
                ans += max(0, h - 2);
            }
        }
        return ans;
    }
};
```