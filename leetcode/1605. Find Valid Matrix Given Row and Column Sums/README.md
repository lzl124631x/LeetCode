# [1605. Find Valid Matrix Given Row and Column Sums (Medium)](https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/)

<p>You are given two arrays <code>rowSum</code> and <code>colSum</code> of non-negative integers where <code>rowSum[i]</code> is the sum of the elements in the <code>i<sup>th</sup></code> row and <code>colSum[j]</code> is the sum of the elements of the <code>j<sup>th</sup></code> column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.</p>

<p>Find any matrix of <strong>non-negative</strong> integers of size <code>rowSum.length x colSum.length</code> that satisfies the <code>rowSum</code> and <code>colSum</code> requirements.</p>

<p>Return <em>a 2D array representing <strong>any</strong> matrix that fulfills the requirements</em>. It's guaranteed that <strong>at least one </strong>matrix that fulfills the requirements exists.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> rowSum = [3,8], colSum = [4,7]
<strong>Output:</strong> [[3,0],
         [1,7]]
<strong>Explanation:</strong>
0th row: 3 + 0 = 0 == rowSum[0]
1st row: 1 + 7 = 8 == rowSum[1]
0th column: 3 + 1 = 4 == colSum[0]
1st column: 0 + 7 = 7 == colSum[1]
The row and column sums match, and all matrix elements are non-negative.
Another possible matrix is: [[1,2],
                             [3,5]]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> rowSum = [5,7,10], colSum = [8,6,8]
<strong>Output:</strong> [[0,5,0],
         [6,1,0],
         [2,0,8]]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> rowSum = [14,9], colSum = [6,9,8]
<strong>Output:</strong> [[0,9,5],
         [6,0,3]]
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> rowSum = [1,0], colSum = [1]
<strong>Output:</strong> [[1],
         [0]]
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> rowSum = [0], colSum = [0]
<strong>Output:</strong> [[0]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= rowSum.length, colSum.length &lt;= 500</code></li>
	<li><code>0 &lt;= rowSum[i], colSum[i] &lt;= 10<sup>8</sup></code></li>
	<li><code>sum(rows) == sum(columns)</code></li>
</ul>

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Reconstruct a 2-Row Binary Matrix (Medium)](https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/)

## Solution 1. Greedy

Fill row by row and column by column. For each cell `(i, j)`, we fill `ans[i][j] = min(rowSum[i], colSum[j])` and deduct `ans[i][j]` from `rowSum[i]` and `colSum[j]`.

```cpp
// OJ: https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1) extra space
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& R, vector<int>& C) {
        int M = R.size(), N = C.size(), d;
        vector<vector<int>> ans(M, vector<int>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                d = ans[i][j] = min(R[i], C[j]);
                R[i] -= d;
                C[j] -= d;
            }
        }
        return ans;
    }
};
```

## Solution 2. Greedy

We just need to go from the top-left to the bottom-right. Once `R[i]` or `C[j]` becomes `0`, the rest of the elements in row `i` or column `j` must be `0`s, so we can increment `i` or `j`.

```cpp
// OJ: https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/
// Author: github.com/lzl124631x
// Time: O(MN) for initialization, O(M + N) for processing
// Space: O(1) extra space
// Ref: https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/discuss/876845/JavaC%2B%2BPython-Easy-and-Concise-with-Prove
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& R, vector<int>& C) {
        int M = R.size(), N = C.size(), i = 0, j = 0, d;
        vector<vector<int>> ans(M, vector<int>(N));
        while (i < M && j < N) {
            d = ans[i][j] = min(R[i], C[j]);
            if ((R[i] -= d) == 0) ++i;
            if ((C[j] -= d) == 0) ++j;
        }
        return ans;
    }
};
```