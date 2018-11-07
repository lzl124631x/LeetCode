# [794. Valid Tic-Tac-Toe State (Medium)](https://leetcode.com/problems/valid-tic-tac-toe-state/)

A Tic-Tac-Toe board is given as a string array `board`. Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

The `board` is a 3 x 3 array, and consists of characters `" "`, `"X"`, and `"O"`.  The " " character represents an empty square.

Here are the rules of Tic-Tac-Toe:

*   Players take turns placing characters into empty squares (" ").
*   The first player always places "X" characters, while the second player always places "O" characters.
*   "X" and "O" characters are always placed into empty squares, never filled ones.
*   The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
*   The game also ends if all squares are non-empty.
*   No more moves can be played if the game is over.

**Example 1:**  
**Input:** board = \["O  ", "   ", "   "\]  
**Output:** false  
**Explanation:** The first player always plays "X".

**Example 2:**  
**Input:** board = \["XOX", " X ", "   "\]  
**Output:** false  
**Explanation:** Players take turns making moves.

**Example 3:**  
**Input:** board = \["XXX", "   ", "OOO"\]  
**Output:** false

**Example 4:**  
**Input:** board = \["XOX", "O O", "XOX"\]  
**Output:** true

**Note:**

*   `board` is a length-3 array of strings, where each string `board[i]` has length 3.
*   Each `board[i][j]` is a character in the set `{" ", "X", "O"}`.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/valid-tic-tac-toe-state/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
private:
    int count(vector<string>& board, char target){ 
        int cnt = 0;
        for (auto row : board) {
            for (char c : row) {
                if (c == target) ++cnt;
            }
        }
        return cnt;
    }
    bool testWin(vector<string>& board, char target) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] != target) break;
                if (j == 2) return true;
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[j][i] != target) break;
                if (j == 2) return true;
            }
        }
        for (int i = 0; i < 3; ++i) {
            if (board[i][i] != target) break;
            if (i == 2) return true;
        }
        for (int i = 0; i < 3; ++i) {
            if (board[i][2 - i] != target) break;
            if (i == 2) return true;
        }
        return false;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        int xCnt = count(board, 'X');
        int oCnt = count(board, 'O');
        if (xCnt != oCnt && xCnt != oCnt + 1) return false;
        bool xWin = testWin(board, 'X');
        bool oWin = testWin(board, 'O');
        if (xWin && oWin) return false;
        if (!xWin && !oWin) return true;
        return (xWin && xCnt == oCnt + 1) || (oWin && xCnt == oCnt);
    }
};
```