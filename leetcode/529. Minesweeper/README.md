# [529. Minesweeper (Medium)](https://leetcode.com/problems/minesweeper/)

<p>Let's play the minesweeper game (<a href="https://en.wikipedia.org/wiki/Minesweeper_(video_game)" target="_blank">Wikipedia</a>, <a href="http://minesweeperonline.com" target="_blank">online game</a>)!</p>

<p>You are given an <code>m x n</code> char matrix <code>board</code> representing the game board where:</p>

<ul>
	<li><code>'M'</code> represents an unrevealed mine,</li>
	<li><code>'E'</code> represents an unrevealed empty square,</li>
	<li><code>'B'</code> represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),</li>
	<li>digit (<code>'1'</code> to <code>'8'</code>) represents how many mines are adjacent to this revealed square, and</li>
	<li><code>'X'</code> represents a revealed mine.</li>
</ul>

<p>You are also given an integer array <code>click</code> where <code>click = [click<sub>r</sub>, click<sub>c</sub>]</code> represents the next click position among all the unrevealed squares (<code>'M'</code> or <code>'E'</code>).</p>

<p>Return <em>the board after revealing this position according to the following rules</em>:</p>

<ol>
	<li>If a mine <code>'M'</code> is revealed, then the game is over. You should change it to <code>'X'</code>.</li>
	<li>If an empty square <code>'E'</code> with no adjacent mines is revealed, then change it to a revealed blank <code>'B'</code> and all of its adjacent unrevealed squares should be revealed recursively.</li>
	<li>If an empty square <code>'E'</code> with at least one adjacent mine is revealed, then change it to a digit (<code>'1'</code> to <code>'8'</code>) representing the number of adjacent mines.</li>
	<li>Return the board when no more squares will be revealed.</li>
</ol>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/12/minesweeper_example_1.png" style="width: 500px; max-width: 400px; height: 269px;">
<pre><strong>Input:</strong> board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]], click = [3,0]
<strong>Output:</strong> [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
</pre>

<p><strong>Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/12/minesweeper_example_2.png" style="width: 500px; max-width: 400px; height: 275px;">
<pre><strong>Input:</strong> board = [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]], click = [1,2]
<strong>Output:</strong> [["B","1","E","1","B"],["B","1","X","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>board[i][j]</code> is either <code>'M'</code>, <code>'E'</code>, <code>'B'</code>, or a digit from <code>'1'</code> to <code>'8'</code>.</li>
	<li><code>click.length == 2</code></li>
	<li><code>0 &lt;= click<sub>r</sub> &lt; m</code></li>
	<li><code>0 &lt;= click<sub>c</sub> &lt; n</code></li>
	<li><code>board[click<sub>r</sub>][click<sub>c</sub>]</code> is either <code>'M'</code> or <code>'E'</code>.</li>
</ul>


**Companies**:  
[Uber](https://leetcode.com/company/uber), [LiveRamp](https://leetcode.com/company/liveramp), [Facebook](https://leetcode.com/company/facebook), [Cruise Automation](https://leetcode.com/company/cruise-automation), [Microsoft](https://leetcode.com/company/microsoft), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Detonate the Maximum Bombs (Medium)](https://leetcode.com/problems/detonate-the-maximum-bombs/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/minesweeper/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& A, vector<int>& click) {
        int M = A.size(), N = A[0].size();
        queue<pair<int, int>> q{{{click[0], click[1]}}};
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            if (A[x][y] == 'M') {
                A[x][y] = 'X';
                continue;
            }
            int cnt = 0;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue;
                    int a = x + dx, b = y + dy;
                    if (a < 0 || a >= M || b < 0 || b >= N) continue;
                    cnt += A[a][b] == 'M';
                }
            }
            if (cnt) A[x][y] = '0' + cnt;
            else {
                A[x][y] = 'B';
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (dx == 0 && dy == 0) continue;
                        int a = x + dx, b = y + dy;
                        if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] != 'E') continue;
                        A[a][b] = '#';
                        q.emplace(a, b);
                    }
                }
            }
        }
        return A;
    }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/minesweeper/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& A, vector<int>& click) {
        int M = A.size(), N = A[0].size();
        function<void(int, int)> dfs = [&](int x, int y) {
            if (A[x][y] == 'M') {
                A[x][y] = 'X';
                return;
            }
            int cnt = 0;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue;
                    int a = x + dx, b = y + dy;
                    if (a < 0 || a >= M || b < 0 || b >= N) continue;
                    cnt += A[a][b] == 'M';
                }
            }
            if (cnt) A[x][y] = '0' + cnt;
            else {
                A[x][y] = 'B';
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (dx == 0 && dy == 0) continue;
                        int a = x + dx, b = y + dy;
                        if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] != 'E') continue;
                        dfs(a, b);
                    }
                }
            }
        };
        dfs(click[0], click[1]);
        return A;
    }
};
```