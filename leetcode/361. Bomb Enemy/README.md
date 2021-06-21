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

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/bomb-enemy/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& G) {
        int M = G.size(), N = G[0].size(), ans = 0;
        vector<vector<int>> top(M, vector<int>(N)), left(M, vector<int>(N)), right(M, vector<int>(N)), bottom(M, vector<int>(N));
        for (int j = 0; j < N; ++j) {
            int cnt = 0;
            for (int i = 0; i < M; ++i) {
                if (G[i][j] == 'E') ++cnt;
                else if (G[i][j] == 'W') cnt = 0;
                top[i][j] = cnt;
            }
        }
        for (int i = 0; i < M; ++i) {
            int cnt = 0;
            for (int j = 0; j < N; ++j) {
                if (G[i][j] == 'E') ++cnt;
                else if (G[i][j] == 'W') cnt = 0;
                left[i][j] = cnt;
            }
        }
        for (int j = 0; j < N; ++j) {
            int cnt = 0;
            for (int i = M - 1; i >= 0; --i) {
                if (G[i][j] == 'E') ++cnt;
                else if (G[i][j] == 'W') cnt = 0;
                bottom[i][j] = cnt;
            }
        }
        for (int i = 0; i < M; ++i) {
            int cnt = 0;
            for (int j = N - 1; j >= 0; --j) {
                if (G[i][j] == 'E') ++cnt;
                else if (G[i][j] == 'W') cnt = 0;
                right[i][j] = cnt;
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (G[i][j] != '0') continue;
                ans = max(ans, top[i][j] + left[i][j] + bottom[i][j] + right[i][j]);
            }
        }
        return ans;
    }
};
```

## Solution 3. DP

```cpp
// OJ: https://leetcode.com/problems/bomb-enemy/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
// Ref: https://leetcode.com/problems/bomb-enemy/solution/
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& G) {
        int M = G.size(), N = G[0].size(), row = 0, ans = 0;
        vector<int> col(N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (j == 0 || G[i][j - 1] == 'W') {
                    row = 0;
                    for (int k = j; k < N && G[i][k] != 'W'; ++k) {
                        row += G[i][k] == 'E';
                    }
                }
                if (i == 0 || G[i - 1][j] == 'W') {
                    col[j] = 0;
                    for (int k = i; k < M && G[k][j] != 'W'; ++k) {
                        col[j] += G[k][j] == 'E';
                    }
                }
                if (G[i][j] == '0') ans = max(ans, row + col[j]);
            }
        }
        return ans;
    }
};
```