# [1314. Matrix Block Sum (Medium)](https://leetcode.com/problems/matrix-block-sum/)

Given a <code>m * n</code> matrix&nbsp;<code>mat</code>&nbsp;and an integer <code>K</code>, return a matrix <code>answer</code> where each <code>answer[i][j]</code>&nbsp;is the sum of all elements <code>mat[r][c]</code> for <code>i - K &lt;= r &lt;= i + K, j - K &lt;= c &lt;= j + K</code>, and <code>(r, c)</code> is a valid position in the matrix.
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
<strong>Output:</strong> [[12,21,16],[27,45,33],[24,39,28]]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
<strong>Output:</strong> [[45,45,45],[45,45,45],[45,45,45]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m ==&nbsp;mat.length</code></li>
	<li><code>n ==&nbsp;mat[i].length</code></li>
	<li><code>1 &lt;= m, n, K &lt;= 100</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 100</code></li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/matrix-block-sum/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& A, int K) {
        int M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            int sum = 0;
            for (int j = 0; j < N; ++j) {
                sum += A[i][j];
                A[i][j] = sum + (i - 1 >= 0 ? A[i - 1][j] : 0);
            }
        }
        vector<vector<int>> ans(M, vector<int>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int minr = max(-1, i - K - 1), maxr = min(M - 1, i + K), minc = max(-1, j - K - 1), maxc = min(N - 1, j + K);
                int a = A[maxr][maxc], b = minc == -1 ? 0 : A[maxr][minc], c = minr == -1 ? 0 : A[minr][maxc], d = minr == -1 || minc == -1 ? 0 : A[minr][minc];
                ans[i][j] = a - b - c + d;
            }
        }
        return ans;
    }
};
```