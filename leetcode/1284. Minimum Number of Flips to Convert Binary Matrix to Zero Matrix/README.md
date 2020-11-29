# [1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix (Hard)](https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/)

<p>Given a <code>m x n</code> binary matrix <code>mat</code>. In one step, you can choose one cell and flip it and all the four neighbours of it&nbsp;if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighboors if they share one edge.</p>

<p>Return the <em>minimum number of steps</em> required to convert <code>mat</code>&nbsp;to a zero matrix or <strong>-1</strong> if you cannot.</p>

<p>Binary matrix is a matrix with all cells equal to 0 or 1 only.</p>

<p>Zero matrix is a matrix with all cells equal to 0.</p>

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
<strong>Explanation:</strong> Given matrix is a zero matrix. We don't need to change it.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> mat = [[1,1,1],[1,0,1],[0,0,0]]
<strong>Output:</strong> 6
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> mat = [[1,0,0],[1,0,0]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> Given matrix can't be a zero matrix
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m ==&nbsp;mat.length</code></li>
	<li><code>n ==&nbsp;mat[0].length</code></li>
	<li><code>1 &lt;= m&nbsp;&lt;= 3</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 3</code></li>
	<li><code>mat[i][j]</code> is 0 or 1.</li>
</ul>


**Related Topics**:  
[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. Bit vector + BFS

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/
// Author: github.com/lzl124631x
// Time: O(MN * 2^(MN))
// Space: O(2^(MN))
class Solution {
public:
    int minFlips(vector<vector<int>>& A) {
        int start = 0, M = A.size(), N = A[0].size(), step = 0, dirs[5] = {1,0,-1,0,1};
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                start |= (A[i][j] << (i * 3 + j));
            }
        }
        queue<int> q;
        unordered_set<int> s;
        q.push(start);
        s.insert(start);
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                int state = q.front();
                q.pop();
                if (state == 0) return step;
                for (int i = 0; i < 9; ++i) {
                    int next = state, r = i / 3, c = i % 3;
                    next ^= (1 << (r * 3 + c));
                    for (int j = 0; j < 4; ++j) {
                        int x = r + dirs[j], y = c + dirs[j + 1];
                        if (x < 0 || x >= M || y < 0 || y >= N) continue;
                        next ^= (1 << (x * 3 + y));
                    }
                    if (s.count(next) == 0) {
                        q.push(next);
                        s.insert(next);
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};
```