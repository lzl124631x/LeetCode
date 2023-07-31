# [2639. Find the Width of Columns of a Grid (Easy)](https://leetcode.com/problems/find-the-width-of-columns-of-a-grid)

<p>You are given a <strong>0-indexed</strong> <code>m x n</code> integer matrix <code>grid</code>. The width of a column is the maximum <strong>length </strong>of its integers.</p>
<ul>
	<li>For example, if <code>grid = [[-10], [3], [12]]</code>, the width of the only column is <code>3</code> since <code>-10</code> is of length <code>3</code>.</li>
</ul>
<p>Return <em>an integer array</em> <code>ans</code> <em>of size</em> <code>n</code> <em>where</em> <code>ans[i]</code> <em>is the width of the</em> <code>i<sup>th</sup></code> <em>column</em>.</p>
<p>The <strong>length</strong> of an integer <code>x</code> with <code>len</code> digits is equal to <code>len</code> if <code>x</code> is non-negative, and <code>len + 1</code> otherwise.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> grid = [[1],[22],[333]]
<strong>Output:</strong> [3]
<strong>Explanation:</strong> In the 0<sup>th</sup> column, 333 is of length 3.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> grid = [[-15,1,3],[15,7,12],[5,6,-2]]
<strong>Output:</strong> [3,1,2]
<strong>Explanation:</strong> 
In the 0<sup>th</sup> column, only -15 is of length 3.
In the 1<sup>st</sup> column, all integers are of length 1. 
In the 2<sup>nd</sup> column, both 12 and -2 are of length 2.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100 </code></li>
	<li><code>-10<sup>9</sup> &lt;= grid[r][c] &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[Samsung](https://leetcode.com/company/samsung)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Next Greater Numerically Balanced Number (Medium)](https://leetcode.com/problems/next-greater-numerically-balanced-number/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-the-width-of-columns-of-a-grid
// Author: github.com/lzl124631x
// Time: O(MND)
// Space: O(D) where D is the length of the longest A[i][j]
class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        vector<int> ans(N);
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < M; ++i) {
                ans[j] = max(ans[j], (int)to_string(A[i][j]).size());
            }
        }
        return ans;
    }
};
```