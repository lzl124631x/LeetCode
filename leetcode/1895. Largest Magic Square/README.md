# [1895. Largest Magic Square (Medium)](https://leetcode.com/problems/largest-magic-square/)

<p>A <code>k x k</code> <strong>magic square</strong> is a <code>k x k</code> grid filled with integers such that every row sum, every column sum, and both diagonal sums are <strong>all equal</strong>. The integers in the magic square <strong>do not have to be distinct</strong>. Every <code>1 x 1</code> grid is trivially a <strong>magic square</strong>.</p>

<p>Given an <code>m x n</code> integer <code>grid</code>, return <em>the <strong>size</strong> (i.e., the side length </em><code>k</code><em>) of the <strong>largest magic square</strong> that can be found within this grid</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/29/magicsquare-grid.jpg" style="width: 413px; height: 335px;">
<pre><strong>Input:</strong> grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The largest magic square has a size of 3.
Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
- Diagonal sums: 5+4+3 = 6+4+2 = 12
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/29/magicsquare2-grid.jpg" style="width: 333px; height: 255px;">
<pre><strong>Input:</strong> grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>6</sup></code></li>
</ul>


**Companies**:  
[Wayfair](https://leetcode.com/company/wayfair)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Magic Squares In Grid (Medium)](https://leetcode.com/problems/magic-squares-in-grid/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/largest-magic-square/
// Author: github.com/lzl124631x
// Time: O(MN * min(M, N)^3)
// Space: O(1)
class Solution {
    int M, N;
    bool isMagic(vector<vector<int>>& G, int x, int y, int len) {
        int a = 0, b = 0;
        for (int i = 0; i < len; ++i) {
            a += G[x + i][y + i];
            b += G[x + i][y + len - 1 - i];
        }
        if (a != b) return false;
        for (int i = 0; i < len; ++i) {
            int row = 0, col = 0;
            for (int j = 0; j < len; ++j) {
                row += G[x + i][y + j];
                col += G[x + j][y + i];
            }
            if (row != a || col != a) return false;
        }
        return true;
    }
public:
    int largestMagicSquare(vector<vector<int>>& G) {
        M = G.size(), N = G[0].size();
        for (int i = min(M, N); i >= 2; --i) {
            for (int x = 0; x <= M - i; ++x) {
                for (int y = 0; y <= N - i; ++y) {
                    if (isMagic(G, x, y, i)) return i;
                }
            }
        }
        return 1;
    }
};
```