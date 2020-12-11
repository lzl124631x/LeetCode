# [1222. Queens That Can Attack the King (Medium)](https://leetcode.com/problems/queens-that-can-attack-the-king/)

<p>On an <strong>8x8</strong> chessboard, there can be multiple Black Queens and one White King.</p>

<p>Given an array of integer coordinates <code>queens</code> that represents the positions of the Black Queens, and a pair of coordinates <code>king</code> that represent the position of the White King, return the coordinates of all the queens (in any order) that can attack the King.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/10/01/untitled-diagram.jpg" style="width: 321px; height: 321px;"></p>

<pre><strong>Input:</strong> queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
<strong>Output:</strong> [[0,1],[1,0],[3,3]]
<strong>Explanation:</strong>&nbsp; 
The queen at [0,1] can attack the king cause they're in the same row. 
The queen at [1,0] can attack the king cause they're in the same column. 
The queen at [3,3] can attack the king cause they're in the same diagnal. 
The queen at [0,4] can't attack the king cause it's blocked by the queen at [0,1]. 
The queen at [4,0] can't attack the king cause it's blocked by the queen at [1,0]. 
The queen at [2,4] can't attack the king cause it's not in the same row/column/diagnal as the king.
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/10/01/untitled-diagram-1.jpg" style="width: 321px; height: 321px;"></strong></p>

<pre><strong>Input:</strong> queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
<strong>Output:</strong> [[2,2],[3,4],[4,4]]
</pre>

<p><strong>Example 3:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/10/01/untitled-diagram-2.jpg" style="width: 321px; height: 321px;"></strong></p>

<pre><strong>Input:</strong> queens = [[5,6],[7,7],[2,1],[0,7],[1,6],[5,1],[3,7],[0,3],[4,0],[1,2],[6,3],[5,0],[0,4],[2,2],[1,1],[6,4],[5,4],[0,0],[2,6],[4,5],[5,2],[1,4],[7,5],[2,3],[0,5],[4,2],[1,0],[2,7],[0,1],[4,6],[6,1],[0,6],[4,3],[1,7]], king = [3,4]
<strong>Output:</strong> [[2,3],[1,4],[1,6],[3,7],[4,3],[5,4],[4,5]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= queens.length&nbsp;&lt;= 63</code></li>
	<li><code>queens[0].length == 2</code></li>
	<li><code>0 &lt;= queens[i][j] &lt;&nbsp;8</code></li>
	<li><code>king.length == 2</code></li>
	<li><code>0 &lt;= king[0], king[1] &lt; 8</code></li>
	<li>At most one piece is allowed in a cell.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/queens-that-can-attack-the-king/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& Q, vector<int>& K) {
        vector<vector<int>> ans;
        int board[8][8] = {};
        for (auto &v : Q) board[v[0]][v[1]] = 1;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                int x = K[0], y = K[1];
                while (x >= 0 && y >= 0 && x < 8 && y < 8) {
                    if (board[x][y]) {
                        ans.push_back({ x, y });
                        break;
                    }
                    x += dx;
                    y += dy;
                }
            }
        }
        return ans;
    }
};
```