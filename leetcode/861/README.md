# [861. Score After Flipping Matrix (Medium)](https://leetcode.com/problems/score-after-flipping-matrix/)

<p>We have a two dimensional matrix&nbsp;<code>A</code> where each value is <code>0</code> or <code>1</code>.</p>

<p>A move consists of choosing any row or column, and toggling each value in that row or column: changing all <code>0</code>s to <code>1</code>s, and all <code>1</code>s to <code>0</code>s.</p>

<p>After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.</p>

<p>Return the highest possible&nbsp;score.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[[0,0,1,1],[1,0,1,0],[1,1,0,0]]</span>
<strong>Output: </strong><span id="example-output-1">39</span>
<strong>Explanation:
</strong>Toggled to <span id="example-input-1-1">[[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39</span></pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 20</code></li>
	<li><code>1 &lt;= A[0].length &lt;= 20</code></li>
	<li><code>A[i][j]</code>&nbsp;is <code>0</code> or <code>1</code>.</li>
</ol>
</div>


**Companies**:  
[IIT Bombay](https://leetcode.com/company/iit-bombay)

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

1. Makes sure the first column only contains 1s by toggling a row if the first element in the row is 0.
2. For the remaining columns, if there are more 0s than 1s, toggle the column.

```cpp
// OJ: https://leetcode.com/problems/score-after-flipping-matrix/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        for (int i = 0; i < M; ++i) {
            if (A[i][0]) continue;
            for (int j = 0; j < N; ++j) A[i][j] = 1 - A[i][j];
        }
        for (int j = 1; j < N; ++j) {
            int one = 0;
            for (int i = 0; i < M; ++i) one += A[i][j];
            if (one * 2 >= M) continue;
            for (int i = 0; i < M; ++i) A[i][j] = 1 - A[i][j];
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) ans += A[i][j] * (1 << (N - j - 1));
        }
        return ans;
    }
};
```