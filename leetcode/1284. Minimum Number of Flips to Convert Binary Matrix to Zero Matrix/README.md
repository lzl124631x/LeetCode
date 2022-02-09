# [1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix (Hard)](https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/)

<p>Given a <code>m x n</code> binary matrix <code>mat</code>. In one step, you can choose one cell and flip it and all the four neighbors of it if they exist (Flip is changing <code>1</code> to <code>0</code> and <code>0</code> to <code>1</code>). A pair of cells are called neighbors if they share one edge.</p>

<p>Return the <em>minimum number of steps</em> required to convert <code>mat</code> to a zero matrix or <code>-1</code> if you cannot.</p>

<p>A <strong>binary matrix</strong> is a matrix with all cells equal to <code>0</code> or <code>1</code> only.</p>

<p>A <strong>zero matrix</strong> is a matrix with all cells equal to <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/11/28/matrix.png" style="width: 409px; height: 86px;">
<pre><strong>Input:</strong> mat = [[0,0],[0,1]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> One possible solution is to flip (1, 0) then (0, 1) and finally (1, 1) as shown.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> mat = [[0]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Given matrix is a zero matrix. We do not need to change it.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> mat = [[1,0,0],[1,0,0]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> Given matrix cannot be a zero matrix.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 3</code></li>
	<li><code>mat[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Minimum Operations to Remove Adjacent Ones in Matrix (Hard)](https://leetcode.com/problems/minimum-operations-to-remove-adjacent-ones-in-matrix/)
* [Remove All Ones With Row and Column Flips (Medium)](https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips/)

## Solution 1. Bit Mask + BFS

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/
// Author: github.com/lzl124631x
// Time: O(MN * 2^(MN))
// Space: O(2^(MN))
class Solution {
public:
    int minFlips(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), init = 0, step = 0, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) init |= A[i][j] << (i * N + j);
        }
        queue<int> q{{init}};
        unordered_set<int> seen{init};
        auto flip = [&](int &state, int x, int y) { state ^= 1 << (x * N + y); };
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                int u = q.front();
                q.pop();
                if (u == 0) return step;
                for (int i = 0; i < M; ++i) {
                    for (int j = 0; j < N; ++j) {
                        int v = u;
                        flip(v, i, j);
                        for (auto &[dx, dy] : dirs) {
                            int a = i + dx, b = j + dy;
                            if (a < 0 || b < 0 || a >= M || b >= N) continue;
                            flip(v, a, b);
                        }
                        if (seen.count(v)) continue;
                        seen.insert(v);
                        q.push(v);
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};
```
