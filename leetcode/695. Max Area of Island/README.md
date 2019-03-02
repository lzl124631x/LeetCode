# [695. Max Area of Island (Medium)](https://leetcode.com/problems/max-area-of-island/)

<p>Given a non-empty 2D array <code>grid</code> of 0's and 1's, an <b>island</b> is a group of <code>1</code>'s (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.</p>

<p>Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)</p>

<p><b>Example 1:</b></p>

<pre>[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,<b>1</b>,0,<b>1</b>,0,0],
 [0,1,0,0,1,1,0,0,<b>1</b>,<b>1</b>,<b>1</b>,0,0],
 [0,0,0,0,0,0,0,0,0,0,<b>1</b>,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
</pre>
Given the above grid, return <code>6</code>. Note the answer is not 11, because the island must be connected 4-directionally.

<p><b>Example 2:</b></p>

<pre>[[0,0,0,0,0,0,0,0]]</pre>
Given the above grid, return <code>0</code>.

<p><b>Note:</b> The length of each dimension in the given <code>grid</code> does not exceed 50.</p>


**Companies**:  
[Google](https://leetcode.com/company/google), [Affirm](https://leetcode.com/company/affirm), [Amazon](https://leetcode.com/company/amazon), [Qualtrics](https://leetcode.com/company/qualtrics), [Facebook](https://leetcode.com/company/facebook), [Uber](https://leetcode.com/company/uber), [DoorDash](https://leetcode.com/company/doordash)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Number of Islands (Medium)](https://leetcode.com/problems/number-of-islands/)
* [Island Perimeter (Easy)](https://leetcode.com/problems/island-perimeter/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/max-area-of-island/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
private:
    int M, N;
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int eraseIsland(vector<vector<int>>& grid, int x, int y) {
        grid[x][y] = 0;
        int size = 1;
        for (auto &dir : dirs) {
            int i = x + dir[0], j = y + dir[1];
            if (i < 0 || i >= M || j < 0 || j >= N || !grid[i][j]) continue;
            size += eraseIsland(grid, i, j);
        }
        return size;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        M = grid.size();
        N = grid[0].size();
        int ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!grid[i][j]) continue;
                ans = max(ans, eraseIsland(grid, i, j));
            }
        }
        return ans;
    }
};
```