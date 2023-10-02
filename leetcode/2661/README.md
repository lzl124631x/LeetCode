# [2661. First Completely Painted Row or Column (Medium)](https://leetcode.com/problems/first-completely-painted-row-or-column)

<p>You are given a <strong>0-indexed</strong> integer array <code>arr</code>, and an <code>m x n</code> integer <strong>matrix</strong> <code>mat</code>. <code>arr</code> and <code>mat</code> both contain <strong>all</strong> the integers in the range <code>[1, m * n]</code>.</p>

<p>Go through each index <code>i</code> in <code>arr</code> starting from index <code>0</code> and paint the cell in <code>mat</code> containing the integer <code>arr[i]</code>.</p>

<p>Return <em>the smallest index</em> <code>i</code> <em>at which either a row or a column will be completely painted in</em> <code>mat</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="image explanation for example 1" /><img alt="image explanation for example 1" src="https://assets.leetcode.com/uploads/2023/01/18/grid1.jpg" style="width: 321px; height: 81px;" />
<pre>
<strong>Input:</strong> arr = [1,3,4,2], mat = [[1,4],[2,3]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="image explanation for example 2" src="https://assets.leetcode.com/uploads/2023/01/18/grid2.jpg" style="width: 601px; height: 121px;" />
<pre>
<strong>Input:</strong> arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The second column becomes fully painted at arr[3].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n = mat[i].length</code></li>
	<li><code>arr.length == m * n</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i], mat[r][c] &lt;= m * n</code></li>
	<li>All the integers of <code>arr</code> are <strong>unique</strong>.</li>
	<li>All the integers of <code>mat</code> are <strong>unique</strong>.</li>
</ul>


**Companies**:
[Citadel](https://leetcode.com/company/citadel)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table), [Matrix](https://leetcode.com/tag/matrix)

**Similar Questions**:
* [Check if Every Row and Column Contains All Numbers (Easy)](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers)
* [Difference Between Ones and Zeros in Row and Column (Medium)](https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/first-completely-painted-row-or-column
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int firstCompleteIndex(vector<int>& A, vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        vector<int> row(m), col(n);
        vector<pair<int, int>> index(A.size() + 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                index[M[i][j]] = {i, j};
            }
        }
        for (int i = 0; i < A.size(); ++i) {
            auto &[x, y] = index[A[i]];
            if (++row[x] == n || ++col[y] == m) return i;
        }
        return -1;
    }
};
```