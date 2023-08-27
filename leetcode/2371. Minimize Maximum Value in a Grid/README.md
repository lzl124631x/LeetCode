# [2371. Minimize Maximum Value in a Grid (Hard)](https://leetcode.com/problems/minimize-maximum-value-in-a-grid)

<p>You are given an <code>m x n</code> integer matrix <code>grid</code> containing <strong>distinct</strong> positive integers.</p>
<p>You have to replace each integer in the matrix with a positive integer satisfying the following conditions:</p>
<ul>
	<li>The <strong>relative</strong> order of every two elements that are in the same row or column should stay the <strong>same</strong> after the replacements.</li>
	<li>The <strong>maximum</strong> number in the matrix after the replacements should be as <strong>small</strong> as possible.</li>
</ul>
<p>The relative order stays the same if for all pairs of elements in the original matrix such that <code>grid[r<sub>1</sub>][c<sub>1</sub>] &gt; grid[r<sub>2</sub>][c<sub>2</sub>]</code> where either <code>r<sub>1</sub> == r<sub>2</sub></code> or <code>c<sub>1</sub> == c<sub>2</sub></code>, then it must be true that <code>grid[r<sub>1</sub>][c<sub>1</sub>] &gt; grid[r<sub>2</sub>][c<sub>2</sub>]</code> after the replacements.</p>
<p>For example, if <code>grid = [[2, 4, 5], [7, 3, 9]]</code> then a good replacement could be either <code>grid = [[1, 2, 3], [2, 1, 4]]</code> or <code>grid = [[1, 2, 3], [3, 1, 4]]</code>.</p>
<p>Return <em>the <strong>resulting</strong> matrix.</em> If there are multiple answers, return <strong>any</strong> of them.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/08/09/grid2drawio.png" style="width: 371px; height: 121px;">
<pre><strong>Input:</strong> grid = [[3,1],[2,5]]
<strong>Output:</strong> [[2,1],[1,2]]
<strong>Explanation:</strong> The above diagram shows a valid replacement.
The maximum number in the matrix is 2. It can be shown that no smaller value can be obtained.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> grid = [[10]]
<strong>Output:</strong> [[1]]
<strong>Explanation:</strong> We replace the only number in the matrix with 1.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 1000</code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>9</sup></code></li>
	<li><code>grid</code> consists of distinct integers.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/), [Union Find](https://leetcode.com/tag/union-find/), [Graph](https://leetcode.com/tag/graph/), [Topological Sort](https://leetcode.com/tag/topological-sort/), [Sorting](https://leetcode.com/tag/sorting/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Candy (Hard)](https://leetcode.com/problems/candy/)

## Solution 1. Topological Sort

```cpp
// OJ: https://leetcode.com/problems/minimize-maximum-value-in-a-grid
// Author: github.com/lzl124631x
// Time: O(MN * (logM + logN))
// Space: O(MN)
class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), num = 1;
        vector<vector<int>> row(M, vector<int>(N, -1)), col(M, vector<int>(N, -1)), indegree(M, vector<int>(N)), ans(M, vector<int>(N));
        for (int i = 0; i < M; ++i) {
            vector<int> id(N);
            iota(begin(id), end(id), 0);
            sort(begin(id), end(id), [&](int a, int b) { return A[i][a] < A[i][b]; });
            for (int j = 1; j < N; ++j) {
                indegree[i][id[j]]++;
                row[i][id[j - 1]] = id[j]; // row[i][j] is the column index of the next greater element in the same row of A[i][j]
            }
        }
        for (int j = 0; j < N; ++j) {
            vector<int> id(M);
            iota(begin(id), end(id), 0);
            sort(begin(id), end(id), [&](int a, int b) { return A[a][j] < A[b][j]; });
            for (int i = 1; i < M; ++i) {
                indegree[id[i]][j]++;
                col[id[i - 1]][j] = id[i]; // col[i][j] is the row index of the next greater element in the same column of A[i][j]
            }
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (indegree[i][j] == 0) q.emplace(i, j);
            }
        }
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [x, y] = q.front();
                q.pop();
                ans[x][y] = num;
                if (row[x][y] != -1 && --indegree[x][row[x][y]] == 0) q.emplace(x, row[x][y]);
                if (col[x][y] != -1 && --indegree[col[x][y]][y] == 0) q.emplace(col[x][y], y);
            }
            ++num;
        }
        return ans;
    }
};
```