# [37. Sudoku Solver (Hard)](https://leetcode.com/problems/sudoku-solver/)

<p>Write a program to solve a Sudoku puzzle by filling the empty cells.</p>

<p>A sudoku solution must satisfy <strong>all of the following rules</strong>:</p>

<ol>
	<li>Each of the digits <code>1-9</code> must occur exactly once in each row.</li>
	<li>Each of the digits <code>1-9</code> must occur exactly once in each column.</li>
	<li>Each of the digits <code>1-9</code> must occur exactly once in each of the 9 <code>3x3</code> sub-boxes of the grid.</li>
</ol>

<p>The <code>'.'</code> character indicates empty cells.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png" style="height:250px; width:250px">
<pre><strong>Input:</strong> board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
<strong>Output:</strong> [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
<strong>Explanation:</strong>&nbsp;The input board is shown above and the only valid solution is shown below:

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png" style="height:250px; width:250px">
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>board.length == 9</code></li>
	<li><code>board[i].length == 9</code></li>
	<li><code>board[i][j]</code> is a digit or <code>'.'</code>.</li>
	<li>It is <strong>guaranteed</strong> that the input board has only one solution.</li>
</ul>


**Companies**:  
[DoorDash](https://leetcode.com/company/doordash), [Microsoft](https://leetcode.com/company/microsoft), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Intuit](https://leetcode.com/company/intuit), [Bloomberg](https://leetcode.com/company/bloomberg), [Adobe](https://leetcode.com/company/adobe), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Valid Sudoku (Medium)](https://leetcode.com/problems/valid-sudoku/)
* [Unique Paths III (Hard)](https://leetcode.com/problems/unique-paths-iii/)

## Solution 1. Backtracking

```cpp
// OJ: https://leetcode.com/problems/sudoku-solver/
// Author: github.com/lzl124631x
// Time: O((9!)^9)
// Space: O(81)
class Solution {
    int row[9][9] = {}, col[9][9] = {}, box[9][9] = {};
    bool valid(int x, int y, int i) {
        return row[x][i] == 0 && col[y][i] == 0 && box[x / 3 * 3 + y / 3][i] == 0;
    }
    bool dfs(vector<vector<char>> &A, int x, int y) {
        if (y == 9) {
            ++x;
            y = 0;
        }
        if (x == 9) return true;
        if (A[x][y] == '.') {
            for (int i = 0; i < 9; ++i) {
                if (!valid(x, y, i)) continue;
                A[x][y] = '1' + i;
                row[x][i] = col[y][i] = box[x / 3 * 3 + y / 3][i] = 1;
                if (dfs(A, x, y + 1)) return true; 
                row[x][i] = col[y][i] = box[x / 3 * 3 + y / 3][i] = 0;
                A[x][y] = '.';
            }
            return false;
        }
        return dfs(A, x, y + 1);
    }
public:
    void solveSudoku(vector<vector<char>>& A) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (A[i][j] == '.') continue;
                row[i][A[i][j] - '1'] = 1;
                col[j][A[i][j] - '1'] = 1;
                box[i / 3 * 3 + j / 3][A[i][j] - '1'] = 1;
            }
        }
        dfs(A, 0, 0);
    }
};
```