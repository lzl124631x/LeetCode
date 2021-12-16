# [2056. Number of Valid Move Combinations On Chessboard (Hard)](https://leetcode.com/problems/number-of-valid-move-combinations-on-chessboard/)

<p>There is an <code>8 x 8</code> chessboard containing <code>n</code> pieces (rooks, queens, or bishops). You are given a string array <code>pieces</code> of length <code>n</code>, where <code>pieces[i]</code> describes the type (rook, queen, or bishop) of the <code>i<sup>th</sup></code> piece. In addition, you are given a 2D integer array <code>positions</code> also of length <code>n</code>, where <code>positions[i] = [r<sub>i</sub>, c<sub>i</sub>]</code> indicates that the <code>i<sup>th</sup></code> piece is currently at the <strong>1-based</strong> coordinate <code>(r<sub>i</sub>, c<sub>i</sub>)</code> on the chessboard.</p>

<p>When making a <strong>move</strong> for a piece, you choose a <strong>destination</strong> square that the piece will travel toward and stop on.</p>

<ul>
	<li>A rook can only travel <strong>horizontally or vertically</strong> from <code>(r, c)</code> to the direction of <code>(r+1, c)</code>, <code>(r-1, c)</code>, <code>(r, c+1)</code>, or <code>(r, c-1)</code>.</li>
	<li>A queen can only travel <strong>horizontally, vertically, or diagonally</strong> from <code>(r, c)</code> to the direction of <code>(r+1, c)</code>, <code>(r-1, c)</code>, <code>(r, c+1)</code>, <code>(r, c-1)</code>, <code>(r+1, c+1)</code>, <code>(r+1, c-1)</code>, <code>(r-1, c+1)</code>, <code>(r-1, c-1)</code>.</li>
	<li>A bishop can only travel <strong>diagonally</strong> from <code>(r, c)</code> to the direction of <code>(r+1, c+1)</code>, <code>(r+1, c-1)</code>, <code>(r-1, c+1)</code>, <code>(r-1, c-1)</code>.</li>
</ul>

<p>You must make a <strong>move</strong> for every piece on the board simultaneously. A <strong>move combination</strong> consists of all the <strong>moves</strong> performed on all the given pieces. Every second, each piece will instantaneously travel <strong>one square</strong> towards their destination if they are not already at it. All pieces start traveling at the <code>0<sup>th</sup></code> second. A move combination is <strong>invalid</strong> if, at a given time, <strong>two or more</strong> pieces occupy the same square.</p>

<p>Return <em>the number of <strong>valid</strong> move combinations</em>​​​​​.</p>

<p><strong>Notes:</strong></p>

<ul>
	<li><strong>No two pieces</strong> will start in the<strong> same</strong> square.</li>
	<li>You may choose the square a piece is already on as its <strong>destination</strong>.</li>
	<li>If two pieces are <strong>directly adjacent</strong> to each other, it is valid for them to <strong>move past each other</strong> and swap positions in one second.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/23/a1.png" style="width: 215px; height: 215px;">
<pre><strong>Input:</strong> pieces = ["rook"], positions = [[1,1]]
<strong>Output:</strong> 15
<strong>Explanation:</strong> The image above shows the possible squares the piece can move to.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/23/a2.png" style="width: 215px; height: 215px;">
<pre><strong>Input:</strong> pieces = ["queen"], positions = [[1,1]]
<strong>Output:</strong> 22
<strong>Explanation:</strong> The image above shows the possible squares the piece can move to.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/23/a3.png" style="width: 214px; height: 215px;">
<pre><strong>Input:</strong> pieces = ["bishop"], positions = [[4,3]]
<strong>Output:</strong> 12
<strong>Explanation:</strong> The image above shows the possible squares the piece can move to.
</pre>

<p><strong>Example 4:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/23/a4.png" style="width: 216px; height: 219px;">
<pre><strong>Input:</strong> pieces = ["rook","rook"], positions = [[1,1],[8,8]]
<strong>Output:</strong> 223
<strong>Explanation:</strong> There are 15 moves for each rook which results in 15 * 15 = 225 move combinations.
However, there are two invalid move combinations:
- Move both rooks to (8, 1), where they collide.
- Move both rooks to (1, 8), where they collide.
Thus there are 225 - 2 = 223 valid move combinations.
Note that there are two valid move combinations that would result in one rook at (1, 8) and the other at (8, 1).
Even though the board state is the same, these two move combinations are considered different since the moves themselves are different.
</pre>

