# [2768. Number of Black Blocks (Medium)](https://leetcode.com/problems/number-of-black-blocks)

<p>You are given two integers <code>m</code> and <code>n</code> representing the dimensions of a&nbsp;<strong>0-indexed</strong>&nbsp;<code>m x n</code> grid.</p>
<p>You are also given a <strong>0-indexed</strong> 2D integer matrix <code>coordinates</code>, where <code>coordinates[i] = [x, y]</code> indicates that the cell with coordinates <code>[x, y]</code> is colored <strong>black</strong>. All cells in the grid that do not appear in <code>coordinates</code> are <strong>white</strong>.</p>
<p>A block is defined as a <code>2 x 2</code> submatrix of the grid. More formally, a block with cell <code>[x, y]</code> as its top-left corner where <code>0 &lt;= x &lt; m - 1</code> and <code>0 &lt;= y &lt; n - 1</code> contains the coordinates <code>[x, y]</code>, <code>[x + 1, y]</code>, <code>[x, y + 1]</code>, and <code>[x + 1, y + 1]</code>.</p>
<p>Return <em>a <strong>0-indexed</strong> integer array</em> <code>arr</code> <em>of size</em> <code>5</code> <em>such that</em> <code>arr[i]</code> <em>is the number of blocks that contains exactly</em> <code>i</code> <em><strong>black</strong> cells</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> m = 3, n = 3, coordinates = [[0,0]]
<strong>Output:</strong> [3,1,0,0,0]
<strong>Explanation:</strong> The grid looks like this:
<img alt="" src="https://assets.leetcode.com/uploads/2023/06/18/screen-shot-2023-06-18-at-44656-am.png" style="width: 150px; height: 128px;">
There is only 1 block with one black cell, and it is the block starting with cell [0,0].
The other 3 blocks start with cells [0,1], [1,0] and [1,1]. They all have zero black cells. 
Thus, we return [3,1,0,0,0]. 
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> m = 3, n = 3, coordinates = [[0,0],[1,1],[0,2]]
<strong>Output:</strong> [0,2,2,0,0]
<strong>Explanation:</strong> The grid looks like this:
<img alt="" src="https://assets.leetcode.com/uploads/2023/06/18/screen-shot-2023-06-18-at-45018-am.png" style="width: 150px; height: 128px;">
There are 2 blocks with two black cells (the ones starting with cell coordinates [0,0] and [0,1]).
The other 2 blocks have starting cell coordinates of [1,0] and [1,1]. They both have 1 black cell.
Therefore, we return [0,2,2,0,0].
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= coordinates.length &lt;= 10<sup>4</sup></code></li>
	<li><code>coordinates[i].length == 2</code></li>
	<li><code>0 &lt;= coordinates[i][0] &lt; m</code></li>
	<li><code>0 &lt;= coordinates[i][1] &lt; n</code></li>
	<li>It is guaranteed that <code>coordinates</code> contains pairwise distinct coordinates.</li>
</ul>

**Companies**:
[Square](https://leetcode.com/company/square), [Twitter](https://leetcode.com/company/twitter)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Enumeration](https://leetcode.com/tag/enumeration/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-black-blocks
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& A) {
        typedef long long LL;
        int d[4][2] = {{0,0},{0,-1},{-1,0},{-1,-1}};
        unordered_map<LL, int> cnt;
        for (auto &v : A) {
            LL x = v[0], y = v[1];
            for (auto &[dx, dy] : d) {
                LL a = x + dx, b = y + dy;
                if (a < 0 || b < 0 || a >= m - 1 || b >= n - 1) continue;
                cnt[a * (n - 1) + b]++;
            }
        }
        vector<LL> ans(5);
        for (auto &[_, c]: cnt) ans[c]++;
        ans[0] = (LL)(m - 1) * (n - 1) - accumulate(begin(ans), end(ans), 0LL);
        return ans;
    }
};
```