# [2850. Minimum Moves to Spread Stones Over Grid (Medium)](https://leetcode.com/problems/minimum-moves-to-spread-stones-over-grid)

<p>You are given a <strong>0-indexed</strong> 2D integer matrix <code>grid</code> of size <code>3 * 3</code>, representing the number of stones in each cell. The grid contains exactly <code>9</code> stones, and there can be <strong>multiple</strong> stones in a single cell.</p>

<p>In one move, you can move a single stone from its current cell to any other cell if the two cells share a side.</p>

<p>Return <em>the <strong>minimum number of moves</strong> required to place one stone in each cell</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/08/23/example1-3.svg" style="width: 401px; height: 281px;" />
<pre>
<strong>Input:</strong> grid = [[1,1,0],[1,1,1],[1,2,1]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> One possible sequence of moves to place one stone in each cell is: 
1- Move one stone from cell (2,1) to cell (2,2).
2- Move one stone from cell (2,2) to cell (1,2).
3- Move one stone from cell (1,2) to cell (0,2).
In total, it takes 3 moves to place one stone in each cell of the grid.
It can be shown that 3 is the minimum number of moves required to place one stone in each cell.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/08/23/example2-2.svg" style="width: 401px; height: 281px;" />
<pre>
<strong>Input:</strong> grid = [[1,3,0],[1,0,0],[1,0,3]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> One possible sequence of moves to place one stone in each cell is:
1- Move one stone from cell (0,1) to cell (0,2).
2- Move one stone from cell (0,1) to cell (1,1).
3- Move one stone from cell (2,2) to cell (1,2).
4- Move one stone from cell (2,2) to cell (2,1).
In total, it takes 4 moves to place one stone in each cell of the grid.
It can be shown that 4 is the minimum number of moves required to place one stone in each cell.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>grid.length == grid[i].length == 3</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 9</code></li>
	<li>Sum of <code>grid</code> is equal to <code>9</code>.</li>
</ul>


**Companies**:
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search), [Matrix](https://leetcode.com/tag/matrix)

**Similar Questions**:
* [Minimum Number of Operations to Move All Balls to Each Box (Medium)](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box)

**Hints**:
* There are at most <code>4</code> cells with more than one stone.
* Let <code>a</code> be the number of cells containing more than one stone, and <code>b</code> be the number of cells containing no stones. <code></code>. <code>b^a ≤ 6561</code>. Use this fact to come up with a bruteforce.
* For all empty cells, bruteforce over all possible cells from which a stone can come. Note that a stone will always come from a cell containing at least 2 stones.

## Solution 1. BFS

* Encode the board state as a `int` number.
* BFS to find the shortest path to `111111111`.

```cpp
// OJ: https://leetcode.com/problems/minimum-moves-to-spread-stones-over-grid
// Author: github.com/lzl124631x
// Time: O(9^9)
// Space: O(9^9)
class Solution {
    int encode(vector<vector<int>> &A) {
        int ans = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                ans = ans * 10 + A[i][j];
            }
        }
        return ans;
    }
    vector<vector<int>> decode(int state) {
        vector<vector<int>> ans(3, vector<int>(3));
        for (int i = 2; i >= 0; --i) {
            for (int j = 2; j >= 0; --j) {
                ans[i][j] = state % 10;
                state /= 10;
            }
        }
        return ans;
    }
public:
    int minimumMoves(vector<vector<int>>& A) {
        int init = encode(A), goal = 111111111, step = 0, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        unordered_set<int> seen{init};
        queue<int> q{{init}};
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                int state = q.front();
                q.pop();
                if (state == goal) return step;
                auto v = decode(state);
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if (v[i][j] <= 1) continue;
                        for (auto &[dx, dy] : dirs) {
                            int x = i + dx, y = j + dy;
                            if (x < 0 || x >= 3 || y < 0 || y >= 3) continue;
                            v[x][y]++;
                            v[i][j]--;
                            int next = encode(v);
                            if (seen.count(next) == 0) {
                                seen.insert(next);
                                q.push(next);
                            }
                            v[i][j]++;
                            v[x][y]--;
                        }
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};
```

## Solution 2. DFS

* Use DFS to traverse all the possible moves.
* In each DFS call, find all the possible starting point (`A[i][j] > 1`) and ending point (`A[i][j] == 0`).
* For a pair of start point `(i,j)` and ending point `(x,y)`, we need `abs(i-x) + abs(j-y)` moves. Assume the board after move is `B`, we try to update the answer with `abs(i-x) + abs(j-y) + minimumMoves(B)`.
* If no pairs of starting/ending points found, we've reached goal state. Return `0`.

```cpp
// OJ: https://leetcode.com/problems/minimum-moves-to-spread-stones-over-grid
// Author: github.com/lzl124631x
// Time: O(9^9)
// Space: O(9^9)
class Solution {
public:
    int minimumMoves(vector<vector<int>>& A) {
        int ans = INT_MAX;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (A[i][j] <= 1) continue;
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        if (A[x][y]) continue;
                        A[i][j]--;
                        A[x][y]++;
                        ans = min(ans, abs(i - x) + abs(j - y) + minimumMoves(A));
                        A[x][y]--;
                        A[i][j]++;
                    }
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
```