<p><strong>Example 5:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/23/a5.png" style="width: 214px; height: 213px;">
<pre><strong>Input:</strong> pieces = ["queen","bishop"], positions = [[5,7],[3,4]]
<strong>Output:</strong> 281
<strong>Explanation:</strong> There are 12 * 24 = 288 move combinations.
However, there are several invalid move combinations:
- If the queen stops at (6, 7), it blocks the bishop from moving to (6, 7) or (7, 8).
- If the queen stops at (5, 6), it blocks the bishop from moving to (5, 6), (6, 7), or (7, 8).
- If the bishop stops at (5, 2), it blocks the queen from moving to (5, 2) or (5, 1).
Of the 288 move combinations, 281 are valid.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == pieces.length </code></li>
	<li><code>n == positions.length</code></li>
	<li><code>1 &lt;= n &lt;= 4</code></li>
	<li><code>pieces</code>&nbsp;only contains the strings&nbsp;<code>"rook"</code>,&nbsp;<code>"queen"</code>, and&nbsp;<code>"bishop"</code>.</li>
	<li>There will be at most one queen on the chessboard.</li>
	<li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 8</code></li>
	<li>Each&nbsp;<code>positions[i]</code>&nbsp;is distinct.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/), [Simulation](https://leetcode.com/tag/simulation/)

## Solution 1. Backtracking

Time Complexity:

For each DFS level, the piece can most move to `4 * 7 + 1 = 29` different positions. There are at most 4 levels. So there are `O(29^4)` different combination of positions.

For each combination, the `valid` function at most check `1 + 2 + 3 = 6` pairs of pieces, and each pair takes takes at most `7` steps. So the `valid` function takes `O(6 * 7)` times for each combination.

So, overall, this solution takes `O(29^4 * 6 * 7)` time.

This number looks large but since lots of combinations are skipped, it can get accepted.

```cpp
// OJ: https://leetcode.com/problems/number-of-valid-move-combinations-on-chessboard/
// Author: github.com/lzl124631x
// Time: O(29^4 * 6 * 7)
// Space: O(64)
class Solution {
public:
    int countCombinations(vector<string>& pc, vector<vector<int>>& pos) {
        int N = pc.size();
        vector<array<int, 2>> dirs[3] = {{{0,1},{0,-1},{1,0},{-1,0}}, {{1,1},{1,-1},{-1,1},{-1,-1}}, {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}}}, goal;
        bool used[8][8] = {};
        auto getDelta = [](int from, int to) { return from < to ? 1 : (from > to ? -1 : 0); };
        auto valid = [&]() {
            int last = goal.size() - 1;
            for (int i = last - 1; i >= 0; --i) {
                int x1 = pos[last][0] - 1, y1 = pos[last][1] - 1, x1g = goal[last][0], y1g = goal[last][1], dx1 = getDelta(x1, x1g), dy1 = getDelta(y1, y1g);
                int x2 = pos[i][0] - 1, y2 = pos[i][1] - 1, x2g = goal[i][0], y2g = goal[i][1], dx2 = getDelta(x2, x2g), dy2 = getDelta(y2, y2g);
                while (x1 != x1g || y1 != y1g || x2 != x2g || y2 != y2g) {
                    if (x1 != x1g) x1 += dx1;
                    if (y1 != y1g) y1 += dy1;
                    if (x2 != x2g) x2 += dx2;
                    if (y2 != y2g) y2 += dy2;
                    if (x1 == x2 && y1 == y2) return false;
                }
            }
            return true;
        };
        function<int(int)> dfs = [&](int i) {
            if (i == N) return 1;
            int x = pos[i][0] - 1, y = pos[i][1] - 1, dir = pc[i] == "rook" ? 0 : (pc[i] == "bishop" ? 1 : 2), ans = 0;
            if (!used[x][y]) {
                used[x][y] = true;
                goal.push_back({x, y});
                if (valid()) ans += dfs(i + 1);
                goal.pop_back();
                used[x][y] = false;
            }
            for (auto &[dx, dy] : dirs[dir]) {
                int a = x, b = y;
                do {
                    a += dx;
                    b += dy;
                    if (a < 0 || a > 7 || b < 0 || b > 7) break;
                    if (used[a][b]) continue;
                    used[a][b] = true;
                    goal.push_back({a, b});
                    if (valid()) ans += dfs(i + 1);
                    goal.pop_back();
                    used[a][b] = false;
                } while (true);
            }
            return ans;
        };
        return dfs(0);
    }
};
```