# [1351. Count Negative Numbers in a Sorted Matrix (Easy)](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/)

<p>Given a <code>m&nbsp;* n</code>&nbsp;matrix <code>grid</code>&nbsp;which is sorted in non-increasing order both row-wise and column-wise.&nbsp;</p>

<p>Return the number of <strong>negative</strong> numbers in&nbsp;<code>grid</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
<strong>Output:</strong> 8
<strong>Explanation:</strong> There are 8 negatives number in the matrix.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[3,2],[1,0]]
<strong>Output:</strong> 0
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [[1,-1],[-1,-1]]
<strong>Output:</strong> 3
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> grid = [[-1]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>-100 &lt;= grid[i][j] &lt;= 100</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for (auto &row : grid) {
            for (int c : row) {
                if (c < 0) ++ans;
            }
        }
        return ans;
    }
};
```

## Solution 2. Binary Search

```cpp
// OJ: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
// Author: github.com/lzl124631x
// Time: O(MlogN)
// Space: O(1)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for (auto &row : grid) {
            ans += upper_bound(row.rbegin(), row.rend(), -1) - row.rbegin();
        }
        return ans;
    }
};
```

## Solution 3. Search Break Points

Traverse from upper right to lower left.

```cpp
// OJ: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
// Author: github.com/lzl124631x
// Time: O(M+N)
// Space: O(1)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size(), x = 0, y = N - 1, ans = 0;
        while (x < M) {
            while (y >= 0 && grid[x][y] < 0) --y;
            ans += N - 1 - y;
            ++x;
        }
        return ans;
    }
};
```