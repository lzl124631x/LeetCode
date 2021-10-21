# [1072. Flip Columns For Maximum Number of Equal Rows (Medium)](https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/)

<p>You are given an <code>m x n</code> binary matrix <code>matrix</code>.</p>

<p>You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from <code>0</code> to <code>1</code> or vice versa).</p>

<p>Return <em>the maximum number of rows that have all values equal after some number of flips</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> matrix = [[0,1],[1,1]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> After flipping no values, 1 row has all values equal.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> matrix = [[0,1],[1,0]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> After flipping values in the first column, both rows have equal values.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> matrix = [[0,0,0],[0,0,1],[1,1,0]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> After flipping values in the first two columns, the last two rows have equal values.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>matrix[i][j]</code> is either&nbsp;<code>0</code> or <code>1</code>.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Matrix](https://leetcode.com/tag/matrix/)

## Solution 1.

**Intuition**: If two rows `a` and `b` can be flipped to be equal, either `a == b` or `a == ~b`. So we can:

1. For each row, if the first element is not `0`, flip the row.
1. Find the maximum count of the rows having the same content.

```cpp
// OJ: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& A) {
        int N = A[0].size(), ans = 0;
        unordered_map<string, int> cnt;
        for (auto &row : A) {
            bool flip = row[0] == 0;
            string s;
            for (int i = 0; i < N; ++i) s += '0' + (row[i] ^ flip);
            ans = max(ans, ++cnt[s]);
        }
        return ans;
    }
};
```