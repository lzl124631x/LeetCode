# [1260. Shift 2D Grid (Easy)](https://leetcode.com/problems/shift-2d-grid/)

<p>Given a 2D <code>grid</code> of size <code>m x n</code>&nbsp;and an integer <code>k</code>. You need to shift the <code>grid</code>&nbsp;<code>k</code> times.</p>

<p>In one shift operation:</p>

<ul>
	<li>Element at <code>grid[i][j]</code> moves to <code>grid[i][j + 1]</code>.</li>
	<li>Element at <code>grid[i][n - 1]</code> moves to <code>grid[i + 1][0]</code>.</li>
	<li>Element at <code>grid[m&nbsp;- 1][n - 1]</code> moves to <code>grid[0][0]</code>.</li>
</ul>

<p>Return the <em>2D grid</em> after applying shift operation <code>k</code> times.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/11/05/e1.png" style="width: 400px; height: 178px;">
<pre><strong>Input:</strong> <code>grid</code> = [[1,2,3],[4,5,6],[7,8,9]], k = 1
<strong>Output:</strong> [[9,1,2],[3,4,5],[6,7,8]]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/11/05/e2.png" style="width: 400px; height: 166px;">
<pre><strong>Input:</strong> <code>grid</code> = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
<strong>Output:</strong> [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> <code>grid</code> = [[1,2,3],[4,5,6],[7,8,9]], k = 9
<strong>Output:</strong> [[1,2,3],[4,5,6],[7,8,9]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m ==&nbsp;grid.length</code></li>
	<li><code>n ==&nbsp;grid[i].length</code></li>
	<li><code>1 &lt;= m &lt;= 50</code></li>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>-1000 &lt;= grid[i][j] &lt;= 1000</code></li>
	<li><code>0 &lt;= k &lt;= 100</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Matrix](https://leetcode.com/tag/matrix/), [Simulation](https://leetcode.com/tag/simulation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/shift-2d-grid/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(K)
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& A, int k) {
        int M = A.size(), N = A[0].size();
        k %= M * N;
        if (k == 0) return A;
        queue<int> q;
        for (int i = 0; i < M * N + k; ++i) {
            int j = i % (M * N), x = j / N, y = j % N;
            if (i < k) q.push(A[x][y]);
            else {
                q.push(A[x][y]);
                A[x][y] = q.front();
                q.pop();
            }
        }
        return A;
    }
};
```

## Solution 2. In-place Rotation

```cpp
// OJ: https://leetcode.com/problems/shift-2d-grid/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& A, int k) {
        int M = A.size(), N = A[0].size(), len = M * N;
        k %= len;
        if (k == 0) return A;
        for (int i = 0, cnt = 0; cnt < len; ++i) {
            int j = i, tmp = A[j / N][j % N]; 
            do {
                int next = (j + k) % len, nextVal = A[next / N][next % N];
                A[next / N][next % N] = tmp;
                tmp = nextVal;
                j = next;
                ++cnt;
            } while (j != i);
        }
        return A;
    }
};
```