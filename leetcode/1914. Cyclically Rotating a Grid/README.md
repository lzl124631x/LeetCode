# [1914. Cyclically Rotating a Grid (Medium)](https://leetcode.com/problems/cyclically-rotating-a-grid/)

<p>You are given an <code>m x n</code> integer matrix <code>grid</code>​​​, where <code>m</code> and <code>n</code> are both <strong>even</strong> integers, and an integer <code>k</code>.</p>

<p>The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/06/10/ringofgrid.png" style="width: 231px; height: 258px;"></p>

<p>A cyclic rotation of the matrix is done by cyclically rotating <strong>each layer</strong> in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the <strong>counter-clockwise</strong> direction. An example rotation is shown below:</p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/22/explanation_grid.jpg" style="width: 500px; height: 268px;">
<p>Return <em>the matrix after applying </em><code>k</code> <em>cyclic rotations to it</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/19/rod2.png" style="width: 421px; height: 191px;">
<pre><strong>Input:</strong> grid = [[40,10],[30,20]], k = 1
<strong>Output:</strong> [[10,20],[40,30]]
<strong>Explanation:</strong> The figures above represent the grid at every state.
</pre>

<p><strong>Example 2:</strong></p>
<strong><img alt="" src="https://assets.leetcode.com/uploads/2021/06/10/ringofgrid5.png" style="width: 231px; height: 262px;"></strong> <strong><img alt="" src="https://assets.leetcode.com/uploads/2021/06/10/ringofgrid6.png" style="width: 231px; height: 262px;"></strong> <strong><img alt="" src="https://assets.leetcode.com/uploads/2021/06/10/ringofgrid7.png" style="width: 231px; height: 262px;"></strong>

<pre><strong>Input:</strong> grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
<strong>Output:</strong> [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
<strong>Explanation:</strong> The figures above represent the grid at every state.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 50</code></li>
	<li>Both <code>m</code> and <code>n</code> are <strong>even</strong> integers.</li>
	<li><code>1 &lt;= grid[i][j] &lt;=<sup> </sup>5000</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

The `rotate` function comes from [189. Rotate Array (Medium)](https://leetcode.com/problems/rotate-array/).

```cpp
// OJ: https://leetcode.com/problems/cyclically-rotating-a-grid/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(M + N)
class Solution {
    void rotate(vector<int>& A, int k) {
        int cnt = 0, N = A.size();
        k %= N;
        if (k == 0) return;
        for (int i = 0; cnt < N; ++i) {
            int j = i, tmp = A[j];
            do {
                int t = (j + k) % N, next = A[t];
                A[t] = tmp;
                tmp = next;
                j = t;
                ++cnt;
            } while (j != i);
        }
    }
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& A, int K) {
        int M = A.size(), N = A[0].size();
        for (int i = 0; i < min(M, N) / 2; ++i) {
            int x = i, y = i, h = M - 2 * i, w = N - 2 * i, k = 0, len = 2 * (h + w - 2);
            vector<int> v(len);
            for (int j = 1; j < w; ++j, ++y) v[k++] = A[x][y];
            for (int j = 1; j < h; ++j, ++x) v[k++] = A[x][y];
            for (int j = 1; j < w; ++j, --y) v[k++] = A[x][y];
            for (int j = 1; j < h; ++j, --x) v[k++] = A[x][y];
            rotate(v, len - K % len);
            x = i, y = i, k = 0;
            for (int j = 1; j < w; ++j, ++y) A[x][y] = v[k++];
            for (int j = 1; j < h; ++j, ++x) A[x][y] = v[k++];
            for (int j = 1; j < w; ++j, --y) A[x][y] = v[k++];
            for (int j = 1; j < h; ++j, --x) A[x][y] = v[k++] ;
        }
        return A;
    }
};
```