# [1275. Find Winner on a Tic Tac Toe Game (Easy)](https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/)

<p>Tic-tac-toe is played&nbsp;by&nbsp;two players <em>A</em> and <em>B</em> on a&nbsp;<i>3</i>&nbsp;x&nbsp;<i>3</i>&nbsp;grid.</p>

<p>Here are the rules of Tic-Tac-Toe:</p>

<ul>
	<li>Players take turns placing characters into empty squares (" ").</li>
	<li>The first player <em>A</em> always places "X" characters, while the second player <em>B</em>&nbsp;always places "O" characters.</li>
	<li>"X" and "O" characters are always placed into empty squares, never on filled ones.</li>
	<li>The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.</li>
	<li>The game also ends if all squares are non-empty.</li>
	<li>No more moves can be played if the game is over.</li>
</ul>

<p>Given an array <code>moves</code> where each element&nbsp;is another array of size 2 corresponding to the row and column of the grid where they mark their respective character in the order in which <em>A</em> and <em>B</em> play.</p>

<p>Return the winner of the game if it exists (<em>A</em> or <em>B</em>), in case the game ends in a draw return "Draw", if there are still movements to play return "Pending".</p>

<p>You can assume that&nbsp;<code>moves</code> is&nbsp;<strong>valid</strong> (It follows the rules of Tic-Tac-Toe),&nbsp;the grid is initially empty and <em>A</em> will play <strong>first</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
<strong>Output:</strong> "A"
<strong>Explanation:</strong> "A" wins, he always plays first.
"X  "    "X  "    "X  "    "X  "    "<strong>X</strong>  "
"   " -&gt; "   " -&gt; " X " -&gt; " X " -&gt; " <strong>X</strong> "
"   "    "O  "    "O  "    "OO "    "OO<strong>X</strong>"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
<strong>Output:</strong> "B"
<strong>Explanation:</strong> "B" wins.
"X  "    "X  "    "XX "    "XXO"    "XXO"    "XX<strong>O</strong>"
"   " -&gt; " O " -&gt; " O " -&gt; " O " -&gt; "XO " -&gt; "X<strong>O</strong> " 
"   "    "   "    "   "    "   "    "   "    "<strong>O</strong>  "
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
<strong>Output:</strong> "Draw"
<strong>Explanation:</strong> The game ends in a draw since there are no moves to make.
"XXO"
"OOX"
"XOX"
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> moves = [[0,0],[1,1]]
<strong>Output:</strong> "Pending"
<strong>Explanation:</strong> The game has not finished yet.
"X  "
" O "
"   "
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= moves.length &lt;= 9</code></li>
	<li><code>moves[i].length == 2</code></li>
	<li><code>0 &lt;= moves[i][j] &lt;= 2</code></li>
	<li>There are no repeated elements on <code>moves</code>.</li>
	<li><code>moves</code> follow the rules of tic tac toe.</li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
    string check(int A[3][3]) {
        for (int i = 0; i < 3; ++i) {
            int j = 1;
            while (j < 3 && A[i][0] != 0 && A[i][j] == A[i][0]) ++j;
            if (j == 3) return A[i][0] == 1 ? "A" : "B";
            j = 1;
            while (j < 3 && A[0][i] != 0 && A[j][i] == A[0][i]) ++j; 
            if (j == 3) return A[0][i] == 1 ? "A" : "B";
        }
        int i = 1;
        while (i < 3 && A[0][0] != 0 && A[i][i] == A[0][0]) ++i; 
        if (i == 3) return A[0][0] == 1 ? "A" : "B";
        i = 1;
        while (i < 3 && A[0][2] != 0 && A[i][2 - i] == A[0][2]) ++i;
        if (i == 3) return A[0][2] == 1 ? "A" : "B";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (A[i][j] == 0) return "Pending";
            }
        }
        return "Draw";
    }
public:
    string tictactoe(vector<vector<int>>& moves) {
        int A[3][3] = {}, ch = 1;
        for (auto &m : moves) {
            A[m[0]][m[1]] = ch;
            ch = ch == 1 ? 2 : 1;
        }
        return check(A);
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int A[8] = {}, B[8] = {};
        for (int i = 0; i < moves.size(); ++i) {
            int r = moves[i][0], c = moves[i][1];
            if (i % 2 == 0 && (++A[r] == 3 || ++A[3 + c] == 3 || (r == c && ++A[6] == 3) || (r == 2 - c && ++A[7] == 3))) return "A";
            if (i % 2 && (++B[r] == 3 || ++B[3 + c] == 3 || (r == c && ++B[6] == 3) || (r == 2 - c && ++B[7] == 3))) return "B";
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
```