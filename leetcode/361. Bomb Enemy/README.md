# [361. Bomb Enemy (Medium)](https://leetcode.com/problems/bomb-enemy/)

<p>Given a 2D grid, each cell is either a wall <code>'W'</code>, an enemy <code>'E'</code> or empty <code>'0'</code> (the number zero), return the maximum enemies you can kill using one bomb.<br>
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.<br>
<strong>Note: </strong>You can only put the bomb at an empty cell.</p>

<p><strong>Example:</strong></p>

<div>
<pre><strong>Input: </strong><span id="example-input-1-1">[["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]</span>
<strong>Output: </strong><span id="example-output-1">3 
<strong>Explanation: </strong></span>For the given grid,

0 E 0 0 
E 0 W E 
0 E 0 0

Placing a bomb at (1,1) kills 3 enemies.
</pre>
</div>

**Companies**:  
[Google](https://leetcode.com/company/google), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/bomb-enemy/
// Author: github.com/lzl124631x
// Time: O(MN(M+N))
// Space: O(1)
class Solution {
private:
    int M, N;
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int count(vector<vector<char>>& grid, int x, int y, int dir[2]) {
        int ans = 0;
        while (true) {
            x += dir[0];
            y += dir[1];
            if (x < 0 || x >= M || y < 0 || y >= N || grid[x][y] == 'W') break;
            if (grid[x][y] == 'E') ++ans;
        }
        return ans;
    }
    int count(vector<vector<char>>& grid, int x, int y) {
        int ans = 0;
        for (auto &dir : dirs) ans += count(grid, x, y, dir);
        return ans;
    }
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        M = grid.size();
        N = grid[0].size();
        int ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] != '0') continue;
                ans = max(ans, count(grid, i, j));
            }
        }
        return ans;
    }
};
```