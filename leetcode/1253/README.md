# [1253. Reconstruct a 2-Row Binary Matrix (Medium)](https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/)

<p>Given the following details of a matrix with <code>n</code> columns and <code>2</code> rows :</p>

<ul>
	<li>The matrix is a binary matrix, which means each element in the matrix can be <code>0</code> or <code>1</code>.</li>
	<li>The sum of elements of the 0-th(upper) row is given as <code>upper</code>.</li>
	<li>The sum of elements of the 1-st(lower) row is given as <code>lower</code>.</li>
	<li>The sum of elements in the i-th column(0-indexed) is <code>colsum[i]</code>, where <code>colsum</code> is given as an integer array with length <code>n</code>.</li>
</ul>

<p>Your task is to reconstruct the matrix with <code>upper</code>, <code>lower</code> and <code>colsum</code>.</p>

<p>Return it as a 2-D integer array.</p>

<p>If there are more than one valid solution, any of them will be accepted.</p>

<p>If no valid solution exists, return an empty 2-D array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> upper = 2, lower = 1, colsum = [1,1,1]
<strong>Output:</strong> [[1,1,0],[0,0,1]]
<strong>Explanation: </strong>[[1,0,1],[0,1,0]], and [[0,1,1],[1,0,0]] are also correct answers.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> upper = 2, lower = 3, colsum = [2,2,1,1]
<strong>Output:</strong> []
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> upper = 5, lower = 5, colsum = [2,1,2,0,1,0,1,2,0,1]
<strong>Output:</strong> [[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= colsum.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= upper, lower &lt;= colsum.length</code></li>
	<li><code>0 &lt;= colsum[i] &lt;= 2</code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Find Valid Matrix Given Row and Column Sums (Medium)](https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        if (accumulate(begin(colsum), end(colsum), 0) != upper + lower) return {};
        vector<vector<int>> ans(2, vector<int>(colsum.size()));
        for (int i = 0; i < colsum.size(); ++i) {
            if (colsum[i] == 2) --upper, --lower, ans[0][i] = ans[1][i] = 1;
            if (upper < 0 || lower < 0) return {};
        }
        for (int i = 0; i < colsum.size(); ++i) {
            if (colsum[i] != 1) continue;
            if (upper) --upper, ans[0][i] = 1;
            else --lower, ans[1][i] = 1;
            if (upper < 0 || lower < 0) return {};
        }
        return ans;
    }
};
```