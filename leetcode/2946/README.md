# [2946. Matrix Similarity After Cyclic Shifts (Easy)](https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts)

<p>You are given a <strong>0-indexed</strong> <code>m x n</code> integer matrix <code>mat</code> and an integer <code>k</code>. You have to cyclically <strong>right</strong> shift <strong>odd</strong> indexed rows <code>k</code> times and cyclically <strong>left</strong> shift <strong>even</strong> indexed rows <code>k</code> times.</p>

<p>Return <code>true</code> <em>if the initial and final matrix are exactly the same and </em><code>false</code> <em>otherwise.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2
<strong>Output:</strong> true
<strong>Explanation:</strong>
<img alt="" src="https://assets.leetcode.com/uploads/2023/10/29/similarmatrix.png" style="width: 500px; height: 117px;" />

Initially, the matrix looks like the first figure. 
Second figure represents the state of the matrix after one right and left cyclic shifts to even and odd indexed rows.
Third figure is the final state of the matrix after two cyclic shifts which is similar to the initial matrix.
Therefore, return true.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> mat = [[2,2],[2,2]], k = 3
<strong>Output:</strong> true
<strong>Explanation:</strong> As all the values are equal in the matrix, even after performing cyclic shifts the matrix will remain the same. Therefeore, we return true.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> mat = [[1,2]], k = 1
<strong>Output:</strong> false
<strong>Explanation:</strong> After one cyclic shift, mat = [[2,1]] which is not equal to the initial matrix. Therefore we return false.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= mat.length &lt;= 25</code></li>
	<li><code>1 &lt;= mat[i].length &lt;= 25</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 25</code></li>
	<li><code>1 &lt;= k &lt;= 50</code></li>
</ul>


**Hints**:
* You can reduce <code>k</code> shifts to <code>(k % n)</code> shifts as after <code>n</code> shifts the matrix will become similar to the initial matrix.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    bool areSimilar(vector<vector<int>>& A, int k) {
        int M = A.size(), N = A[0].size();
        k %= N;
        if (k == 0) return true;
        for (int i = 0; i < M; ++i) { 
            k = -k;
            for (int j = 0; j < N; ++j) {
                if (A[i][j] != A[i][(j + k + N) % N]) return false;
            }
        }
        return true;
    }
};
```