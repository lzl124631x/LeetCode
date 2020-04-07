# [289. Game of Life (Medium)](https://leetcode.com/problems/game-of-life/)

<p>According to the <a href="https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life" target="_blank">Wikipedia's article</a>: "The <b>Game of Life</b>, also known simply as <b>Life</b>, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."</p>

<p>Given a <i>board</i> with <i>m</i> by <i>n</i> cells, each cell has an initial state <i>live</i> (1) or <i>dead</i> (0). Each cell interacts with its <a href="https://en.wikipedia.org/wiki/Moore_neighborhood" target="_blank">eight neighbors</a> (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):</p>

<ol>
	<li>Any live cell with fewer than two live neighbors dies, as if caused by under-population.</li>
	<li>Any live cell with two or three live neighbors lives on to the next generation.</li>
	<li>Any live cell with more than three live neighbors dies, as if by over-population..</li>
	<li>Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.</li>
</ol>

<p>Write a function to compute the next state (after one update) of the board given its current state.&nbsp;<span>The next state is created by applying the above rules simultaneously to every cell in the current state, where&nbsp;births and deaths occur simultaneously.</span></p>

<p><strong>Example:</strong></p>

<pre><strong>Input: 
</strong><span id="example-input-1-1">[
&nbsp; [0,1,0],
&nbsp; [0,0,1],
&nbsp; [1,1,1],
&nbsp; [0,0,0]
]</span>
<strong>Output: 
</strong><span id="example-output-1">[
&nbsp; [0,0,0],
&nbsp; [1,0,1],
&nbsp; [0,1,1],
&nbsp; [0,1,0]
]</span>
</pre>

<p><b>Follow up</b>:</p>

<ol>
	<li>Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.</li>
	<li>In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?</li>
</ol>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Set Matrix Zeroes (Medium)](https://leetcode.com/problems/set-matrix-zeroes/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/game-of-life/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
    int M, N;
    inline bool alive(vector<vector<int>> &A, int x, int y) {
        return x >= 0 && y >= 0 && x < M && y < N && A[x][y] & 1;
    }
public:
    void gameOfLife(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return;
        int dx[8] = {-1,-1,0,1,1,1,0,-1}, dy[8] = {0,1,1,1,0,-1,-1,-1};
        M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) cnt += alive(A, i + dx[k], j + dy[k]);
                if ((A[i][j] && cnt == 2) || cnt == 3) A[i][j] |= 2;
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                A[i][j] >>= 1;
            }
        }
    }
};
```