# [688. Knight Probability in Chessboard (Medium)](https://leetcode.com/problems/knight-probability-in-chessboard/)

<p>On an <code>N</code>x<code>N</code> chessboard, a knight starts at the <code>r</code>-th row and <code>c</code>-th column and attempts to make exactly <code>K</code> moves. The rows and columns are 0 indexed, so the top-left square is <code>(0, 0)</code>, and the bottom-right square is <code>(N-1, N-1)</code>.</p>

<p>A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.</p>

<p>&nbsp;</p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/knight.png" style="width: 200px; height: 200px;"></p>

<p>&nbsp;</p>

<p>Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.</p>

<p>The knight continues moving until it has made exactly <code>K</code> moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.</p>

<p>&nbsp;</p>

<p><b>Example:</b></p>

<pre><b>Input:</b> 3, 2, 0, 0
<b>Output:</b> 0.0625
<b>Explanation:</b> There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ul>
	<li><code>N</code> will be between 1 and 25.</li>
	<li><code>K</code> will be between 0 and 100.</li>
	<li>The knight always initially starts on the board.</li>
</ul>


**Companies**:  
[Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Out of Boundary Paths (Medium)](https://leetcode.com/problems/out-of-boundary-paths/)

## Solution 1. DP

Denote the result as `F(N, K, r, c)`.

For `K = 0`:
```
F(N, K, r, c) = 1     If (r, c) is on board.
                0     otherwise.
```

For `K > 0`:
```
F(N, K, r, c) = Sum(F(N, K - 1, x, y)) / 8      where (x, y) are all the points reachable from (r, c)
```

We can use this recurrence relation to solve the problem.

```cpp
// OJ: https://leetcode.com/problems/knight-probability-in-chessboard/
// Author: github.com/lzl124631x
// Time: O(KN^2)
// Space: O(N^2)
class Solution {
private:
    int dirs[8][2] = {{-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}};
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> m(N, vector<double>(N, 1));
        while (K-- > 0) {
            vector<vector<double>> next(N, vector<double>(N, 0));
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    for (auto &dir : dirs) {
                        int x = i + dir[0], y = j + dir[1];
                        if (x < 0 || x >= N || y < 0 || y >= N) continue;
                        next[i][j] += m[x][y];
                    }
                    next[i][j] /= 8;
                }
            }
            m = next;
        }
        return m[r][c];
    }
};
```