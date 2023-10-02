# [542. 01 Matrix (Medium)](https://leetcode.com/problems/01-matrix)

<p>Given an <code>m x n</code> binary matrix <code>mat</code>, return <em>the distance of the nearest </em><code>0</code><em> for each cell</em>.</p>
<p>The distance between two adjacent cells is <code>1</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/01-1-grid.jpg" style="width: 253px; height: 253px;">
<pre><strong>Input:</strong> mat = [[0,0,0],[0,1,0],[0,0,0]]
<strong>Output:</strong> [[0,0,0],[0,1,0],[0,0,0]]
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/01-2-grid.jpg" style="width: 253px; height: 253px;">
<pre><strong>Input:</strong> mat = [[0,0,0],[0,1,0],[1,1,1]]
<strong>Output:</strong> [[0,0,0],[0,1,0],[1,2,1]]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>4</sup></code></li>
	<li><code>mat[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
	<li>There is at least one <code>0</code> in <code>mat</code>.</li>
</ul>

**Companies**:
[Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Shortest Path to Get Food (Medium)](https://leetcode.com/problems/shortest-path-to-get-food/)
* [Minimum Operations to Remove Adjacent Ones in Matrix (Hard)](https://leetcode.com/problems/minimum-operations-to-remove-adjacent-ones-in-matrix/)
* [Difference Between Ones and Zeros in Row and Column (Medium)](https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/01-matrix/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> ans(M, vector<int>(N, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 0) {
                    q.emplace(i, j);
                    ans[i][j] = 0;
                }
            }
        }
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto &[dx, dy] : dirs) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || a >= M || b < 0 || b >= N || ans[a][b] != INT_MAX) continue;
                    ans[a][b] = 1 + ans[x][y];
                    q.emplace(a, b);
                }
            }
        }
        return ans;
    }
};
```

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/01-matrix/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1) if in-place computation is allowed; otherwise O(MN)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j]) A[i][j] = 0x3f3f3f3f;
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                A[i][j] = min({ A[i][j], i - 1 >= 0 ? A[i - 1][j] + 1 : INT_MAX, j - 1 >= 0 ? A[i][j - 1] + 1 : INT_MAX });
            }
        }
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                A[i][j] = min({ A[i][j], i + 1 < M ? A[i + 1][j] + 1 : INT_MAX, j + 1 < N ? A[i][j + 1] + 1 : INT_MAX });
            }
        }
        return A;
    }
};
```