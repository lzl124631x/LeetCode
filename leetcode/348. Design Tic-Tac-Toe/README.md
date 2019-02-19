# [348. Design Tic-Tac-Toe (Medium)](https://leetcode.com/problems/design-tic-tac-toe/)

<p>Design a Tic-tac-toe game that is played between two players on a <i>n</i> x <i>n</i> grid.
</p>

<p>You may assume the following rules:
</p><ol>
<li>A move is guaranteed to be valid and is placed on an empty block.</li>
<li>Once a winning condition is reached, no more moves is allowed.</li>
<li>A player who succeeds in placing <i>n</i> of their marks in a horizontal, vertical, or diagonal row wins the game.</li>
</ol>
<p></p>

<p><b>Example:</b><br>
</p><pre>Given <i>n</i> = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -&gt; Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -&gt; Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -&gt; Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -&gt; Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -&gt; Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -&gt; Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -&gt; Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
</pre>
<p></p>

<p><b>Follow up:</b><br>
Could you do better than O(<i>n</i><sup>2</sup>) per <code>move()</code> operation?
</p>

**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Valid Tic-Tac-Toe State (Medium)](https://leetcode.com/problems/valid-tic-tac-toe-state/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/design-tic-tac-toe/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N^2)
class TicTacToe {
private:
    vector<vector<int>> board;
    int n;
    int status(int row, int col) {
        int p = board[row][col];
        bool win = true;
        for (int i = 0; i < n && win; ++i) {
            if (board[row][i] != p) win = false;
        }
        if (win) return p;
        win = true;
        for (int i = 0; i < n && win; ++i) {
            if (board[i][col] != p) win = false;
        }
        if (win) return p;
        if (row == col) {
            win = true;
            for (int i = 0; i < n && win; ++i) {
                if (board[i][i] != p) win = false;
            }
            if (win) return p;
        }
        if (row + col == n - 1) {
            win = true;
            for (int i = 0; i < n && win; ++i) {
                if (board[i][n - 1 - i] != p) win = false;
            }
            if (win) return p;
        }
        return 0;
    }
public:
    TicTacToe(int n) : n(n) {
        board = vector<vector<int>>(n, vector<int>(n));
    }
    int move(int row, int col, int player) {
        board[row][col] = player;
        return status(row, col);
    }
};
```

## Solution 2. 

```cpp
// OJ: https://leetcode.com/problems/design-tic-tac-toe/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(N)
class TicTacToe {
private:
    vector<int> rows, cols;
    int n, diag = 0, anti = 0;
public:
    TicTacToe(int n) : n(n), rows(n, 0), cols(n, 0) {}
    
    int move(int row, int col, int player) {
        int d = player == 1 ? 1 : -1;
        rows[row] += d;
        cols[col] += d;
        if (row == col) diag += d;
        if (row + col == n - 1) anti += d;
        if (abs(rows[row]) == n
           || abs(cols[col]) == n
           || abs(diag) == n
           || abs(anti) == n) return player;
        return 0;
    }
};
```