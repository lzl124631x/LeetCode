# [723. Candy Crush (Medium)](https://leetcode.com/problems/candy-crush/)

<p>This question is about implementing a basic elimination algorithm for Candy Crush.</p>

<p>Given a 2D integer array <code>board</code> representing the grid of candy, different positive integers <code>board[i][j]</code> represent different types of candies. A value of <code>board[i][j] = 0</code> represents that the cell at position <code>(i, j)</code> is empty. The given board represents the state of the game following the player's move. Now, you need to restore the board to a <i>stable state</i> by crushing candies according to the following rules:</p>

<ol>
	<li>If three or more candies of the same type are adjacent vertically or horizontally, "crush" them all at the same time - these positions become empty.</li>
	<li>After crushing all candies simultaneously, if an empty space on the board has candies on top of itself, then these candies will drop until they hit a candy or bottom at the same time. (No new candies will drop outside the top boundary.)</li>
	<li>After the above steps, there may exist more candies that can be crushed. If so, you need to repeat the above steps.</li>
	<li>If there does not exist more candies that can be crushed (ie. the board is <i>stable</i>), then return the current board.</li>
</ol>

<p>You need to perform the above rules until the board becomes stable, then return the current board.</p>

<p>&nbsp;</p>

<p><b>Example:</b></p>

<pre style="white-space: pre-line"><b>Input:</b>
board = 
[[110,5,112,113,114],[210,211,5,213,214],[310,311,3,313,314],[410,411,412,5,414],[5,1,512,3,3],[610,4,1,613,614],[710,1,2,713,714],[810,1,2,1,1],[1,1,2,2,2],[4,1,4,4,1014]]

<b>Output:</b>
[[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[110,0,0,0,114],[210,0,0,0,214],[310,0,0,113,314],[410,0,0,213,414],[610,211,112,313,614],[710,311,412,613,714],[810,411,512,713,1014]]

<b>Explanation:</b> 
<img src="https://assets.leetcode.com/uploads/2018/10/12/candy_crush_example_2.png" style="width: 777px; height: 532px;">
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ol>
	<li>The length of <code>board</code> will be in the range [3, 50].</li>
	<li>The length of <code>board[i]</code> will be in the range [3, 50].</li>
	<li>Each <code>board[i][j]</code> will initially start as an integer in the range [1, 2000].</li>
</ol>


**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/candy-crush/
// Author: github.com/lzl124631x
// Time: O((MN)^2)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int M = board.size(), N = board[0].size();
        bool found = false;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j + 2 < N; ++j) {
                int v = abs(board[i][j]);
                if (!v || abs(board[i][j + 1]) != v || abs(board[i][j + 2]) != v) continue;
                found = true;
                board[i][j] = board[i][j + 1] = board[i][j + 2] = -v;
            }
        }
        for (int i = 0; i + 2 < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int v = abs(board[i][j]);
                if (!v || abs(board[i + 1][j]) != v || abs(board[i + 2][j]) != v) continue;
                found = true;
                board[i][j] = board[i + 1][j] = board[i + 2][j] = -v;
            }
        }
        for (int j = 0; j < N; ++j) {
            int k = M - 1;
            for (int i = M - 1; i >= 0; --i) {
                if (board[i][j] <= 0) continue;
                board[k--][j] = board[i][j];
            }
            while (k >= 0) board[k--][j] = 0;
        }
        return board;
        return found ? candyCrush(board) : board;
    }
};
```

## Solution 2.

Memo to myself: NEVER EVER be lazy to wrap bitwise operators in parenthesis!!

I used to write `c & (1 << k) == 0`. But because bitwise operators have **lower precedence** than `==`, it's actually wrong! It should be `(c & (1 << k)) == 0`!

```cpp
// OJ: https://leetcode.com/problems/candy-crush/
// Author: github.com/lzl124631x
// Time: O((MN)^2)
// Space: O(1)
class Solution {
private:
    int M, N;
    int dirs[2][2] = {{ 1, 0 }, { 0, 1 }};
    int crushable(vector<vector<int>> &board, int i, int j) {
        if (!board[i][j]) return 0;
        int ans = 0, val = abs(board[i][j]);
        for (int k = 0; k < 2; ++k) {
            auto dir = dirs[k];
            int x = i, y = j, cnt = 1;
            do {
                x += dir[0];
                y += dir[1];
                if (x >= M || y >= N || abs(board[x][y]) != val) break;
                ++cnt;
            } while (cnt < 3);
            if (cnt >= 3) ans |= (1 << k);
        }
        return ans;
    }
    void mark(vector<vector<int>> &board, int i, int j, int c) {
        int val = abs(board[i][j]);
        board[i][j] = -val;
        for (int k = 0; k < 2; ++k) {
            if ((c & (1 << k)) == 0) continue;
            int x = i, y = j;
            auto dir = dirs[k];
            do {
                x += dir[0];
                y += dir[1];
                if (x >= M || y >= N || abs(board[x][y]) != val) break;
                board[x][y] = -val;
            } while (true);
        }
    }
    void drop(vector<vector<int>> &board) {
        for (int j = 0; j < N; ++j) {
            int k = M - 1;
            for (int i = M - 1; i >= 0; --i) {
                if (board[i][j] <= 0) continue;
                board[k--][j] = board[i][j];
            }
            while (k >= 0) board[k--][j] = 0;
        }
    }
    bool crush(vector<vector<int>> &board) {
        bool found = false;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int c = crushable(board, i, j);
                if (!c) continue;
                mark(board, i, j, c);
                found = true;
            }
        }
        if (!found) return false;
        drop(board);
        return true;
    }
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        M = board.size(), N = board[0].size();
        while (crush(board));
        return board;
    }
};
```