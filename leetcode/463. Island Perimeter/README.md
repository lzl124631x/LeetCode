# [463. Island Perimeter (Easy)](https://leetcode.com/problems/island-perimeter/)

<p>You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.</p>

<p>Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).</p>

<p>The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.</p>

<p>&nbsp;</p>

<p><b>Example:</b></p>

<pre><strong>Input:</strong>
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

<strong>Output:</strong> 16

<strong>Explanation:</strong> The perimeter is the 16 yellow stripes in the image below:

<img src="https://assets.leetcode.com/uploads/2018/10/12/island.png" style="width: 221px; height: 213px;">
</pre>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [Max Area of Island (Medium)](https://leetcode.com/problems/max-area-of-island/)
* [Flood Fill (Easy)](https://leetcode.com/problems/flood-fill/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/island-perimeter/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int M = grid.size(), N = grid[0].size();
        int peri = 0;
        for (int i = 0; i < M; ++i) {
            auto row = grid[i];
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) continue;
                if (i - 1 < 0 || grid[i - 1][j] == 0) ++peri;
                if (j - 1 < 0 || grid[i][j - 1] == 0) ++peri;
                if (i + 1 >= M || grid[i + 1][j] == 0) ++peri;
                if (j + 1 >= N || grid[i][j + 1] == 0) ++peri;
            }
        }
        return peri;
    }
};
```