# [840. Magic Squares In Grid (Easy)](https://leetcode.com/problems/magic-squares-in-grid/)

<p>A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers <strong>from 1 to 9</strong> such that each row, column, and both diagonals all have the same sum.</p>

<p>Given an <code>grid</code>&nbsp;of integers, how many 3 x 3 "magic square" subgrids are there?&nbsp; (Each subgrid is contiguous).</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>[[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]
<strong>Output: </strong>1
<strong>Explanation: </strong>
The following subgrid is a 3 x 3 magic square:
438
951
276

while this one is not:
384
519
762

In total, there is only one magic square inside the given grid.
</pre>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= grid.length&nbsp;&lt;= 10</code></li>
	<li><code>1 &lt;= grid[0].length&nbsp;&lt;= 10</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 15</code></li>
</ol>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/magic-squares-in-grid/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
private:
    bool isMagic(vector<vector<int>>& grid, int x, int y) {
        if (grid[x + 1][y + 1] != 5) return false;
        int cnt[9] = {0};
        for (int i = 0; i < 3; ++i) {
            int xSum = 0, ySum = 0;
            for (int j = 0; j < 3; ++j) {
                int v = grid[x + i][y + j];
                if (v < 1 || v > 9 || cnt[v - 1]) return false;
                cnt[v - 1]++;
                xSum += v;
                ySum += grid[x + j][y + i];
            }
            if (xSum != 15 || ySum != 15) return false;
        }
        return (grid[x][y] + grid[x + 2][y + 2] == 10)
            && (grid[x][y + 2] + grid[x + 2][y] == 10);
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size(), cnt = 0;
        for (int i = 0; i <= M - 3; ++i) {
            for (int j = 0; j <= N - 3; ++j) {
                if (isMagic(grid, i, j)) ++cnt;
            }
        }
        return cnt;
    }
};
```